/*
* main.c
*/

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#include "../inc/matrix.h"
#include "../inc/spi.h"
#include "../inc/usart.h"

#define DEL		14000

int main (void)
{
	//usart_init();
	spi_init();
	matrix_init();
	matrix_clear();
	
	uint8_t values[8] = {0b11111111, 0b10000000, 0b10111111, 0b10100001, 0b10101101, 0b10111101, 0b10000001, 0b11111111};
	
	while(1){

				for (uint8_t i = 0x00; i < NUM_MATRICIES; i++){
					for (uint8_t j = 0x01; j < NUM_COLUMNS+1; j++){
						spi_clear_ss();
					
						for (uint8_t k = 0x00; k < i; k++){
							spi_write_register(0x00, 0x00);
						}	
						
						spi_write_register(j, values[j-1]);
					
						for (uint8_t k = NUM_MATRICIES-1; k > i; k--){
							spi_write_register(0x00, 0x00);
						}
						
						spi_set_ss();
											
					}
						
				}
				
				_delay_us(DEL);
			}

	return 0;
}
