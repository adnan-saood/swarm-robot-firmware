/*
 * __timer1__.h
 *
 * Created: 5/9/2021 10:17:41 AM
 *  Author: adnan
 */ 


#ifndef __TIMER1___H_
#define __TIMER1___H_


#include <__swarm_wold__.h>

#pragma message "Make sure of Tick time"


#define _TICK_US_1 0.0625
#define _TICK_MS_1 0.0000625

#define _TICK_US_0 16
#define _TICK_MS_0 0.016

extern volatile uint8_t _controler_flag_A;
extern volatile uint8_t _controler_flag_B;


void _timer1_init(void);
//void _timer1_init_prescaler(int prescaler);

uint64_t _micros1(void);
uint64_t _millis1(void);

#endif /* __TIMER1___H_ */