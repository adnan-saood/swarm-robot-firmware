/*
 * __adc__.h
 *
 * Created: 5/9/2021 9:44:28 AM
 *  Author: adnan
 */ 


#ifndef __ADC___H_
#define __ADC___H_

//#define __ADC_RES_8_BIT
#define __ADC_RES_10_BIT


#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <board.h>
#include <conf_board.h>
#include <util/delay.h>




void _adc_init(void);
int _adc_read(char channel);

#endif /* __ADC___H_ */