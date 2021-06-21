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

 *****************************************************************************/

#include "stdint.h"

#define SCALING_FACTOR  128

/*! \brief PID Status
 *
 * Setpoints and data used by the PID control algorithm
 */
typedef struct PID_DATA{
  //! Last process value, used to find derivative of process value.
  float lastProcessValue;
  //! Summation of errors, used for integrate calculations
  float sumError;
  //! The Proportional tuning constant, multiplied with SCALING_FACTOR
  float P_Factor;
  //! The Integral tuning constant, multiplied with SCALING_FACTOR
  float I_Factor;
  //! The Derivative tuning constant, multiplied with SCALING_FACTOR
  float D_Factor;
  //! Maximum allowed error, avoid overflow
  float maxError;
  //! Maximum allowed sumerror, avoid overflow
  float maxSumError;
} pidData_t;

/*! \brief Maximum values
 *
 * Needed to avoid sign/overflow problems
 */
// Maximum value of variables
#define MAX_INT         INT16_MAX
#define MAX_LONG        INT32_MAX
#define MAX_I_TERM      (100)


extern volatile uint8_t flag;

// Boolean values
#define FALSE           0
#define TRUE            1

void pid_Init(float p_factor, float i_factor, float d_factor, struct PID_DATA *pid);
float pid_Controller(float setPoint, float processValue, struct PID_DATA *pid_st);
void pid_Reset_Integrator(pidData_t *pid_st);



#endif /* _PID__H_ */