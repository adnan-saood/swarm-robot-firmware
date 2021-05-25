#ifndef __USART___H_
#define __USART___H_


#define BAUD 4800
#define RX_BUFSIZE 120

#define BRC ((F_CPU/(16UL*BAUD)) - 1)




#include <asf.h>
#include <stdio.h>
#include <board.h>
#include <conf_board.h>
#include <util/delay.h>





static int _uart_put_char(char input, FILE *stream);
static int _uart_get_char(FILE *stream);
void usart_init(void);

static FILE uart_str =  FDEV_SETUP_STREAM(_uart_put_char, _uart_get_char,_FDEV_SETUP_RW);



#endif /* __USART___H_ */