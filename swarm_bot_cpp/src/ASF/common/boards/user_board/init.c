/**
 * \file
 *
 * \brief User board initialization template
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <asf.h>
#include<stdio.h>
#include <board.h>
#include <conf_board.h>
#include <__adc__.h>
#include "__usart__.h"
#include <util/delay.h>
#include <__timer1__.h>
#include <__INT_0_1__.h>


void board_init(void)
{
	/* This function is meant to contain board-specific initialization code
	 * for, e.g., the I/O pins. The initialization can rely on application-
	 * specific board configuration, found in conf_board.h.
	 */
	
	usart_init();
	_adc_init();
	_timer1_init();
	_interrupt0_enable(_INT_RISING_EDGE);
	
}

