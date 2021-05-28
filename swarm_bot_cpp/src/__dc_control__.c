/*
 * __dc_control__.c
 *
 * Created: 5/26/2021 9:17:59 PM
 *  Author: adnan
 */ 



#include <__dc_control__.h>

float _setpoint_a = 0;

int _set_speed(uint8_t motor, int value)
{
	if(value == 0)
	{
		_break_motor(motor);
		return value;
	}
	if(value < 0)
	{
		if (motor == MA)
		{
			_set_pwm_0A(-1*value);
			_set_pwm_1A(0);
		} 
		else if (motor == MB)
		{
			_set_pwm_0B(0);
			_set_pwm_1B(-1*value);
		}
	}
	else if(value > 0)
	{
		if (motor == MA)
		{
			_set_pwm_0A(0);
			_set_pwm_1A(value);
		}
		else if (motor == MB)
		{
			_set_pwm_0B(value);
			_set_pwm_1B(0);
		}
	}
	return value;
}

void _break_motor(uint8_t motor)
{
	if (motor == MA)
	{
		_set_pwm_0A(0);
		_set_pwm_1A(0);
	}
	else if (motor == MB)
	{
		_set_pwm_0B(0);
		_set_pwm_1B(0);
	}
}

void _set_setpoint(float value, uint8_t motor)
{
	if (motor == MA)
	{
		_setpoint_a = value;
	} 
	else if (motor == MB)
	{
	}
}