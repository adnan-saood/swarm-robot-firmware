 
#include <__odometry__.h>

// amount if time in a tick
volatile static uint64_t _tick_timeA = 0;
volatile static uint64_t _tick_timeB = 0;

//previous tick time in micros
volatile static uint64_t _prev_tick_timeA = 0;
volatile static uint64_t _prev_tick_timeB = 0;

volatile static float _omega_enc_a = 0.0f;
volatile static float _omega_enc_b = 0.0f;

volatile static int32_t _enca_count = 0;
volatile static int16_t _dira;
volatile static int32_t _encb_count = 0;
volatile static int16_t _dirb;

volatile static float _omega_enca_prev = 0.0f;
volatile static float _omega_encb_prev = 0.0f;


ISR(INT0_vect)
{
	//__led_toggle(D4);
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
	}

	_enca_count++;

}

ISR(INT1_vect)
{
	if(_encb_count == 0)
	{
		_prev_tick_timeB = _micros0();
		_omega_enc_b = 0;
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
	if(_micros0() - _prev_tick_timeA > 100000)
	{
		_omega_enc_a = 0.0;
		return _omega_enc_a;
	}
		_omega_enc_a = (__ENC_TICK_THETA_FOR_OMEGA / (float)_tick_timeA);
	if(_omega_enc_a > 10)
	{
		 return _omega_enca_prev;
	}
	else
	{
		_omega_enca_prev = _omega_enc_a;
		 return _dira * _omega_enc_a;
	}
	//return _tick_timeA;
}
float _omega_from_encB(void)
{
	if(_micros0() - _prev_tick_timeB > 100000)
	{
		_omega_enc_b = 0.0;
		return _omega_enc_b;
	}
	_omega_enc_b = (__ENC_TICK_THETA_FOR_OMEGA / (float)_tick_timeB);
	if(_omega_enc_b > 10)
	{
		return _omega_encb_prev;
	}
	else
	{
		_omega_encb_prev = _omega_enc_b;
		return _dirb * _omega_enc_b;
	}
	//return _tick_timeA;
}

ISR(TIMER2_OVF_vect)
{
// ewmmber to turn it on if you wanna use it
}

ISR(TIMER2_COMPA_vect)
{
	// ewmmber to turn it on if you wanna use it
}