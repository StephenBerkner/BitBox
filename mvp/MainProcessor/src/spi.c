/*
* spi.c
*/

#include "../inc/spi.h"

void spi_init(void){
	
	// Set SCK, CS, and MOSI as output pins
	// MISO is not currently used
	SPI_DDR |= (1 << SCK) | (1 << CS) | (1 << MOSI);
	
	// SPI bus master, clock rate = F_CPU/16
	SPCR |= (1 << MSTR) | (1 << SPR0);
	
	// Enable SPI
	SPCR |= (1 << SPE);
}

void spi_set_ss(void){
	PORTB |= (1 << PORTB2);
}

void spi_clear_ss(void){
	PORTB &= ~(1 << PORTB2);
}

void spi_write_byte(uint8_t val){
	SPDR = val;
	
	while(!(SPSR & (1 << SPIF)));
	
}

void spi_write_register(uint8_t addr, uint8_t val){
	spi_write_byte(addr);
	spi_write_byte(val);
}
