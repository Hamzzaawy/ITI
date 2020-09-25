/*
 * UART_Interface.h
 *
 *  Created on: Jul 12, 2019
 *      Author: Hamza
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void MUART_voidInit(void);

void MUART_voidSendChar(u8 copy_data);

void MUART_voidSendString(u8*);

u8 MUART_u8ReceiveChar(void);

u8* MUART_u8ReceiveString(void);

void MBootLoarder_voidParser(void);


#endif /* UART_INTERFACE_H_ */
