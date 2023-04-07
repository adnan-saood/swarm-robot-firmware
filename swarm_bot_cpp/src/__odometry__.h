/**
 * \file odometry.h
 * \brief Header file for odometry.c
 *
 * \author Swarm robot graduation project workgroup
 * \author Mechatronics Program for the Distinguished
 *
 * \date 5/19/2021
 *
 * \details This header file contains function declarations and preprocessor definitions
 *          used for odometry calculations for a mobile robot.
 *
 * \note Tested on ATmega328P microcontroller
 */

#ifndef ODOMETRY_H_
#define ODOMETRY_H_

#include <swarm_world.h>

/** \brief Threshold value for encoder ticks used to calculate angular velocity */
#define ENC_TICK_THETA_FOR_OMEGA 190399

/** \brief Conversion factor from encoder ticks to radians */
#define ENC_TICK_THETA 0.1904

/** \brief Lower bound for potentiometer readings */
#define PM_LOWER_BOUND 200

/** \brief Upper bound for potentiometer readings */
#define PM_UPPER_BOUND 800

/** \brief Number of samples taken for potentiometer readings */
#define PM_SAMPLE_COUNT 5

/** \brief Slope for potentiometer readings, in radians per volt per overflow */
#define PM_SLOPE 1

/** \brief Constant used to indicate forward motion */
#define FORWARD  1

/** \brief Constant used to indicate backward motion */
#define BACKWARD -1


/**
 * \brief Returns the absolute rotation angle of motor A.
 * \return The absolute rotation angle of motor A in radians.
 */
float theta_A(void);


/**
 * \brief Returns the absolute rotation angle of motor B.
 * \return The absolute rotation angle of motor B in radians.
 */
float theta_B(void);


/**
 * \brief Returns the angular velocity of motor A based on encoder readings.
 * \return The angular velocity of motor A in radians per second.
 *
 * This function measures the time between consecutive encoder ticks to determine
 * the angular velocity of motor A.
 */
float omega_from_enc_A(void);


/**
 * \brief Returns the angular velocity of motor B based on encoder readings.
 * \return The angular velocity of motor B in radians per second.
 *
 * This function measures the time between consecutive encoder ticks to determine
 * the angular velocity of motor B.
 */
float omega_from_enc_B(void);


/**
 * \brief Returns the angular velocity of motor A based on potentiometer readings.
 * \return The angular velocity of motor A in radians per second.
 *
 * This function uses the potentiometer readings of motor A to determine its angular velocity.
 */
float omega_from_PM_A(void);


/**
 * \brief Returns the angular velocity of motor B based on potentiometer readings.
 * \return The angular velocity of motor B in radians per second.
 *
 * This function uses the potentiometer readings of motor B to determine its angular velocity.
 */
float omega_from_PM_B(void);


/**
 * \brief Returns the complementary filter for the angular velocity of motor A.
 * \return The complementary filter for the angular velocity of motor A in radians per second.
 *
 * This function uses both encoder and potentiometer readings to calculate a more
 * accurate estimate of the angular velocity of motor A.
 */
float omega_comp_A(void);


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