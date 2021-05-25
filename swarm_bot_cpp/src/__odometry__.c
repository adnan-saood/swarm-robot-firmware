/*
 * __odometry__.c
 *
 * Created: 5/19/2021 9:44:12 AM
 *  Author: adnan
 */ 

#include <__odometry__.h>

//
ISR(INT0_vect)
{
	if(_enca_count=0)
	{
		_prev_tick_timeA = _micros();
	}
	else
	{
		_tick_timeA = _micros() - _prev_tick_timeA;
	}
	if(__read_secodary_enc(ENCA2))
	{
		_enca_count++;
	}
	else
	{
		_enca_count--;
	}
}

ISR(INT1_vect)
{
	
	if(_enca_count=0)
	{
		_prev_tick_timeB = _micros();
	}
	else
	{
		_tick_timeB = _micros() - _prev_tick_timeB;
	}
	
	if(__read_secodary_enc(ENCB2))
	{
		_encb_count++;
	}
	else
	{
		_encb_count--;
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
	return (__ENC_TICK_THETA / _tick_timeA);
}
float _omega_from_encB(void)
{
	return (__ENC_TICK_THETA / _tick_timeB);
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
		_omega_pmA = _omega_from_encA();
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


ISR(TIMER0_COMPA_vect)
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