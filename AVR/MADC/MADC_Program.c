/*
 * MADC_Program.c
 *
 *  Created on: Jul 7, 2019
 *      Author: Hamza
 */

#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MADC_Interface.h"
#include "MADC_Private.h"
#include "MADC_Config.h"
#include "MDIO_interface.h"


void (*PTR)(u16);



void MADC_En_Dis_INT_Global(u8 Mode)
{
	switch(Mode)
	{
		case CLR_I:		MADC_SREG=Clr_Bit(MADC_SREG,7);			break;
		case EN_I:		MADC_SREG=Set_Bit(MADC_SREG,7);			break;
	}

}

void MADC_voidInit(void)
{
	//enable the ADC peripheral
	MADC_ADCSRA=Set_Bit(MADC_ADCSRA,ADEN);

	//selecting prescaller value
	MADC_ADCSRA=Set_Bit(MADC_ADCSRA,ADPS2);
	MADC_ADCSRA=Clr_Bit(MADC_ADCSRA,ADPS1);
	MADC_ADCSRA=Clr_Bit(MADC_ADCSRA,ADPS0);

	//selecting reference voltage
	MADC_ADMUX=Set_Bit(MADC_ADMUX,REFS0);
	MADC_ADMUX=Clr_Bit(MADC_ADMUX,REFS1);

	//Disable Left adjustment
	MADC_ADMUX=Clr_Bit(MADC_ADMUX,ADLAR);


}

u16 MADC_u16ConvertSync(u8 copy_ChNo)
{
	MADC_ADMUX &= ~(0b00011111);
	MADC_ADMUX |= copy_ChNo;
	MADC_ADCSRA=Set_Bit(MADC_ADCSRA,ADSC);
	while(GET_Bit(MADC_ADCSRA,ADSC));
	return MADC_ADC;

}

void MADC_voidConvertAsync(u8 copy_ChNo,void(*Call_Back)(u16))
{
	MADC_ADMUX &= ~(0b00011111);
	MADC_ADMUX |= copy_ChNo;

	PTR=Call_Back;

	MADC_ADCSRA=Set_Bit(MADC_ADCSRA,ADIE);

	MADC_ADCSRA=Set_Bit(MADC_ADCSRA,ADSC);



}

u16 MADC_u16GetLastValue(copy_ChNo)
{
	return MADC_ADC;


}

//void MADC_voidSetEnableState(u8 copy_InitState)
//{
//
//
//}

void __vector_16 (void)
{
	//MDIO_SetPinValue(PORTC,2,HIGH);
	PTR(MADC_ADC);
	MADC_ADCSRA=Set_Bit(MADC_ADCSRA,ADSC);

}
