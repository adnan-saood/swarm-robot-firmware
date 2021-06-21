#ifndef __KINEMATICS___H_
#define __KINEMATICS___H_

/*! \file *********************************************************************
 *
 * \brief Header file for __kimenatics__.c
 *
 * - File:               __kimenatics__.h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            Kinematics calculations for the mobile robot
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 1 $
 * $RCSfile$
 * $Date: 5/29/2021 8:04:54 PM$
 *****************************************************************************/

	

#define L 0.07
#define r 0.0195
#define R_over_L 0.27857
#define R_over_2 0.00975


#include <__swarm_wold__.h>

/**
       * point struct (x and y card. coordinates
       */
struct point
{
	float x; ///< @param x 
	float y; ///< @param y
};

/**
       * position struct to hold robot's pos vector
       */
struct pos
{
	float x; ///< @param x
	float y; ///< @param y
	float th;///< @param Theta (\theta)
};


/**
       * position derivative vector struct (\frac{d pos}{dt})
       */
struct pos_dot
{
	float x_dot; ///< @param x'
	float y_dot; ///< @param y'
	float th_dot;///< @param \theta '	
};

/**
       * Inertial pos vector V and W
       */
struct _i_pos
{
	float v; ///< linear velocity V
	float w;///< rotational velocity W	
};

/**
       * square matrix struct
	   *[@param a @param b]
	   *[@param c @param d]
       */
struct mat2
{
	float a; ///< 11
	float b; ///< 12
	float c; ///< 21
	float d; ///< 22
};

/**
       * Struct to hold wheels' velocity rad/s
       */
struct _omega
{
	float wl; ///< left motor
	float wr; ///< right motor
};

/**
       * struct to hold wheel absolute rotation
       */
struct _theta
{
	float left; ///< left motor
	float right; ///< right motor	
};


/**
       * A function to convert wheels rotation velocity to inertial velocities
       */
struct _i_pos _omega_to_intertial(struct _omega * input /**< [in] struct of wheels velocity @param _omega */);

/**
       * A function to convert inertial velocities to pos_dot
       */
struct pos_dot _inertial_to_pos_dot(struct _i_pos * inertial /**< [in] struct of inertial pos*/, struct pos * _pos /**< [in] struct of current pos for \theta */);

/**
       * a dead-reckoner for spatial pos estimation, returns debug info
       */
uint16_t _dead_reckon(struct pos * _pos /**< [in] pos */, struct pos_dot * _pos_dot /**< [in] derivative of pos */); // uint8_t for debugging

/**
       * A function to convert wheels' absolute rotation angles to pos (not proper)
       */
struct pos _thetaLR_to_pos(struct _theta * th /**< [in] wheels' absolute rotation */);

/**
       * A function to update the absolute rotation angle of each wheel from hardware modules
       */
void _update_thetaLR(struct _theta * input /**< [in] wheels' absolute rotation */);

/**
       * A function to update the wheels' rotation velocity or each wheel from hardware modules
       */
void _update_omega(struct _omega * input /**< [in] wheel's rotational velocity */);

#endif /* __KINEMATICS___H_ */