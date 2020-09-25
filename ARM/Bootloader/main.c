/*
 * main.c
 *
 *  Created on: Jul 12, 2019
 *      Author: Hamza
 */


#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MRCC_interface.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"
#include "UART_Interface.h"
#include "parser.h"


u8* data;
Parser parser;
void main (void)
{
	MRCC_voidInit();
	MRCC_voidEnPeriphClk(MRCC_U8_USART1);
	MRCC_voidEnPeriphClk(MRCC_U8_GPIOA);
	MRCC_voidEnPeriphClk(MRCC_U8_GPIOC);

	MUART_voidInit();

	MDIO_voidSetPinMode(MDIO_PORTA,MDIO_PIN_9,MDIO_MODE_AF_OUTPUT_PUSHPULL_2);
	MDIO_voidSetPinMode(MDIO_PORTA,MDIO_PIN_10,MDIO_MODE_INPUT_FLOATING);
	MDIO_voidSetPinMode(MDIO_PORTC,MDIO_PIN_13,MDIO_MODE_OUTPUT_PUSHPULL_2);


	MDIO_voidSetPinValue(MDIO_PORTC,MDIO_PIN_13,DIO_U8_LOW);

	while (1)
	{
		data=MUART_u8ReceiveString();
		parserFunction(data,&parser);
//		if(data == 'R')
//		{
//			//MDIO_voidSetPinValue(DIO_U8_PIN32,DIO_u8_HIGH);
//		}
		//MUART_voidSendString(parser.DataCount);
		//MUART_voidSendString(parser.Address);
		MUART_voidSendString(parser.Data);


	}
}
