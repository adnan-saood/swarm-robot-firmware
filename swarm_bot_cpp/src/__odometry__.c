 
#include <__odometry__.h>

// amount if time in a tick
volatile static uint64_t _tick_timeA = 0;
volatile static uint64_t _tick_timeB = 0;

//previous tick time in micros
volatile static uint64_t _prev_tick_timeA = 0;
volatile static uint64_t _prev_tick_timeB = 0;

volatile static float _omega_enc_a = 0.0f;


volatile static int32_t _enca_count = 0;
volatile static int32_t _encb_count = 0;

volatile static float _omega_enca_prev = 0.0f;


volatile static uint16_t _pmA_prev = -1;
volatile static uint16_t _pmA_current = 0;

volatile static uint16_t _pmB_prev = -1;
volatile static uint16_t _pmB_current = 0;

volatile static float _omega_pmA = 0.0f;
volatile static float _omega_pmB = 0.0f;

ISR(INT0_vect)
{
	__led_toggle(D4);
	if(_enca_count == 0)
	{
		_prev_tick_timeA = _micros0();
		_omega_enc_a = 0;
	}
	else
	{
		uint64_t t = _micros0();
		_tick_timeA = t - _prev_tick_timeA;
		_prev_tick_timeA = t;
		_omega_enc_a = (__ENC_TICK_THETA_FOR_OMEGA / (float)_tick_timeA);
	}
	_enca_count++;
}

ISR(INT1_vect)
{
	if(_encb_count == 0)
	{
		_prev_tick_timeB = _micros0();
	}
	else
	{
		uint64_t t = _micros0();
		_tick_timeB = t - _prev_tick_timeB;
		_prev_tick_timeB = t;
	}
		_encb_count++;

}

float _thetaA(void)
{
	return __ENC_TICK_THETA * _enca_count;
}
float _thetaB(void)
{
	return __ENC_TICK_THETA * _encb_count;
}

int32_t _ticksA()
{
	return _enca_count;
}
int32_t _ticksB()
{
	return _encb_count;
}

float _omega_from_encA(void)
{
	if(_omega_enc_a > 20)
	{
		 return _omega_enca_prev;
	}
	 else
	{
		_omega_enca_prev = _omega_enc_a;
		 return _omega_enc_a;
	}
	//return _tick_timeA;
}
float _omega_from_encB(void)
{
	return (__ENC_TICK_THETA_FOR_OMEGA / (float)_tick_timeB);
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
	if(_micros0() - _prev_tick_timeA > 100000)
	{
		_omega_enc_a = 0.0;
	}
}


ISR(TIMER2_COMPA_vect)
{
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