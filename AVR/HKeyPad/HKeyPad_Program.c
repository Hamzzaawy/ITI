#include"LSTR_Types.h"
#include"LUTILS.h"
#include"HKeyPad_Interface.h"
#include"HKeyPad_Private.h"
#include"MDIO_interface.h"


void HkeyPad_Init(u8 PORT)
{
	for(u8 i=0;i<8;i++)
	{
		MDIO_SetDirection(PORT,i,INPUT_PULLUP);
	}
}

u8 HKeyPad_GetKey(u8 PORT)
{

	if(MDIO_GetPinValue(PORT,C1)==0)
	{
		if(MDIO_GetPinValue(PORT,R1)==0)
		{
			return KPD[0][0];
		}
		else if(MDIO_GetPinValue(PORT,R1)==1)
		{
			return KPD[1][0];
		}
		else if(MDIO_GetPinValue(PORT,R2)==1)
		{
			return KPD[2][0];
		}
		else if(MDIO_GetPinValue(PORT,R3)==1)
		{
			return KPD[3][0];
		}
	}
	else if (MDIO_GetPinValue(PORT,C2)==0)
	{
		if(MDIO_GetPinValue(PORT,R1)==0)
		{
			return KPD[0][1];
		}
		else if(MDIO_GetPinValue(PORT,R1)==1)
		{
			return KPD[1][1];
		}
		else if(MDIO_GetPinValue(PORT,R2)==1)
		{
			return KPD[2][1];
		}
		else if(MDIO_GetPinValue(PORT,R3)==1)
		{
			return KPD[3][1];
		}
	}

	else if (MDIO_GetPinValue(PORT,C3)==0)
	{
		if(MDIO_GetPinValue(PORT,R1)==0)
		{
			return KPD[0][2];
		}
		else if(MDIO_GetPinValue(PORT,R1)==1)
		{
			return KPD[1][2];
		}
		else if(MDIO_GetPinValue(PORT,R2)==1)
		{
			return KPD[2][2];
		}
		else if(MDIO_GetPinValue(PORT,R3)==1)
		{
			return KPD[3][2];
		}
	}

	else if (MDIO_GetPinValue(PORT,C4)==0)
	{
		if(MDIO_GetPinValue(PORT,R1)==0)
		{
			return KPD[0][3];
		}
		else if(MDIO_GetPinValue(PORT,R1)==1)
		{
			return KPD[1][3];
		}
		else if(MDIO_GetPinValue(PORT,R2)==1)
		{
			return KPD[2][3];
		}
		else if(MDIO_GetPinValue(PORT,R3)==1)
		{
			return KPD[3][3];
		}
	}


}
