#include <__swarm_wold__.h>

#include <__kinematics__.h>





void _command_L(int16_t val)
{
	_set_ref(MA,val);
	_set_ref(MB,val);
}

void _command_other(int16_t val)
{
	_set_speed(MA,val);
	_set_speed(MB,val);
}
int main (void)
{
	cli();
	board_init();
	sei();
	_init_dc_control();
	int i = 0;
	_set_ref(MA,6);
	_set_ref(MB,6);
	while(1)
	{
		i++;
		if(__read_sw(SW1))
		{
			_command_other(0);
			while(1)
			{
				if(~__read_sw(SW1))
				{
					break;
				}
			}
		}
		_dc_controller_loop();
		if(i == 10)
		{
			printf("%1.2f,%1.2f\n", _omega_from_encA(), _omega_from_encB());
			i = 0;
		}
		_delay_ms(100);
	}
	return 0;
}

