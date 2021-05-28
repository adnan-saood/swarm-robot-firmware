/*
 * __dc_control__.c
 *
 * Created: 5/26/2021 9:17:59 PM
 *  Author: adnan
 */ 



#include <__dc_control__.h>

static struct PID_DATA pidData;


int16_t _ref(uint8_t motor)
{
	if(motor == MA)
	{
		return 20;
	}
	else if (motor == MB)
	{
		return 30;
	}
	return 0;
}

void _command(uint8_t motor, int16_t inputValue)
{
	_set_speed(motor,inputValue);
}

float _sens(uint8_t motor)
{
	if(motor == MA)
	{
		return (_omega_from_encA()*9.55);
	}
	else if (motor == MB)
	{
		
		return (_omega_from_encB()*9.55);
	}
	else
	{
		return -1;
	}
}

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

void _init_dc_control(void)
{
	pid_Init(K_P * SCALING_FACTOR, K_I * SCALING_FACTOR , K_D * SCALING_FACTOR , &pidData);
	sei();
}

int16_t _update_controller(uint8_t motor)
{
	int16_t ref, sen,u;
	ref = _ref(motor);
	sen =   (int16_t) _sens(motor);
	u = pid_Controller(ref,sen, &pidData);
	_command(motor, u);
	if (DEBUG_CONTROLLER)
	{
		printf("%d - %d - %d\n",ref, sen, u);
	}
	return u;
}

int16_t _dc_controller_loop(void)
{
	if(_controler_flag_A)
	{
		 _update_controller(MA);
		 _controler_flag_A = 0;
	}
	if(_controler_flag_B)
	{
		_update_controller(MB);
		_controler_flag_B = 0;
	}
	return 0;
}