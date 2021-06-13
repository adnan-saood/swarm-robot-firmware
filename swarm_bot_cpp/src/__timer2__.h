#ifndef __TIMER2___H_
#define __TIMER2___H_

/*! \file *********************************************************************
 *
 * \brief Header file for __timer2__.c.
 *
 * - File:               __timer2__.h
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
 * $Date:5/20/2021 12:04:32 AM$
 *****************************************************************************/


#include <__swarm_wold__.h>

/**
       * Initialize Timer/Counter 2 with 1 prescaler (244 Hz overflow frequency at 16 MHz) 
       */
void _timer2_init(void);

#endif /* __TIMER2___H_ */