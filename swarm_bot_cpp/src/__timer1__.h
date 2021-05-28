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
#define _TICK_US 1
#define _TICK_MS 0.001

extern volatile uint8_t _controler_flag_A;
extern volatile uint8_t _controler_flag_B;


void _timer1_init(void);
//void _timer1_init_prescaler(int prescaler);

uint64_t _micros1(void);
uint64_t _millis1(void);

#endif /* __TIMER1___H_ */