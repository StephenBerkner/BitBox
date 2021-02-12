/*
 * matrix.h
 */ 

#ifndef MATRIX_H_
#define MATRIX_H_

//Matrix Functions
void matrix_init(void);

void matrix_clear(void);

void buffer_init(void);

void buffer_clear(void);

void buffer_push(void);

void matrix_push_char(uint8_t val);

void matrix_push_str(char * val);

#endif /* MATRIX_H_ */