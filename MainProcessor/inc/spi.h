/*
 * spi.h
 */ 

#ifndef SPI_H_
#define SPI_H_

#define SPI_DDR		DDRB
#define SCK			PINB5
#define MISO		PINB4
#define MOSI		PINB3
#define CS			PINB2

//SPI functions

void spi_init(void);

void spi_set_ss(void);

void spi_clear_ss(void);

void spi_write_byte(uint8_t val);

void spi_write_register(uint8_t addr, uint8_t val);

#endif /* SPI_H_ */