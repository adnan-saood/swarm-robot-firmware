/*
 * __timer1__.h
 *
 * Created: 5/9/2021 10:17:41 AM
 *  Author: adnan
 */ 


#ifndef __TIMER1___H_
#define __TIMER1___H_


#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <board.h>
#include <conf_board.h>
#include <util/delay.h>

#define _TICK_US 4096
#define _TICK_MS 4.096

static uint16_t _tcnt1_mem = 0;
static uint64_t _tmr_overflow_count = 0;
void _timer1_init(void);
void _timer1_init_prescaler(uint8_t prescaler);
void _timer1_stop_and_clear(void);
void _timer1_stop_and_save(void);

uint64_t _micros(void);

#endif /* __TIMER1___H_ */