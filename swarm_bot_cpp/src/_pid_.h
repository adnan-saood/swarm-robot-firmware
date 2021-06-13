#ifndef _PID__H_
#define _PID__H_
/*! \file *********************************************************************
 *
 * \brief Header file for pid.c.
 *
 * - File:               pid.h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            Discrete PID controller
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 456 $
 * $RCSfile$
 * $Date:2021 $
 *****************************************************************************/

#include "stdint.h"

#define SCALING_FACTOR  128

/*! \brief PID Status
 *
 * Setpoints and data used by the PID control algorithm
 */
typedef struct PID_DATA{
  //! Last process value, used to find derivative of process value.
  int16_t lastProcessValue;
  //! Summation of errors, used for integrate calculations
  int32_t sumError;
  //! The Proportional tuning constant, multiplied with SCALING_FACTOR
  int16_t P_Factor;
  //! The Integral tuning constant, multiplied with SCALING_FACTOR
  int16_t I_Factor;
  //! The Derivative tuning constant, multiplied with SCALING_FACTOR
  int16_t D_Factor;
  //! Maximum allowed error, avoid overflow
  int16_t maxError;
  //! Maximum allowed sumerror, avoid overflow
  int32_t maxSumError;
} pidData_t;

/*! \brief Maximum values
 *
 * Needed to avoid sign/overflow problems
 */
// Maximum value of variables
#define MAX_INT         INT16_MAX
#define MAX_LONG        INT32_MAX
#define MAX_I_TERM      (MAX_LONG / 2)


extern volatile uint8_t flag;

// Boolean values
#define FALSE           0
#define TRUE            1

void pid_Init(int16_t p_factor, int16_t i_factor, int16_t d_factor, struct PID_DATA *pid);
int16_t pid_Controller(int16_t setPoint, int16_t processValue, struct PID_DATA *pid_st);
void pid_Reset_Integrator(pidData_t *pid_st);



#endif /* _PID__H_ */