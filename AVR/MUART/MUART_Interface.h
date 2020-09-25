/*
 * uart_interface.h
 *
 *  Created on: Jun 12, 2019
 *      Author: Hamza
 */

#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_


/************************************/
/*
 * Function Desc:The function is to initialise
 * UART Peripheral
 *
 * Input Parameter : void
 * Output Parameter : void
 */

void MUART_En_Dis_INT_Global(u8 Mode);


void MUART_Set_Call_Back(void (*ptr) (void));

void MUART_voidIntit(void);


void MUART_voidSendByte(u8 Byte);

void MUART_voidSendString(u8* String);


u8 MUART_u8ReceiveByte(void);

//protoype of the the ISR function of the UART RX Complete
void __vector_13 (void)__attribute__((signal,INTR_ATTRS));

//protoype of the the ISR function of the UART DATA Register empty
//void __vector_12 (void)__attribute__((signal,INTR_ATTRS));

//protoype of the the ISR function of the UART TX Copmlete
//void __vector_13 (void)__attribute__((signal,INTR_ATTRS));
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//naming the bits of each register
//////////////////////////////////////////////////////////////////////////


//UCSRA Register bits
#define	MPCM					0
#define	U2X						1
#define	PE						2
#define	DOR						3
#define	FE						4
#define	UDRE					5
#define	TXC						6
#define	RXC						7

//UCSRB Register bits
#define	TXB8					0
#define	RXB8					1
#define	UCSZ2					2
#define	TXEN					3
#define	RXEN					4
#define	UDRIE					5
#define	TXCIE					6
#define	RXCIE					7

//UCSRC Register bits
#define	UCPOL					0
#define	UCSZ0					1
#define	UCSZ1					2
#define	USBS					3
#define	UPM0					4
#define	UPM1					5
#define	UMSEL					6
#define	URSEL					7

//macros for the global interrupt enable
#define CLR_I 					1
#define EN_I 					0

//macros for configuring the init function

#define Async_Normal			0
#define Async_Double_Speed		1
#define Sync_Mode				2

//parity values
#define Parity_Disable				0b00
#define Parity_En_Even				0b10
#define Parity_En_Odd				0b11

//data size modes
#define	Data_5_Bits				0b000
#define Data_6_Bits				0b001
#define Data_7_Bits				0b010
#define Data_8_Bits				0b011
#define Data_9_Bits				0b111






#endif /* MUART_INTERFACE_H_ */
