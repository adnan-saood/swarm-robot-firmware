
#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <__adc__.h>
#include "__usart__.h"
#include "__timer1__.h"
#include <__odometry__.h>

#define F_CPU 1000000

#include <util/delay.h>


int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
	
	DDRB = 0xFF;
	DDRD = 0x00;
	while (1)
	{
	    int temp1 = _omega_from_encA();
		float temp = (_omega_from_encA() - temp1) * 1000;
		printf("%d.%d \n", (int) _omega_from_encA(), (int) temp);
		//printf("%lu\n", _micros0());
	}
	/* Insert application code here, after the board has been initialized. */
}
