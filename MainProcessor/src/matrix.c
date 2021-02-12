/*
 * matrix.c
 *
 */ 

#include "../inc/matrix.h"

#define NUM_MATRICIES 4

// Matrix functions 
void matrix_init(void){
	
	spi_clear_ss();
	for (uint8_t i = 0; i < NUM_MATRICIES; i++){
		// intensity register, set brightness level
		spi_write_register(0x0A, 0x07);
	}
	spi_set_ss();

	spi_clear_ss();
	for (uint8_t i = 0; i < NUM_MATRICIES; i++){
		// scan-limit register, columns 0-7
		spi_write_register(0x0B, 0x07);
	}
	spi_set_ss();

	spi_clear_ss();
	for (uint8_t i = 0; i < NUM_MATRICIES; i++){
		// shutdown register, normal operation mode
		spi_write_register(0x0C, 0x01);
	}
	spi_set_ss();
	
	
	
}

void matrix_clear(void);

void buffer_init(void);

void buffer_clear(void);

void buffer_push(void);

void matrix_push_char(uint8_t val);

void matrix_push_str(char * val);

#endif /* MATRIX_H_ */