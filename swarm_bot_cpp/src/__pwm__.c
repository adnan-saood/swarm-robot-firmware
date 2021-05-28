/*
 * __pwm__.c
 *
 * Created: 5/19/2021 9:30:27 AM
 *  Author: adnan
 */ 
#include <__pwm__.h>


void _set_pwm_0A(int input)
{
	if (input > 255)
		{input = 255;}
	else if (input < 0)
		{input = 0;}
	
	
	OCR0A = (uint8_t)input;
}
void _set_pwm_0B(int input)
{

	if (input > 255)
		{input = 255;}
	else if (input < 0)
		{input = 0;}
		
	OCR0B = (uint8_t)input;
}
void _set_pwm_1A(int input)
{
	if (input > 255)
		{input = 255;}
	else if (input < 0)
		{input = 0;}
	
	
	OCR1AH = (uint8_t)(input);
	OCR1AL = 0;
}
void _set_pwm_1B(int input)
{
	if (input > 255)
		{input = 255;}
	else if (input < 0)
		{input = 0;}
	
	
	OCR1BH = (uint8_t)(input);
	OCR1BL = 0;
}