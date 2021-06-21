/*
 * __timer2__.c
 *
 * Created: 5/20/2021 12:04:46 AM
 *  Author: adnan
 */ 

#include <__timer2__.h>

void _timer2_init(void)
{
	TCCR2A = 0;
	OCR2A = 128;
	TCCR2B |=(1 << CS22) | (1 << CS21) | (1 << CS20);
	TIMSK2 |= (0 << OCIE2A) | (0 << TOIE2);
}
