/*
 * UART_Program.c

 *
 *  Created on: Jul 12, 2019
 *      Author: Hamza
 */


#include "LSTR_Types.h"
#include "LUTILS.h"

#include "UART_Interface.h"
#include "UART_Private.h"


static u8 data[50]={0};

void MUART_voidInit(void)
{
	MUART_CR1=Set_Bit(MUART_CR1,UE);

	MUART_CR1=Clr_Bit(MUART_CR1,M);

	MUART_CR1=Clr_Bit(MUART_CR1,PCE);

	MUART_CR1=Set_Bit(MUART_CR1,TE);

	MUART_CR1=Set_Bit(MUART_CR1,RE);

	MUART_CR2=Clr_Bit(MUART_CR2,STOP0);
	MUART_CR2=Clr_Bit(MUART_CR2,STOP1);

	MUART_BRR=0x8A;




}

void MUART_voidSendChar(u8 copy_data)
{
	MUART_DR=copy_data;

	while(GET_Bit(MUART_SR,TC)==0);
}

void MUART_voidSendString(u8* copy_data)
{
	u8 offset=0;
	while(copy_data[offset] != '\r')
	{
		MUART_voidSendChar(copy_data[offset]);
		offset++;
	}
}

u8 MUART_u8ReceiveChar(void)
{
	while(GET_Bit(MUART_SR,RXNE)==0);

	return MUART_DR;
}

u8* MUART_u8ReceiveString(void)
{
	u8 offset=0;
	do
	{
		while(GET_Bit(MUART_SR,RXNE)==0);
		u8 rvalue = MUART_DR;
		data[offset]=rvalue;
		offset++;
	}while(data[offset-1] != '\r');

	return data;

}

void MBootLoarder_voidParser(void)
{

}
