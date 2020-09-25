/*
 * main.c
 *
 *  Created on: Jun 12, 2019
 *      Author: Hamza
 */

#include "LSTR_Types.h"
#include "LUTILS.h"
#include "MDIO_interface.h"
#include "MUART_Interface.h"
#include "MUART_Private.h"
#include "util/delay.h"

void func(void);


u8 data[10]={0};
u32 number =10050;

void main (void){

	MUART_En_Dis_INT_Global(EN_I);
	MUART_Set_Call_Back(func);
	MUART_voidIntit();
	MDIO_SetDirection(PORTA,0,OUTPUT);
	MDIO_SetDirection(PORTA,1,OUTPUT);
	ltoa(number,data,10);
	MUART_voidSendString(data);
	while(1)
	{
		//MUART_voidSendString("Hamza");
		//_delay_ms(1000);
		MUART_voidSendByte('Z');
		_delay_ms(1000);
//		MUART_voidSendByte('C');
//		_delay_ms(1000);

//		if(MUART_u8ReceiveByte()=='A')
//			MDIO_SetPinValue(PORTA,0,HIGH);
//		else
//			MDIO_SetPinValue(PORTA,0,LOW);
	}
}

void func (void)
{
	MDIO_SetPinValue(PORTA,0,HIGH);

}
