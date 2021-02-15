/*
* matrix.h
*/

#include <stdint.h>
#include <avr/io.h>

#ifndef MATRIX_H_
#define MATRIX_H_

#define NUM_MATRICIES	4
#define NUM_COLUMNS		8

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