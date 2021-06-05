/*
 * __INT_0_1__.c
 *
 * Created: 5/11/2021 9:17:47 AM
 *  Author: adnan
 */ 

#include <__INT_0_1__.h>

void _interrupt0_enable(uint8_t trigger)
{
	EIMSK |= (1 << INT0);
	EICRA |= (1 << ISC00) | (1 << ISC01);
	sei();
}
void _interrupt1_enable(uint8_t trigger)
{
	EIMSK |= (1 << INT1);
	EICRA |= (1 << ISC10) | (1 << ISC11);
	sei();
}
