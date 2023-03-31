/*! \file *********************************************************************
 *
 * \brief Header file for __format__.c
 *
 * - File:               __format__.h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            PID for DC motor control
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 1 $
 * $RCSfile$
 * $Date:6/5/2021 12:34:48 AM$
 *****************************************************************************/


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

