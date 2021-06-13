#include <__pwm__.h>



/**
       * sets the PWM output of OCR0A (Motor A rear) 
       */
void _set_pwm_0A(int input/**< [in] @param input a number (0 --> 255) */)
{
	if (input > 255)
		{input = 255;}
	else if (input < 0)
		{input = 0;}
	
	
	OCR0A = (uint8_t)input;
}

/**
       * sets the PWM output of OCR0B (Motor B rear) 
       */
void _set_pwm_0B(int input/**< [in] @param input a number (0 --> 255)*/)
{

	if (input > 255)
		{input = 255;}
	else if (input < 0)
		{input = 0;}
		
	OCR0B = (uint8_t)input;
}

/**
       * sets the PWM output of OCR1A (Motor A front) 
       */
void _set_pwm_1A(int input/**< [in] @param input a number (0 --> 255) */)
{
	if (input > 255)
		{input = 255;}
	else if (input < 0)
		{input = 0;}
	
	
	OCR1AH = (uint8_t)(input);
	OCR1AL = 0;
}

/**
       * sets the PWM output of OCR1B (Motor B front) 
       */
void _set_pwm_1B(int input /**< [in] @param input a number (0 --> 255)*/)
{
	if (input > 255)
		{input = 255;}
	else if (input < 0)
		{input = 0;}
	
	
	OCR1BH = (uint8_t)(input);
	OCR1BL = 0;
}