#include <__swarm_wold__.h>

#include <__kinematics__.h>

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	cli();
	board_init();
	DDRB = 0xFF;
	DDRD = 0b01100010;
	
	struct _theta te;
	struct pos p;
	struct pos_dot _p;
	struct _i_pos _i_p;
	struct _omega w;
	te.left = 0;
	te.right = 0;
	w.wl = 0;
	w.wr = 0;
	uint16_t DT = 100;
	uint32_t t_prev = 0;
	sei();
	while (1)
	{
		_set_speed(MA, -40);
		_set_speed(MB, 40);
		_update_omega(&w);
		_i_p = _omega_to_intertial(&w);
		printf("(%f , ", _i_p.v);
		printf(" %f)\n", _i_p.w);
		_delay_ms(100);
		//_set_speed(MA, 80);
		//while(1)
		//{
		//	printf("+(%d,", (int)(_omega_from_encA()*57.29577));
		//	printf(" %d )\n",(int)( _omega_from_encB()*57.29577));
		//	_delay_ms(100);
		//	if(_ticksA() < 0)
		//	{
		//		break;
		//	}
		//}
	}
	return 0;
}

