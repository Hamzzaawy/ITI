/*
 * uart_private.h
 *
 *  Created on: Jun 12, 2019
 *      Author: Hamza
 */

#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_

#define 	MUART_UDR  		*((volatile u8*)(0x2C))
#define 	MUART_UCSRA		*((volatile u8*)(0x2B))
#define 	MUART_UCSRB		*((volatile u8*)(0x2A))
#define 	MUART_UCSRC		*((volatile u8*)(0x40))
#define 	MUART_UBRRH		*((volatile u8*)(0x40))
#define 	MUART_UBRRL		*((volatile u8*)(0x29))

//global interupt enable pin in SREG
#define MUART_SREG      *((volatile u8*)(0x5F))



#endif /* MUART_PRIVATE_H_ */
