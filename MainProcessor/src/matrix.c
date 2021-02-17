/*
* matrix.c
*/

#include "../inc/matrix.h"
#include "../inc/spi.h"

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#define TRANSMIT_DELAY_MS 200

uint8_t buffer[NUM_MATRICIES*NUM_COLUMNS];// = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

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

void matrix_clear(void){
	
	for (uint8_t i = 0x01; i < (NUM_COLUMNS + 1); i++){
		spi_clear_ss();
		for (uint8_t j = 0x00; j < NUM_MATRICIES; j++){
			spi_write_register(i, 0x00);
		}
		spi_set_ss();
	}

	buffer_clear();
}

// set all buffer values to 0x00
void buffer_init(void){
	
	for(uint8_t i = 0x00; i < NUM_MATRICIES*NUM_COLUMNS; i++){
		buffer[i] = 0x00;
	}
	
}

// set all buffer values to 0x00
void buffer_clear(void){
	
	for(uint8_t i = 0x00; i < NUM_MATRICIES*NUM_COLUMNS; i++){
		buffer[i] = 0x00;
	}

}

// add val at the end of buffer
void buffer_push(uint8_t val){
	
	for (uint8_t i = 0; i < (NUM_MATRICIES*NUM_COLUMNS - 1); i++){
			//move every byte over by one
			buffer[i] = buffer[i+1];
	}
	
	//add new byte at the end
	buffer[NUM_MATRICIES*NUM_COLUMNS - 1] = val;
	
}

void buffer_shift(void){
	//
	//
	for(uint8_t i = 0; i < (NUM_COLUMNS*NUM_MATRICIES) - NUM_COLUMNS; i++){
		buffer[i]= (buffer[i] << 1) | (buffer[i+NUM_COLUMNS] >> 7);

	}


	for(uint8_t i = (NUM_COLUMNS*NUM_MATRICIES) - NUM_COLUMNS; i < (NUM_COLUMNS*NUM_MATRICIES); i++){
		buffer[i]= (buffer[i] << 1) | (buffer[i - ((NUM_COLUMNS*NUM_MATRICIES) - NUM_COLUMNS)] >> 7);
	
	}

}

void matrix_push_char(uint8_t val){
	
}

void matrix_push_str(char * val){
	
}

void matrix_display_buffer(void){
	for (uint8_t i = 0x00; i < NUM_MATRICIES; i++){
		for (uint8_t j = 0x01; j < NUM_COLUMNS+1; j++){
		
			spi_clear_ss();			
			for (uint8_t k = 0x00; k < i; k++){
				spi_write_register(0x00, 0x00);
			}
						
			spi_write_register(j, buffer[j + i * NUM_COLUMNS - 1]);
						
			for (uint8_t k = NUM_MATRICIES-1; k > i; k--){
				spi_write_register(0x00, 0x00);
			}
						
			spi_set_ss();
						
		}
					
	}
				
	_delay_ms(TRANSMIT_DELAY_MS);
	
}
