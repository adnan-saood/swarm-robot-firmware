
#ifndef __PWM___H_
#define __PWM___H_

/*! \file *********************************************************************
 *
 * \brief Header file for __pwm__.c
 *
 * - File:               __pwm__.h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            PWM driver
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 1 $
 * $RCSfile$
 * $Date:5/19/2021 9:30:13 AM$
 *****************************************************************************/


#include <__swarm_wold__.h>

/**
       * sets the PWM output of OCR0A (Motor A rear) 
       */
void _set_pwm_0A(int input);
/**
       * sets the PWM output of OCR0B (Motor B rear) 
       */
void _set_pwm_0B(int input);
/**
       * sets the PWM output of OCR1A (Motor A front) 
       */
void _set_pwm_1A(int input);
/**
       * sets the PWM output of OCR1B (Motor B front) 
       */
void _set_pwm_1B(int input);



#endif /* __PWM___H_ */