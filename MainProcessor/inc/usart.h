/*
* usart.h
*/
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#define BAUD 2400
#define MYUBRR F_CPU/16/BAUD-1

#define USART_TRANSMIT_DELAY 10

#ifndef USART_H_
#define USART_H_

void usart_init(void);

void usart_transmit_char(char val);

void usart_transmit_string(char * val);

uint8_t usart_receive_byte(void);

char usart_receive_char(void);

#endif /* USART_H_ */