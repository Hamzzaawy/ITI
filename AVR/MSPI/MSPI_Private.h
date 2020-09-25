/*
 * MSPI_Private.h
 *
 *  Created on: Jun 16, 2019
 *      Author: Hamza
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

//SPCR Rigester bits
#define SPR0			0
#define SPR1			1
#define CPHA			2
#define CPOL			3
#define MSTR			4
#define DORD			5
#define SPE				6
#define SPIE			7

//SPSR	Register Bits
#define SPI2X			0
#define WCOL			6
#define SPIF			7


#define MSPI_SPDR 	 *((volatile u8*)(0x2F))

#define MSPI_SPSR    *((volatile u8*)(0x2E))

#define MSPI_SPCR    *((volatile u8*)(0x2D))

#define MSPI_SREG      *((volatile u8*)(0x5F))




#endif /* MSPI_PRIVATE_H_ */
