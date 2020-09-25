/*
 * MWDT_Program.c
 *
 *  Created on: Jun 26, 2019
 *      Author: Hamza
 */
#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MWDT_Interface.h"
#include "MWDT_Private.h"

void MWDT_voidStartTimer(u8 Time_Out)
{
//	switch(Time_Out)
//	{
//	case Delay_16_MS 	:	MWDT_WDTCR |= Delay_16_MS;		break;
//	case Delay_32_MS 	:	MWDT_WDTCR |= Delay_32_MS;		break;
//	case Delay_65_MS 	:	MWDT_WDTCR |= Delay_65_MS;		break;
//	case Delay_130_MS 	:	MWDT_WDTCR |= Delay_130_MS;		break;
//	case Delay_260_MS 	:	MWDT_WDTCR |= Delay_260_MS;		break;
//	case Delay_520_MS 	:	MWDT_WDTCR |= Delay_520_MS;		break;
//	case Delay_1_S 		:	MWDT_WDTCR |= Delay_1_S;		break;
//	case Delay_2_S 		:	MWDT_WDTCR |= Delay_2_S;		break;
//	default:												break;
//	}

	MWDT_WDTCR=Time_Out;
	MWDT_WDTCR=Set_Bit(MWDT_WDTCR,WDE);


}
void MWDT_voidStopTimer	(void)
{
	MWDT_WDTCR  |=(1<<WDE) | (1<<WDTOE);
	MWDT_WDTCR=0;

}
void MWDT_voidRefreshTimer(void)
{
	MWDT_voidStopTimer();
	MWDT_voidStartTimer(Delay_1_S);

}

void MWDT_voidSycReset(void)
{
	//disable global interupt
	MWDT_voidStartTimer(Delay_16_MS);

}
