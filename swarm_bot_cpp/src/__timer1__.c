/*
 * __timer1__.c
 *
 * Created: 5/9/2021 10:17:30 AM
 *  Author: adnan
 */ 

#include "__timer1__.h"

volatile uint64_t _tmr_overflow_count = 0;

volatile uint8_t _controler_flag_A = 0;
volatile uint8_t _controler_flag_B = 0;

void _timer1_init(void)
{
	TCCR1A |= (1 << COM1A1) | (0 << COM1A0) | (1 << COM1B1) | (0 << COM1B0);
	TCCR1A |= (1 << WGM11 ) | (0 << WGM10 ) ; // top is ICr , FAST PWM
	ICR1 = 0xFFFF;
	TCCR1B |= (1 << WGM13) | (1 << WGM12);
	TCCR1B |= (0 << CS12 ) | (0 << CS11 ) | (1 << CS10); // timer active at 16M/65526 frequency of Overflow
	TIMSK1 |= (1 << TOIE1);
	sei();
}
// Commented out for space saving
/*
void _timer1_init_prescaler(int prescaler)
{
	TCCR1A |= (1 << COM1A1) | (0 << COM1A0) | (1 << COM1B1) | (0 << COM1B0);
	TCCR1A |= (1 << WGM11) | (0 << WGM10) ; // top is ICr , FAST PWM
	ICR1 = 0xFFFF;
	TCCR1B |= (1 << WGM13) | (1 << WGM12);
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
					TCCR1A &= 0b11111000 ; __CS__ = 0;break;
			
	}
	
	TCCR1B |= __CS__;
}
*/


uint64_t _micros1(void)
{
	uint16_t tmr = TCNT1L;
	tmr |= (TCNT1H << 8);
	return _TICK_US_1*(tmr + ( _tmr_overflow_count << 16));
}

uint64_t _millis1(void)
{
	uint16_t tmr = TCNT1L;
	tmr |= (TCNT1H << 8);
	return _TICK_MS_1*(tmr + ( _tmr_overflow_count << 16));
}

ISR(TIMER1_OVF_vect)
{
	_tmr_overflow_count++;
	
	_controler_flag_A = 1;
	_controler_flag_B = 1;
}