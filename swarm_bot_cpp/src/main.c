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
	_init_dc_control();
	sei();
	uint16_t t = _millis0();
	while (1)
	{
		_update_controller(MA);
		if(_millis0() - t > 500)
		{
			printf("OCR0A : %d, sens : %1.3f \n", 255-OCR1AH, _omega_from_encA());
			t = _millis0();
		}
		_delay_ms(25);
	}
//	_set_speed(MA,240);
//	uint16_t t = _millis0();
//	while(_millis0() - t < 4000)
//	{
//		printf("240 : %1.3f : %d \n", _omega_from_encA(), _ticksA());
//		_delay_ms(250);
//	}
	return 0;
}

