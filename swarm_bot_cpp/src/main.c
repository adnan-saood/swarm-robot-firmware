#include <__swarm_wold__.h>

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	
	board_init();
	DDRB = 0xFF;
	DDRD = 0b01100011;
	//sei();
	while (1)
	{
		//int16_t = _omega_from_PMA();
		printf("%d\n", __read_btr__);
		
		//printf("%d\n", _millis1() - _millis0());
		//printf("%d\n", i);
	//	i++;
		_delay_ms(1000);
	}
	return 0;
}





