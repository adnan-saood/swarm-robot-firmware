/*
 * __odometry__.h
 *
 * Created: 5/19/2021 9:43:59 AM
 *  Author: adnan
 */ 


#ifndef __ODOMETRY___H_
#define __ODOMETRY___H_

#include <__swarm_wold__.h>

#define __ENC_TICK_THETA 0.1904
#define __PM_lower_bound 200
#define __PM_upper_bound 800

#define __PM_SAMPLE_COUNT 5
#define __PM_SLOPE 13.5 // rad per volt / time of one overflow


// amount if time in a tick
static uint64_t _tick_timeA = 0;
static uint64_t _tick_timeB = 0;

//previous tick time in micros
static uint64_t _prev_tick_timeA = 0;
static uint64_t _prev_tick_timeB = 0;


static uint64_t _enca_count = 0;
static uint64_t _encb_count = 0;

static uint16_t _pmA_prev = -1;
static uint16_t _pmA_current = 0;

static uint16_t _pmB_prev = -1;
static uint16_t _pmB_current = 0;

static float _omega_pmA = 0.0f;
static float _omega_pmB = 0.0f;


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