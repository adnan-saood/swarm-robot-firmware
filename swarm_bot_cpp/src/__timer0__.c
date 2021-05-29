/*
 * __timer0__.c
 *
 * Created: 5/19/2021 9:04:08 AM
 *  Author: adnan
 */ 

#include <__timer0__.h>

uint64_t _timer0_ovf_cnt = 0;



void _timer0_init(void)
{
	TCCR0A |= (1 << COM0A1) | (0 << COM0A0) | (1 << COM0B1) | (0 << COM0B0);
	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	
	TCCR0B |=(1 << CS02) | (0 << CS01) | (0 << CS00);
	TIMSK0 |= (1 << TOIE0);
	sei();
}

void _timer0_init_prescaler(uint16_t prescaler)
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
	TIMSK0 |= (1 << TOIE0);
}

unsigned long _micros0()
{
	 
	if ((TIFR0 & (1 << TOV0)) && (TCNT0 < 255))
	{
		_timer0_ovf_cnt++;
	}
	return _TICK_US_0*((_timer0_ovf_cnt << 8) + TCNT0);
}
unsigned long _millis0()
{
	
	if ((TIFR0 & (1 << TOV0)) && (TCNT0 < 255))
	{
		_timer0_ovf_cnt++;
	}
	return _TICK_MS_0*(((_timer0_ovf_cnt << 8) + TCNT0));
}

ISR(TIMER0_OVF_vect)
{
	_timer0_ovf_cnt++;
}