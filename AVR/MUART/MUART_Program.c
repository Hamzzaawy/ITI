/*
 * uart.c
 *
 *  Created on: Jun 12, 2019
 *      Author: Hamza
 */

#include "LSTR_Types.h"
#include "LUTILS.h"
#include "MUART_Interface.h"
#include "MUART_Private.h"
#include "MDIO_interface.h"
#include "MUART_Config.h"
#include "util/delay.h"


void (*Pointer)(void);

u8 Data_String[50]={0};


#if Operation_Mode == Async_Normal
#define UBRR			( ( F_osc / (16* BAUD ) ) -1 )
#elif Operation_Mode== Async_Double_Speed
#define UBRR			( ( F_osc / (8 * BAUD ) ) -1 )
#elif	Operation_Mode == Sync_Mode
#define UBRR			( ( F_osc / (2 * BAUD ) ) -1 )
#endif

void MUART_En_Dis_INT_Global(u8 Mode)
{
	switch(Mode)
	{
		case CLR_I:		MUART_SREG=Clr_Bit(MUART_SREG,7);			break;
		case EN_I:		MUART_SREG=Set_Bit(MUART_SREG,7);			break;
	}

}


void MUART_Set_Call_Back(void (*ptr)(void))
{
	Pointer=ptr;
}




void MUART_voidIntit(void)
{
	u8 UCSRC_Temp=(0b1000000);

	MUART_UCSRB=Set_Bit(MUART_UCSRB,RXEN);	//enable RXEN
	MUART_UCSRB=Set_Bit(MUART_UCSRB,TXEN);	//enable Txen

	MUART_UCSRB &= ~(1<<2);
	MUART_UCSRB |= (((u8)Data_Size>>2)<<2);
	UCSRC_Temp &= ~(0b11<<4);
	UCSRC_Temp |= (((u8)Data_Size <<6)>>5);

#if Operation_Mode== Async_Normal
	UCSRC_Temp=Clr_Bit(UCSRC_Temp,UMSEL);// asynchronous mode
#elif 	Operation_Mode== Async_Double_Speed
	UCSRC_Temp=Clr_Bit(UCSRC_Temp,UMSEL);
	MUART_UCSRA==Set_Bit(MUART_UCSRA,U2X);
#elif	Operation_Mode==Sync_Mode
	UCSRC_Temp=Set_Bit(UCSRC_Temp,UMSEL);
#endif

	UCSRC_Temp &= ~(0b11 << 4);				//parity config
	UCSRC_Temp |= (Parity_Condition << 4);

#if Stop_Bits == 0
	UCSRC_Temp=Clr_Bit(UCSRC_Temp,USBS);// 1 stop bit
#else
	UCSRC_Temp=Set_Bit(UCSRC_Temp,USBS);// 2 stop bits
#endif

	if(UBRR<255)
	{
		MUART_UBRRH=0;
		MUART_UBRRL=UBRR;
	}
	else
	{
		MUART_UBRRL=(u8)UBRR;
		MUART_UBRRH=UBRR>>8;
	}

#if RX_INT_En == 0
	MUART_UCSRB=Clr_Bit(MUART_UCSRB,RXCIE);// Disable The RX INT
#else
	MUART_UCSRB=Set_Bit(MUART_UCSRB,RXCIE);// Enbale The RX INT
#endif

#if TX_INT_En == 0
	MUART_UCSRB=Clr_Bit(MUART_UCSRB,TXCIE);// Disable The TX INT
#else
	MUART_UCSRB=Set_Bit(MUART_UCSRB,TXCIE);// Enbale The TX INT
#endif

#if UDR_INT_En == 0
	MUART_UCSRB=Clr_Bit(MUART_UCSRB,UDRIE);// Disable The RX INT
#else
	MUART_UCSRB=Set_Bit(MUART_UCSRB,UDRIE);// Enbale The RX INT
#endif

	UCSRC_Temp|=0b10000000;
//
//	if(UCSRC_Temp==0b10001100)
//	{
//		MDIO_SetPinValue(PORTA,0,HIGH);
//
//	}

	MUART_UCSRC=(UCSRC_Temp);

}


void MUART_voidSendByte(u8 Byte)
{
	while(GET_Bit(MUART_UCSRA,UDRE)==0);
	MUART_UDR=Byte;

}

void MUART_voidSendString(u8* String)
{
	u8 i=0;
	while(String[i]!='\0')
	{
		while(GET_Bit(MUART_UCSRA,UDRE)==0);
		MUART_UDR=String[i];
		i++;
	}


}


u8 MUART_u8ReceiveByte(void)
{
	while (GET_Bit(MUART_UCSRA,RXC)==0);
	return MUART_UDR;

}


void __vector_13 (void)
{
	u8 	   data=MUART_UDR;
	static u8 i=0;
	i++;
	Data_String[i]=data;
	if(Data_String[i]=='\0')
	{
		MUART_voidSendString(Data_String);
	}


}

void __vector_14 (void)
{

}

void __vector_15 (void)
{


}
