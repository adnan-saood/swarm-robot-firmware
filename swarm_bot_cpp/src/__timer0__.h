/*
 * __timer0__.h
 *
 * Created: 5/19/2021 9:03:51 AM
 *  Author: adnan
 */ 


#ifndef __TIMER0___H_
#define __TIMER0___H_


#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <board.h>
#include <conf_board.h>
#include <util/delay.h>

static uint16_t _tcnt0_mem = 0;
static uint64_t _tmr0_overflow_count = 0;

uint8_t _is_tmr0_enabled();

void _timer0_init(void);
void _timer0_init_prescaler(uint8_t prescaler);
void _timer0_stop_and_clear(void);
void _timer0_stop_and_save(void);
void _timer0_enable_ovf(void);

unsigned long _micros0(void);
unsigned long _millis0(void);

#endif /* __TIMER0___H_ */