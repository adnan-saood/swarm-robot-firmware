/*
 * __odometry__.h
 *
 * Created: 5/19/2021 9:43:59 AM
 *  Author: adnan
 */ 


#ifndef __ODOMETRY___H_
#define __ODOMETRY___H_

#include <__swarm_wold__.h>

#define __ENC_TICK_THETA_FOR_OMEGA 190399
#define __ENC_TICK_THETA 0.1904
#define __PM_lower_bound 200
#define __PM_upper_bound 800

#define __PM_SAMPLE_COUNT 5
#define __PM_SLOPE 13.5 // rad per volt / time of one overflow

#define FORWARD  1
#define BACKWARD  -1


///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////



float _thetaA(void);
float _thetaB(void);

float _omega_from_encA(void);
float _omega_from_encB(void);

float _omega_from_PMA(void);
float _omega_from_PMB(void);

void _insertion_sort(uint16_t arr[], int n);



#endif /* __ODOMETRY___H_ */