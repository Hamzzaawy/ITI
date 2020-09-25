/*
 * MSPI_Interface.h
 *
 *  Created on: Jun 16, 2019
 *      Author: Hamza
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_


#define CLR_I 					1
#define EN_I 					0

#define LSB_First		1
#define MSB_First		0


#define Leading_Rising		0
#define Leading_Falling		1

#define	Leading_Sample		0
#define Leading_Setup		1

#define Normal_Speed			0
#define Double_Speed			1

#define Clock_Rate_1			0b00
#define Clock_Rate_2			0b01
#define Clock_Rate_3			0b10
#define Clock_Rate_4			0b11

#define Data_Order			LSB_First

#define Clk_Polarity		Leading_Falling

#define Clk_Phase			Leading_Setup

#define Speed_Mode			Normal_Speed

#define Clock_Rate			Clock_Rate_4

#define DUMMY_DATA			0xAA

void MSPI_voidMasterInit(void);

void MSPI_voidSlaveInit(void);

u8 MSPI_u8TransferData(u8 Data);

void MSPI_Set_Call_Back(void (*ptr) (void));

void MSPI_En_Dis_INT_Global(u8 Mode);

void __vector_13 (void)__attribute__((signal,INTR_ATTRS));



#endif /* MSPI_INTERFACE_H_ */
