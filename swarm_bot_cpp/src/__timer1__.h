/*
 * __timer1__.h
 *
 * Created: 5/9/2021 10:17:41 AM
 *  Author: adnan
 */ 


#ifndef __TIMER1___H_
#define __TIMER1___H_


#include <__swarm_wold__.h>

#define _TICK_US 1
#define _TICK_MS 0.001


void _timer1_init(void);
void _timer1_init_prescaler(int prescaler);
void _timer1_stop_and_clear(void);
void _timer1_stop_and_save(void);

uint64_t _micros(void);
uint64_t _millis(void);

#endif /* __TIMER1___H_ */