#ifndef __TIMER0___H_
#define __TIMER0___H_

/*! \file *********************************************************************
 *
 * \brief Header file for __timer0__.c.
 *
 * - File:               __timer0__.h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            Discrete PID controller
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 1 $
 * $RCSfile$
 * $Date:5/19/2021 9:03:51 AM$
 *****************************************************************************/

#include <__swarm_wold__.h>

/**
       * Initialize Timer/Counter 0 with clock prescaler of 1024 (244 Hz overflow at 16 MHz) 
       */
void _timer0_init(void);

/**
       * Initialize Timer/Counter 0 with costume prescaler (see the datasheet) 
       */
void _timer0_init_prescaler(uint16_t prescaler/**< [in] prescaler 1,2,4,8,255,1024 */);

/**
       * Returns the microseconds passed since timer initialize 
       */
unsigned long _micros0(void);
/**
       * Returns the milliseconds passed since timer initialize 
       */
unsigned long _millis0(void);

#endif /* __TIMER0___H_ */