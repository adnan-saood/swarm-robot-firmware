 


#include <__dc_control__.h>

static struct PID_DATA pidDataA;
static struct PID_DATA pidDataB;

volatile static float _dc_ref_A = 0.0f;
volatile static float _dc_ref_B = 0.0f;

void _set_ref(uint8_t motor, float ref)
{
	if(motor == MA)
	{
		_dc_ref_A = ref;
	}
	if(motor == MB)
	{
		_dc_ref_B = ref;
	}
}
float _ref(uint8_t motor)
{
	if(motor == MA)
	{
		return _dc_ref_A;
	}
	else if (motor == MB)
	{
		return _dc_ref_B;
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
		return (_omega_from_encA());
	}
	else if (motor == MB)
	{
		
		return (_omega_from_encB());
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
			_set_pwm_0A(255);
			_set_pwm_1A(255);
		}
		else if (motor == MB)
		{
			_set_pwm_0B(255);
			_set_pwm_1B(255);
		}
	}
	else if(value > 0)
	{
		if (motor == MA)
		{
			_set_pwm_0A(255);
			_set_pwm_1A(255-value);
		}
		else if (motor == MB)
		{
			_set_pwm_0B(255-value);
			_set_pwm_1B(255);
		}
	}
	return value;
}


void _break_motor(uint8_t motor)
{
	if (motor == MA)
	{
		_set_pwm_0A(255);
		_set_pwm_1A(255);
	}
	else if (motor == MB)
	{
		_set_pwm_0B(255);
		_set_pwm_1B(255);
	}
}

void _init_dc_control(void)
{
	pid_Init(K_P * SCALING_FACTOR, K_I * SCALING_FACTOR , K_D * SCALING_FACTOR , &pidDataA);
	pid_Init(K_P * SCALING_FACTOR, K_I * SCALING_FACTOR , K_D * SCALING_FACTOR , &pidDataB);
	
	sei();
}

int16_t _update_controller(uint8_t motor)
{
	float ref, sen;
	float u;
	ref = _ref(motor);
	sen =    _sens(motor); // major bug here
	if(motor == MA)
	{
		u = pid_Controller(ref,sen, &pidDataA);
	}
	else if(motor == MB)
	{
		u = pid_Controller(ref,sen, &pidDataB);
	}
	_command(motor, (int)u);
	if (DEBUG_CONTROLLER)
	{
		printf("%1.2f - %1.2f - %1.2f\n",ref, sen, u);
	}
	return 0;
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