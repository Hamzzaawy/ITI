/*
 * Main.c
 *
 *  Created on: Jun 11, 2019
 *      Author: Hamza
 */
#include "LSTR_Types.h"
#include "LUTILS.h"
#include"MDIO_interface.h"
#include"MRCC_interface.h"
int main(void)
	{
		MRCC_voidEnablePeriphClk(MRCC_U8_GPIOC);
		MDIO_voidIntialize();
		//MDIO_voidSetPinMode(DIO_U8_PIN32,DIO_U8_2M_OUT_PP);

	  while (1)
	    {
	       MDIO_voidSetPinValue(DIO_U8_PIN32,DIO_u8_LOW);
	       L_Delay_ms(1000);
	       MDIO_voidSetPinValue(DIO_U8_PIN32,DIO_u8_HIGH);
	       L_Delay_ms(1000);

	    }
	}


