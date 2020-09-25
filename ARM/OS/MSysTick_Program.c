/*
 * MSysTick_Program.c
 *
 *  Created on: Jun 28, 2019
 *      Author: Hamza
 */

#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MSycTick_interface.h"
#include "MSysTick_Private.h"


void MSysTick_voidInit(void)
{

	//choose the AHB/8 clock source
//	MSysTick->STK_CTRL[0]=Clr_Bit(MSysTick->STK_CTRL[0],CLKSOURCE);
	STK_CTRL=Set_Bit(STK_CTRL,CLKSOURCE);

	//enable the exception request on counting down to zero
	STK_CTRL=Set_Bit(STK_CTRL,TICKINT);

	//enable the SysTick counter
	STK_CTRL=Set_Bit(STK_CTRL,ENABLE);

}


void MSysTick_voidSetReloadValue(u32	copyValue)
{
//	if(copyValue < ((u32)(1<<24)))
//	{
	STK_LOAD=copyValue;
//	}
}
