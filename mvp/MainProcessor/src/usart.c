/*
* usart.c
*/

#include "../inc/usart.h"
#include "../inc/matrix.h"
#include <util/delay.h>
#include <avr/interrupt.h>
char received_char;

// receive interrupt service routine
ISR(USART_RX_vect){
	received_char = (char)UDR0;
}

void usart_init(void){
	UBRR0H = (unsigned char)((MYUBRR) >> 8);
	UBRR0L = (unsigned char)(MYUBRR);
	
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
	UCSR0C = (0 << USBS0) | (0 << UCSZ02)| (1 << UCSZ01) | (3 << UCSZ00);
	received_char = NULL;
}

void usart_transmit_char(char val){
	while( !(UCSR0A & (1 << UDRE0)) );
	UDR0 = val;
}

void usart_transmit_string(char * val){
	unsigned char current;
	
	while((current = *val++)){
		usart_transmit_char(current);
		_delay_ms(USART_TRANSMIT_DELAY);
	}	
}

uint8_t usart_receive_byte(void){
	while (!(UCSR0A & (1<<RXC0)));
	
	return UDR0;
}

char usart_receive_char(void){
	while (!(UCSR0A & (1<<RXC0)));
	
	return (char) UDR0;
}

