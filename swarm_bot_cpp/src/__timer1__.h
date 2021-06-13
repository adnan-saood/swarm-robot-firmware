#ifndef __TIMER1___H_
#define __TIMER1___H_

/*! \file *********************************************************************
 *
 * \brief Header file for __timer1__.c.
 *
 * - File:               __timer1__.h
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
 * $Date:5/9/2021 10:17:41 AM$
 *****************************************************************************/

#include <__swarm_wold__.h>

#pragma message "Make sure of Tick time"


#define _TICK_US_1 0.0625
#define _TICK_MS_1 0.0000625

#define _TICK_US_0 16
#define _TICK_MS_0 0.016

extern volatile uint8_t _controler_flag_A;
extern volatile uint8_t _controler_flag_B;

/**
       * Initialize Timer/Counter 1 with 1 prescaler (244 MHz overflow frequency at 16 MHz) 
       */
void _timer1_init(void);
//void _timer1_init_prescaler(int prescaler);

uint64_t _micros1(void);
uint64_t _millis1(void);

#endif /* __TIMER1___H_ */