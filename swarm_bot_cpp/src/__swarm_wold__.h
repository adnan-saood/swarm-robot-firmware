#ifndef __SWARM_WOLD___H_
#define __SWARM_WOLD___H_

/*! \file *********************************************************************
 *
 * \brief Header file for dummy purposes
 *
 * - File:               __swarm_world__.h
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
 * $Date:5/19/2021 9:31:42 AM$
 *****************************************************************************/

#define F_CPU 16000000

#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <board.h>
#include <conf_board.h>
#include <util/delay.h>

#include "stdint.h"

#include <__adc__.h>
#include <__INT_0_1__.h>
#include <__pin_map.h>
#include <__timer0__.h>
#include <__timer1__.h>
#include <__timer2__.h>
#include <__usart__.h>
#include <__dc_control__.h>
#include <__odometry__.h>
#include <__pwm__.h>
#include <_pid_.h>
#include <__format__.h>
#include <__path_follow__.h>
#include <__moves__.h>
#include <__kinematics__.h>

#endif /* __SWARM_WOLD___H_ */