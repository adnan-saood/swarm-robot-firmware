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
	while(1)
	{
		_move(FRWD);
		_delay_ms(2000);
		_move(LEFT);
		_delay_ms(1000);
	}
	return 0;
}

