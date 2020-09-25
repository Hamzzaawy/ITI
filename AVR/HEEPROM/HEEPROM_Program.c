/*
 * MEEPROM_Program.c
 *
 *  Created on: Jun 27, 2019
 *      Author: Hamza
 */
#include "LSTR_Types.h"
#include "LUTILS.h"

#include "HEEPROM_Interface.h"
#include "MI2C_Interface.h"



void HEEPROM_voidInit(void)
{
	MI2C_voidInit();

}

void HEEPROM_voidWriteByte(u16 Location,u8 Byte)
{
	u8 Loc=(u8)Location;
	u8 SLA=(0b01010000) | ((Location&0x0300)>> 8);

	MI2C_voidStartCondition();
	if(MI2C_u8CheckStatus(0x08)==0)
	{
		return;
	}

	MI2C_voidSendSlaveAddress(SLA,0);
	if(MI2C_u8CheckStatus(0x18)==0)
	{
		return;
	}

	MI2C_voidSendData(Loc);
	if(MI2C_u8CheckStatus(0x28)==0)
	{
		return;
	}

	MI2C_voidSendData(Byte);
	if(MI2C_u8CheckStatus(0x28)==0)
	{
		return;
	}

	MI2C_voidStopCondtion();
}

void HEEPROM_voidReadByte(u16 Location,u8* Data)
{
	u8 Loc=(u8)Location;
	u8 SLA=(0b01010000) | ((Location&0x0300)>> 8);

	MI2C_voidStartCondition();
	if(MI2C_u8CheckStatus(0x08)==0)
	{
		return;
	}

	MI2C_voidSendSlaveAddress(SLA,0);
	if(MI2C_u8CheckStatus(0x18)==0)
	{
		return;
	}

	MI2C_voidSendData(Loc);
	if(MI2C_u8CheckStatus(0x28)==0)
	{
		return;
	}

	MI2C_voidStartCondition();
	if(MI2C_u8CheckStatus(0x10)==0)
	{
		return;
	}

	MI2C_voidSendSlaveAddress(SLA,1);
	if(MI2C_u8CheckStatus(0x40)==0)
	{
		return;
	}

	*Data=MI2C_u8ReceiveDataWithNoAck();


	MI2C_voidStopCondtion();
}
