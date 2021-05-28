
#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <__adc__.h>
#include "__usart__.h"
#include "__timer1__.h"
#include <__odometry__.h>

#include <_pid_.h>
#define F_CPU 1000000
#include <util/delay.h>


int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	cli();
	board_init();
	DDRB = 0xFF;
	DDRD = 0b01100011;
	sei();
	while (1)
	{
		_dc_controller_loop();
	}
	return 0;
}





