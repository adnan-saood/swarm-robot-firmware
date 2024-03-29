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

#ifndef ODOMETRY_H_
#define ODOMETRY_H_

#include "__swarm_wold__.h"

/** \brief Threshold value for encoder ticks used to calculate angular velocity */
#define __ENC_TICK_THETA_FOR_OMEGA 190399

/** \brief Conversion factor from encoder ticks to radians */
#define __ENC_TICK_THETA 0.1904

/** \brief Lower bound for potentiometer readings */
#define __PM_lower_bound 200

/** \brief Upper bound for potentiometer readings */
#define __PM_upper_bound 800

/** \brief Number of samples taken for potentiometer readings */
#define __PM_SAMPLE_COUNT 5

/** \brief Slope for potentiometer readings, in radians per volt per overflow */
#define __PM_SLOPE 1

/** \brief Constant used to indicate forward motion */
#define FORWARD  1

/** \brief Constant used to indicate backward motion */
#define BACKWARD -1


/**
 * \brief Returns the absolute rotation angle of motor A.
 * \return The absolute rotation angle of motor A in radians.
 */
float _theta_A(void);


/**
 * \brief Returns the absolute rotation angle of motor B.
 * \return The absolute rotation angle of motor B in radians.
 */
float _theta_B(void);


/**
 * \brief Returns the angular velocity of motor A based on encoder readings.
 * \return The angular velocity of motor A in radians per second.
 *
 * This function measures the time between consecutive encoder ticks to determine
 * the angular velocity of motor A.
 */
float _omega_from_enc_A(void);


/**
 * \brief Returns the angular velocity of motor B based on encoder readings.
 * \return The angular velocity of motor B in radians per second.
 *
 * This function measures the time between consecutive encoder ticks to determine
 * the angular velocity of motor B.
 */
float _omega_from_enc_B(void);


/**
 * \brief Returns the angular velocity of motor A based on potentiometer readings.
 * \return The angular velocity of motor A in radians per second.
 *
 * This function uses the potentiometer readings of motor A to determine its angular velocity.
 */
float _omega_from_PM_A(void);


/**
 * \brief Returns the angular velocity of motor B based on potentiometer readings.
 * \return The angular velocity of motor B in radians per second.
 *
 * This function uses the potentiometer readings of motor B to determine its angular velocity.
 */
float _omega_from_PM_B(void);


/**
 * \brief Returns the complementary filter for the angular velocity of motor A.
 * \return The complementary filter for the angular velocity of motor A in radians per second.
 *
 * This function uses both encoder and potentiometer readings to calculate a more
 * accurate estimate of the angular velocity of motor A.
 */
float _omega_comp_A(void);


/**
 * \brief Returns the complementary filter for the angular velocity of motor B.
 * \return The complementary filter for the angular velocity of motor B in radians per second.
 *
 * This function uses both encoder and potentiometer readings to calculate a more
 * accurate estimate of the angular velocity of motor B.
 */
float omega_comp_B(void);


/**
 * \brief Returns the number of encoder ticks for motor A since boot.
 * \return The number of encoder ticks for motor A since boot.
 */
int32_t _ticksA();

/**
 * \brief Returns the number of encoder ticks for motor A since boot.
 * \return The number of encoder ticks for motor A since boot.
 */
int32_t _ticksB();

/**
 * \brief Indertio sort algorithm. Faster for small array sizes.
 */
void _insertion_sort(uint16_t arr[] /**< [in] pointer to start of sorting */, int n /**< [in] offset from @param arr[]*/);



#endif /* __ODOMETRY___H_ */