
#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <__adc__.h>
#include "__usart__.h"
#include "__timer1__.h"

#define F_CPU 16000000

#include <util/delay.h>


int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
	
	
	
	while (1)
	{
	}
	/* Insert application code here, after the board has been initialized. */
}
