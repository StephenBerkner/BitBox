/*
* matrix.h
*/

#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#ifndef MATRIX_H_
#define MATRIX_H_

#define MATRIX_TRANSMIT_DELAY 15

#define NUM_MATRICIES	4
#define NUM_COLUMNS		8

#define NUM_CHARS		96
#define CHAR_LENGTH     8

#define QUEUE_MAX_SIZE		NUM_MATRICIES*NUM_COLUMNS*NUM_COLUMNS

extern uint8_t buffer[NUM_MATRICIES*NUM_COLUMNS];
extern uint8_t queue[QUEUE_MAX_SIZE];
extern int queue_front;
extern int queue_rear;
extern int queue_count;

extern char const ascii_table[NUM_CHARS][CHAR_LENGTH] PROGMEM;

// queue functions
uint8_t queue_is_empty(void);

uint8_t queue_is_full(void);

int queue_size(void);

uint8_t queue_peek(void);

uint8_t queue_pop(void);

void queue_insert(uint8_t val);

// matrix Functions
void matrix_init(void);

void matrix_clear(void);

void buffer_init(void);

void buffer_clear(void);

void buffer_shift(void);

void matrix_push_char(char val);

void matrix_push_str(char * val);

void matrix_display_buffer(void);

#endif /* MATRIX_H_ */