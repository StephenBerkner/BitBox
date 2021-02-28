#include "../inc/matrix.h"
#include "../inc/spi.h"
#include "../inc/usart.h"


int main (void)
{
	//initializations
	usart_init();
	spi_init();
	matrix_init();
	matrix_clear();	
	buffer_init();
	buffer_clear();
	
	while(1){
		//check for available data in serial buffer
		if ((UCSR0A & (1 << RXC0)) != 0){
			//push data 
			matrix_push_char(UDR0);
		}
		
		matrix_display_buffer();
		buffer_shift();
	}
	return 0;
}



	