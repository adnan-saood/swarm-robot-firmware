/*
 * __timer0__.c
 *
 * Created: 5/19/2021 9:04:08 AM
 *  Author: adnan
 */ 

#include <__timer0__.h>

void _timer0_init(void)
{
	TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << COM0B1) | (1 << COM0B0);
	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	
	TCCR0B |=(0 << CS02) | (0 << CS01) | (1 << CS00);
}
void _timer0_enable_ovf(void)
{
	TIMSK0 |= (1 << TOIE0);
}
void _timer0_init_prescaler(uint8_t prescaler)
{
	TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << COM0B1) | (1 << COM0B0);
	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	
	
	int __CS__ = 0;
	
	switch (prescaler)
	{
		
		case 1:
		__CS__ = 1;break;
		case 8:
		__CS__ = 2;break;
		case 64:
		__CS__ = 3;break;
		case 256:
		__CS__ = 4;break;
		case 1024:
		__CS__ = 5;break;
		default:
		TCCR0B &= 0b11111000 ; __CS__ = 0;break;
		
	}
	
	TCCR0B |= __CS__;
}
void _timer0_stop_and_clear(void)
{
	TCCR0B &= 0b11111000;
	TCNT0 = 0;
}
void _timer0_stop_and_save(void)
{
	_tcnt0_mem = TCNT0;
	TCCR0B &= 0b11111000;
}

uint8_t _is_tmr0_enabled()
{
	return (TCCR0B | 0b111);
}
