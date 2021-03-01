#include "../inc/matrix.h"
#include "../inc/spi.h"
#include "../inc/usart.h"

#include <avr/interrupt.h>

int main (void)
{
	//initializations
	usart_init();
	spi_init();
	matrix_init();
	matrix_clear();	
	buffer_init();
	buffer_clear();
	sei();
	
	while(1){

		if ((received_char != '\n') && (received_char != NULL)){
			
			matrix_push_char(received_char);
			received_char = NULL;

		} else if (received_char == '\n'){

			// add the same number of spaces as the
			// number of matrices to ensure the 
			// screen clears after the message
			for (uint8_t i = 0; i < NUM_MATRICIES; i++){
				matrix_push_char(' ');
			}
			while(!queue_is_empty()){
				matrix_display_buffer();
				buffer_shift();
			}	
			
			received_char = NULL;
		}
		
		
	}
	return 0;
}



	