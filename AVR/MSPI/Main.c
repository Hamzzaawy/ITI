/*
 * Main.c
 *
 *  Created on: Jun 16, 2019
 *      Author: Hamza
 */

#include "LSTR_Types.h"
#include "LUTILS.h"
#include "MDIO_interface.h"
#include "MSPI_Interface.h"
#include "util/delay.h"



void func (void);

void main (void)
{

	MSPI_En_Dis_INT_Global(CLR_I);

	MSPI_Set_Call_Back(func);
	/*
	//master config
	MDIO_SetDirection(PORTB,4,OUTPUT);
	MDIO_SetDirection(PORTB,5,OUTPUT);
	MDIO_SetDirection(PORTB,6,INPUT_FLOAT);
	MDIO_SetDirection(PORTB,7,OUTPUT);
	MDIO_SetPinValue(PORTB,4,LOW);
	*/
	//slave config

	MDIO_SetDirection(PORTB,4,INPUT_PULLUP);
	MDIO_SetDirection(PORTB,5,INPUT_FLOAT);
	MDIO_SetDirection(PORTB,6,OUTPUT);
	MDIO_SetDirection(PORTB,7,INPUT_FLOAT);


	MDIO_SetDirection(PORTA,0,OUTPUT);
	MDIO_SetDirection(PORTA,1,OUTPUT);
	//MDIO_SetPinValue(PORTB,4,LOW);


	MSPI_voidSlaveInit();
	//MSPI_voidMasterInit();
	u8 data=0;
	while(1)
	{
		/*
		data=MSPI_u8TransferData('A');
		_delay_ms(1000);
		data=MSPI_u8TransferData('B');
		_delay_ms(1000);
		*/

		data=MSPI_u8TransferData(DUMMY_DATA);
		if(data == 'A')
		{
			MDIO_SetPinValue(PORTA,0,HIGH);
			MDIO_SetPinValue(PORTA,1,LOW);
		}
		else if(data=='B')
		{
			MDIO_SetPinValue(PORTA,0,LOW);
			MDIO_SetPinValue(PORTA,1,HIGH);
		}


	}
}

void func (void){

}
