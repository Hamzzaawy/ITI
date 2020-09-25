/*
 * main.c
 *
 *  Created on: Jun 28, 2019
 *      Author: Hamza
 */


#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MSycTick_interface.h"
#include  "MDIO_interface.h"
#include  "MRCC_interface.h"


void main (void)
{
	MRCC_voidEnablePeriphClk(MRCC_U8_GPIOC);
	MDIO_voidIntialize();

	MDIO_voidSetPinMode(DIO_U8_PIN32,DIO_U8_2M_OUT_PP);
	MDIO_voidSetPinValue(DIO_U8_PIN32,DIO_u8_HIGH);
	MSysTick_voidInit();
	MSysTick_voidSetReloadValue(16000000);
	MDIO_voidSetPinValue(DIO_U8_PIN32,DIO_u8_LOW);

	while(1);
}


void SysTick_Handler(void)
{
	static u8 flag=0;
	if(flag==0)
	{
		MDIO_voidSetPinValue(DIO_U8_PIN32,DIO_u8_HIGH);
		flag=1;
	}
	else
	{
		MDIO_voidSetPinValue(DIO_U8_PIN32,DIO_u8_LOW);
		flag=0;
	}

}






