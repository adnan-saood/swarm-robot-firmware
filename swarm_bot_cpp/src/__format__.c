/*
 * __format__.c
 *
 * Created: 6/5/2021 12:34:48 AM
 *  Author: adnan
 */ 

#include <__format__.h>


char * _float_to_printable(float input)
{
	//a.b
	int16_t a = input;
	uint16_t b = (float)((input - (float)a ) * 10000.0);
	char *out;
	
	sprintf(out, "%d,%u", a,b);
	return out;
}

