#include <__swarm_wold__.h>

/*! \file *********************************************************************
 *
 * \brief Header file for __dc_control__.c
 *
 * - File:               __dc_control__.h
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
 * $Date:5/26/2021 9:18:13 PM$
 *****************************************************************************/

#ifndef __DC_CONTROL___H_
#define __DC_CONTROL___H_

#define MA 1
#define MB 2

#define DEBUG_CONTROLLER 0

#define K_P     20.0
#define K_I     2
#define K_D     1


/**
       * Reference for @param motor
       */
int16_t _ref(uint8_t motor /**< [in] motor MA or MB. */);

/**
       * Output command module for @param motor of value @param inputValue
       */
void _command(uint8_t motor/**< [in] motor MA or MB. */, int16_t inputValue/**< [in] input value */);
/**
       * sensor module for @param motor
       */
float _sens(uint8_t motor/**< [in] motor MA or MB. */);
/**
       * L298 driver module using PWM signals and motor orientation
	   * @param value can be negative or positive for direction
       */
int _set_speed(uint8_t motor/**< [in] motor MA or MB. */, int value/**< [in] speed value */);
/**
       * breaks the @param motor
       */
void _break_motor(uint8_t motor/**< [in] motor MA or MB. */);

/**
       * Initialize the DC PID control module
       */
void _init_dc_control(void);
/**
       * Update a control iteration for a discrete PID controller for the DC motor
       */
int16_t _update_controller(uint8_t motor/**< [in] motor MA or MB. */);
/**
       * PID DC controller loop
       */
int16_t _dc_controller_loop(void);

#endif /* __DC_CONTROL___H_ */