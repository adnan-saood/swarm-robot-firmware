#include <__usart__.h>

static int _uart_put_char(char input, FILE *stream)
{
	if (input == '\n')
	_uart_put_char('\r', stream);
	
	while(!((UCSR0A >> UDRE0) & 1)); // wait until buffer is ready for data
	UDR0 = input;
	return 0;
}

static int _uart_get_char(FILE *stream)
{
	uint8_t c;
	while(!(UCSR0A&(1<<RXC0)));
	c = UDR0;
	//_uart_put_char(c,stream); // for debug only
	return c;
}

void usart_init(void)
{
	UBRR0H = (uint8_t) (BRC >> 8); // baud
	UBRR0L = (uint8_t) BRC; // baud

	UCSR0B = (1 << TXEN0) | (1 << RXEN0); // enable rx and tx
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // clock
	UCSR0A |= (1 << U2X0); // double speed
	
	stdin = stdout = &uart_str; // link stdin and stdout to uart
	
}

