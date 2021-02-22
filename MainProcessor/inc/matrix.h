/*
* matrix.h
*/

#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#ifndef MATRIX_H_
#define MATRIX_H_

#define NUM_MATRICIES	4
#define NUM_COLUMNS		8

#define NUM_CHARS		96
#define CHAR_LENGTH     8

extern char const ascii_table[19][CHAR_LENGTH] PROGMEM;

//Matrix Functions
void matrix_init(void);

void matrix_clear(void);

void buffer_init(void);

void buffer_clear(void);

void buffer_push(uint8_t val);

void buffer_shift(void);

void matrix_push_char(uint8_t val);

void matrix_push_str(char * val);

void matrix_display_buffer(void);

#endif /* MATRIX_H_ */