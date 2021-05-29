/*
 * __timer0__.h
 *
 * Created: 5/19/2021 9:03:51 AM
 *  Author: adnan
 */ 


#ifndef __TIMER0___H_
#define __TIMER0___H_

#include <__swarm_wold__.h>


void _timer0_init(void);
void _timer0_init_prescaler(uint16_t prescaler);


unsigned long _micros0(void);
unsigned long _millis0(void);

#endif /* __TIMER0___H_ */