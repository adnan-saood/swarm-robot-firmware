#ifndef __USART___H_
#define __USART___H_
/*! \file *********************************************************************
 *
 * \brief Header file for pid.c.
 *
 * - File:               __usart__.h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            USART module driver
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 456 $
 * $RCSfile$
 * $Date:2021-5 $
 *****************************************************************************/


#define BAUD 57600
#define RX_BUFSIZE 120

#define BRC ((F_CPU/(16UL*BAUD)) - 1)




#include <asf.h>
#include <stdio.h>
#include <board.h>
#include <conf_board.h>
#include <util/delay.h>




/**
       * Dummy function to put a char into the UDR register and send it to serial bus 
       */
static int _uart_put_char(char input, FILE *stream);
/**
       * Dummy function to get a char from the serial bus 
       */
static int _uart_get_char(FILE *stream);
/**
       * Initialize the USART module with @param BAUD 
       */
void usart_init(void);

/**
       * point the stdin and stdout to the USART stream 
       */
static FILE uart_str =  FDEV_SETUP_STREAM(_uart_put_char/**< [in] put char functin*/, _uart_get_char /**< [in] get char function*/,_FDEV_SETUP_RW /**< [in] read, write, or read/write*/);



#endif /* __USART___H_ */