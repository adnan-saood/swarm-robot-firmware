/*
 * __pin_map.h
 *
 * Created: 5/19/2021 8:24:17 AM
 *  Author: adnan
 */ 


#ifndef __PIN_MAP_H_
#define __PIN_MAP_H_
#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <board.h>
#include <conf_board.h>
#include <util/delay.h>
#include <__adc__.h>
#include <__timer1__.h>

///////////////////////////////////////////////
// LED
///////////////////////////////////////////////
#define D4 PORTB0
#define LED1 PORTB3
#define LED2 PORTB4
#define LED3 PORTB5

#define __led_high(NUM) PORTB|=(1 << NUM)
#define __led_low(NUM) PORTB|=(0 << NUM)
#define __led_toggle(NUM) PORTB ^= (1 << NUM)

///////////////////////////////////////////////
// ADC
///////////////////////////////////////////////
#define BTR PORTC2
#define SENSA 6
#define SENSB 7

#define PMA PORTC0
#define PMB PORTC1

#define __read_btr__ _adc_read(BTR)
#define __read_sens(A) _adc_read(A)
#define __read_PM(A) _adc_read(A)

///////////////////////////////////////////////
// SW
///////////////////////////////////////////////
#define SW1 PORTC3
#define SW2 PORTC4
#define SW3 PORTC5

#define __read_sw(A) (PINC &(1 << A))
#define __read_whole_sw__ ( __read_sw(SW1) | (__read_sw(SW2) << 1) | (__read_sw(SW3) << 2))

///////////////////////////////////////////////
// ENC
///////////////////////////////////////////////
#define ENCA2 PORTD4
#define ENCB2 PORTD7

#define __read_secodary_enc(A) (PIND &(1 << A))





#endif /* __PIN_MAP_H_ */