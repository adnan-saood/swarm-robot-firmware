/*
 * __pwm__.h
 *
 * Created: 5/19/2021 9:30:13 AM
 *  Author: adnan
 */ 


#ifndef __PWM___H_
#define __PWM___H_

#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <board.h>
#include <conf_board.h>
#include <util/delay.h>
#include <__swarm_wold__.h>

void _set_pwm_0A(int input);
void _set_pwm_0B(int input);
void _set_pwm_1A(int input);
void _set_pwm_1B(int input);



#endif /* __PWM___H_ */