/*
 * __INT_0_1__.c
 *
 * Created: 5/11/2021 9:17:47 AM
 *  Author: adnan
 */ 

#include <__INT_0_1__.h>

void _interrupt0_enable(uint8_t trigger)
{
	if(trigger == _INT_RISING_EDGE)
	{
		EIMSK |= (1 << INT0);
		EICRA |= (1 << ISC00) | (1 << ISC01);
	}
	else if(trigger == _INT_FALLING_EDGE)
	{
		
		EIMSK |= (1 << INT0);
		EICRA |= (0 << ISC00) | (1 << ISC01);
	}
	else if(trigger == _INT_CHANGE_LEVEL)
	{
		
		EIMSK |= (1 << INT0);
		EICRA |= (1 << ISC00) | (0 << ISC01);
	}
	sei();
}
void _interrupt1_enable(uint8_t trigger)
{
	if(trigger == _INT_RISING_EDGE)
	{
		EIMSK |= (1 << INT1);
		EICRA |= (1 << ISC10) | (1 << ISC11);
	}
	else if(trigger == _INT_FALLING_EDGE)
	{
		
		EIMSK |= (1 << INT1);
		EICRA |= (0 << ISC10) | (1 << ISC11);
	}
	else if(trigger == _INT_CHANGE_LEVEL)
	{
		
		EIMSK |= (1 << INT1);
		EICRA |= (1 << ISC10) | (0 << ISC11);
	}
	sei();
}
