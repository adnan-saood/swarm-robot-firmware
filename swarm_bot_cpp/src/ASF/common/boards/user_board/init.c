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

#include <__swarm_wold__.h>



void board_init(void)
{
	/* This function is meant to contain board-specific initialization code
	 * for, e.g., the I/O pins. The initialization can rely on application-
	 * specific board configuration, found in conf_board.h.
	 */
	
	// IO init
	
	DDRB = 0xFF;
	DDRD = 0b01100010;
	
	__led_low(D4);
	_delay_ms(100);
	__led_high(D4);
	
	
	usart_init();
	_adc_init();
	_timer1_init();
	_timer0_init();
	_timer2_init();
	_interrupt0_enable(_INT_CHANGE_LEVEL);
	_interrupt1_enable(_INT_CHANGE_LEVEL);
	printf("---BOARD-INITIALIZED---");
	
	
}

