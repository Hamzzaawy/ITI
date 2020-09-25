/*
 * main.c
 *
 *  Created on: Jul 14, 2019
 *      Author: Hamza
 */

#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MRCC_interface.h"
#include "MSycTick_interface.h"
#include "MDIO_interface.h"

void Toggle_1(void);
void Toggle_2(void);

void main(void)
{


	MRCC_voidInit();
	MRCC_voidEnPeriphClk(MRCC_U8_GPIOA);
	MSysTick_voidInit();
	MSysTick_voidSetReloadValue(4000000);
	MDIO_voidSetPinMode(MDIO_PORTA,MDIO_PIN_0,MDIO_MODE_OUTPUT_PUSHPULL_2);
	MDIO_voidSetPinMode(MDIO_PORTA,MDIO_PIN_1,MDIO_MODE_OUTPUT_PUSHPULL_2);

	CreateTask(Toggle_1,1,0);
	CreateTask(Toggle_2,2,1);


	while(1);
}

void Toggle_1(void)
{
	static u8 i=0;
	if(i==0)
	{
		MDIO_voidSetPinValue(MDIO_PORTA,MDIO_PIN_0,DIO_U8_HIGH);
		i=1;
	}
	else
	{
		MDIO_voidSetPinValue(MDIO_PORTA,MDIO_PIN_0,DIO_U8_LOW);
		i=0;
	}
}
void Toggle_2(void)
{
	static u8 i=0;
	if(i==0)
	{
		MDIO_voidSetPinValue(MDIO_PORTA,MDIO_PIN_1,DIO_U8_HIGH);
		i=1;
	}
	else
	{
		MDIO_voidSetPinValue(MDIO_PORTA,MDIO_PIN_1,DIO_U8_LOW);
		i=0;
	}
}

void SysTick_Handler(void)
{

	Scheduler();
}
