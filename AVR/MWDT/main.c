/*
 * main.c
 *
 *  Created on: Jun 26, 2019
 *      Author: Hamza
 */


#include "LSTR_Types.h"
#include "LUTILS.h"



#include "MWDT_Interface.h"
#include "MDIO_interface.h"
#include "util/delay.h"


void main (void)
{


	MDIO_SetDirection(PORTA,0,HIGH);
	_delay_ms(1000);
	MDIO_SetPinValue(PORTA,0,HIGH);

	MWDT_voidStartTimer(Delay_1_S);


	while(1)
	{
		//MWDT_voidStopTimer();
		MWDT_voidRefreshTimer();

	}
}
