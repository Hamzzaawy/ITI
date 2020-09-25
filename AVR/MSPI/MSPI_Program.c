/*
 * MSPI_Program.c
 *
 *  Created on: Jun 16, 2019
 *      Author: Hamza
 */

#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MSPI_Interface.h"
#include "MSPI_Private.h"

void (*Pointer)(void);


void MSPI_En_Dis_INT_Global(u8 Mode)
{
	switch(Mode)
	{
		case CLR_I:		MSPI_SREG=Clr_Bit(MSPI_SREG,7);			break;
		case EN_I:		MSPI_SREG=Set_Bit(MSPI_SREG,7);			break;
	}

}

void MSPI_voidMasterInit(void)
{

	MSPI_SPCR=Set_Bit(MSPI_SPCR,SPE);

#if Data_Order == LSB_First
	MSPI_SPCR=Clr_Bit(MSPI_SPCR,DORD);
#else
	MSPI_SPCR=Set_Bit(MSPI_SPCR,DORD);
#endif


	MSPI_SPCR=Set_Bit(MSPI_SPCR,MSTR);


#if Clk_Polarity == Leading_Rising
	MSPI_SPCR=Clr_Bit(MSPI_SPCR,CPOL);
#else
	MSPI_SPCR=Set_Bit(MSPI_SPCR,CPOL);
#endif

#if Clk_Phase==Leading_Sample
	MSPI_SPCR=Clr_Bit(MSPI_SPCR,CPHA);
#else
	MSPI_SPCR=Set_Bit(MSPI_SPCR,CPHA);
#endif

#if Speed_Mode == Normal_Speed
	MSPI_SPSR=Clr_Bit(MSPI_SPSR,SPI2X);
#else
	MSPI_SPSR=Set_Bit(MSPI_SPSR,SPI2X);
#endif


#if 		Clock_Rate == Clock_Rate_1
		MSPI_SPCR &= ~(0b11);
		MSPI_SPCR |=  (Clock_Rate_1);
#elif 	Clock_Rate == Clock_Rate_2
		MSPI_SPCR &= ~(0b11);
		MSPI_SPCR |=  (Clock_Rate_2);
#elif 	Clock_Rate == Clock_Rate_3
		MSPI_SPCR &= ~(0b11);
		MSPI_SPCR |=  (Clock_Rate_3);
#else
		MSPI_SPCR &= ~(0b11);
		MSPI_SPCR |=  (Clock_Rate_4);
#endif

	//MSPI_SPCR=Set_Bit(MSPI_SPCR,SPR1);
	//MSPI_SPCR=Set_Bit(MSPI_SPCR,SPR0);


}

void MSPI_voidSlaveInit(void)
{
	MSPI_SPCR=Set_Bit(MSPI_SPCR,SPE);

#if Data_Order == LSB_First
	MSPI_SPCR=Clr_Bit(MSPI_SPCR,DORD);
#else
	MSPI_SPCR=Set_Bit(MSPI_SPCR,DORD);
#endif


	MSPI_SPCR=Clr_Bit(MSPI_SPCR,MSTR);


#if Clk_Polarity == Leading_Rising
	MSPI_SPCR=Clr_Bit(MSPI_SPCR,CPOL);
#else
	MSPI_SPCR=Set_Bit(MSPI_SPCR,CPOL);
#endif

#if Clk_Phase==Leading_Sample
	MSPI_SPCR=Clr_Bit(MSPI_SPCR,CPHA);
#else
	MSPI_SPCR=Set_Bit(MSPI_SPCR,CPHA);
#endif

#if Speed_Mode == Normal_Speed
	MSPI_SPSR=Clr_Bit(MSPI_SPSR,SPI2X);
#else
	MSPI_SPSR=Set_Bit(MSPI_SPSR,SPI2X);
#endif


#if 		Clock_Rate == Clock_Rate_1
		MSPI_SPCR &= ~(0b11);
		MSPI_SPCR |=  (Clock_Rate_1);
#elif 	Clock_Rate == Clock_Rate_2
		MSPI_SPCR &= ~(0b11);
		MSPI_SPCR |=  (Clock_Rate_2);
#elif 	Clock_Rate == Clock_Rate_3
		MSPI_SPCR &= ~(0b11);
		MSPI_SPCR |=  (Clock_Rate_3);
#else
		MSPI_SPCR &= ~(0b11);
		MSPI_SPCR |=  (Clock_Rate_4);
#endif

}

void MSPI_Set_Call_Back(void (*ptr) (void))
{

	Pointer=ptr;
}


u8 MSPI_u8TransferData(u8 Data)
{
	MSPI_SPDR=Data;

	while(GET_Bit(MSPI_SPSR,SPIF)==0);

	return MSPI_SPDR;

}


void __vector_13(void)
{
	Pointer();
}
