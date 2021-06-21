#ifndef __ODOMETRY___H_
#define __ODOMETRY___H_

/*! \file *********************************************************************
 *
 * \brief Header file for __odometry__.c
 *
 * - File:               __odometry__h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            Odometry calculations for the mobile robot
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 1 $
 * $RCSfile$
 * $Date:5/19/2021 9:43:59 AM$
 *****************************************************************************/


#include <__swarm_wold__.h>

#define __ENC_TICK_THETA_FOR_OMEGA 190399
#define __ENC_TICK_THETA 0.190399
#define __PM_lower_bound 200
#define __PM_upper_bound 800

#define __PM_SAMPLE_COUNT 5
#define __PM_SLOPE 100.0 // rad per volt / time of one overflow

#define FORWARD  1
#define BACKWARD  -1

/**
       * Returns the absolute rotation angle of motor A
       */
float _thetaA(void);
/**
       * Returns the absolute rotation angle of motor B
       */
float _thetaB(void);

/**
       * Returns the A wheel's angular velocity from encoder readings by measuring he time between consecutive encoder ticks
       */
float _omega_from_encA(void);

/**
       * Returns the B wheel's angular velocity from encoder readings by measuring he time between consecutive encoder ticks
       */
float _omega_from_encB(void);


/**
       * returns the number of ticks happened since boot to wheel A
       */
int32_t _ticksA();

/**
       * returns the number of ticks happened since boot to wheel B
       */
int32_t _ticksB();


#endif /* __ODOMETRY___H_ */