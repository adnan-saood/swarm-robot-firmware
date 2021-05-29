/*
 * __odometry__.c
 *
 * Created: 5/19/2021 9:44:12 AM
 *  Author: adnan
 */ 

#include <__odometry__.h>

// amount if time in a tick
volatile static uint64_t _tick_timeA = 0;
volatile static uint64_t _tick_timeB = 0;

//previous tick time in micros
volatile static uint64_t _prev_tick_timeA = 0;
volatile static uint64_t _prev_tick_timeB = 0;


volatile static uint64_t _enca_count = 0;
volatile static uint64_t _encb_count = 0;
volatile static int8_t _dir_a = 1;
volatile static int8_t _dir_b = 1;


volatile static uint16_t _pmA_prev = -1;
volatile static uint16_t _pmA_current = 0;

volatile static uint16_t _pmB_prev = -1;
volatile static uint16_t _pmB_current = 0;

volatile static float _omega_pmA = 0.0f;
volatile static float _omega_pmB = 0.0f;

ISR(INT0_vect)
{
	if(_enca_count == 0)
	{
		_prev_tick_timeA = _micros0();
	}
	else
	{
		uint64_t t = _micros0();
		_tick_timeA = t - _prev_tick_timeA;
		_prev_tick_timeA = t;
	}
	
	if(__read_secodary_enc(ENCA2))
	{
		_enca_count++;
		_dir_a=FORWARD;
	}
	else
	{
		_enca_count--;
		_dir_a=BACKWARD;
		
	}
	
}

ISR(INT1_vect)
{
	
	if(_encb_count==0)
	{
		_prev_tick_timeB = _micros0();
	}
	else
	{
		uint64_t t = _micros0();
		_tick_timeB = t - _prev_tick_timeB;
		_prev_tick_timeB = t;
	}
	
	if(__read_secodary_enc(ENCB2))
	{
		_encb_count++;
		_dir_b = FORWARD;
	}
	else
	{
		_encb_count--;
		_dir_b = BACKWARD;
	}
}

float _thetaA(void)
{
	return __ENC_TICK_THETA * _enca_count;
}
float _thetaB(void)
{
	return __ENC_TICK_THETA * _encb_count;
}

float _omega_from_encA(void)
{
	return _dir_a*(__ENC_TICK_THETA_FOR_OMEGA / (float)_tick_timeA);
	//return _tick_timeA;
}
float _omega_from_encB(void)
{
	return _dir_b*(__ENC_TICK_THETA_FOR_OMEGA / (float)_tick_timeB);
}

float _omega_from_PMA(void)
{
	return _omega_pmA;
}
float _omega_from_PMB(void)
{
	return _omega_pmB;
}

float _omega_comp_A(void)
{
	return _omega_from_PMA() * 0.3f + _omega_from_encA() * 0.7f;
}
float _omega_comp_B(void)
{
	return _omega_from_PMB() * 0.3f + _omega_from_encB() * 0.7f;
}

ISR(TIMER2_OVF_vect)
{
	uint16_t snap = __read_PM(PMA);
	if ( (snap < __PM_lower_bound) || (snap > __PM_upper_bound) )
	{
		_pmA_current = -1;
		// _omega_pmA = _omega_from_encA();
	}
	else
	{
		if ( _pmA_prev == -1 )
		{
			_omega_pmA = _omega_from_encA();
		}
		else
		{
			// make 5 successive reads
			uint16_t *reads = (uint16_t*) malloc(__PM_SAMPLE_COUNT * sizeof(uint16_t));
	
			for (uint8_t i = 0 ; i < __PM_SAMPLE_COUNT ; i ++)
			{
				reads[i] = __read_PM(PMA);
			}
			// Sort outcome
			_insertion_sort(reads, __PM_SAMPLE_COUNT);
			_pmA_current = reads[(__PM_SAMPLE_COUNT >> 1)];
			_omega_pmA = __PM_SLOPE * (float)(_pmA_current - _pmA_prev);
		}
	}
	_pmA_prev = _pmA_current;
}


ISR(TIMER2_COMPA_vect)
{
	uint16_t snap = __read_PM(PMB);
	if ( (snap < __PM_lower_bound) || (snap > __PM_upper_bound) )
	{
		_pmB_current = -1;
		_omega_pmB = _omega_from_encA();
	}
	else
	{
		if ( _pmA_prev == -1 )
		{
			_omega_pmB = _omega_from_encB();
		}
		else
		{
			// make 5 successive reads
			uint16_t *reads = (uint16_t*) malloc(__PM_SAMPLE_COUNT * sizeof(uint16_t));
			
			for (uint8_t i = 0 ; i < __PM_SAMPLE_COUNT ; i ++)
			{
				reads[i] = __read_PM(PMB);
			}
			// Sort outcome
			_insertion_sort(reads, __PM_SAMPLE_COUNT);
			_pmB_current = reads[(__PM_SAMPLE_COUNT >> 1)];
			_omega_pmB = __PM_SLOPE * (float)(_pmB_current - _pmB_prev);
		}
	}
	_pmB_prev = _pmB_current;
}
void _insertion_sort(uint16_t arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}