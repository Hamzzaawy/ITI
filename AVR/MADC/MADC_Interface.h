/*
 * MADC_Interface.h
 *
 *  Created on: Jul 7, 2019
 *      Author: Hamza
 */

#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_

void MADC_voidInit(void);

u16 MADC_u16ConvertSync(u8 copy_ChNo);

void MADC_voidConvertAsync(u8 copy_ChNo,void(*Call_Back)(u16));

u16 MADC_u16GetLastValue(copy_ChNo);

void MADC_voidSetEnableState(u8 copy_InitState);

void MADC_En_Dis_INT_Global(u8 Mode);

#define Disable			0
#define Enable			1

//macros for the global interrupt enable
#define CLR_I 					1
#define EN_I 					0


//prescaller macros

#define MADC_2_Prescaler		0b001
#define MADC_4_Prescaler		0b010
#define MADC_8_Prescaler		0b011
#define MADC_16_Prescaler		0b100
#define MADC_32_Prescaler		0b101
#define MADC_64_Prescaler		0b110
#define MADC_128_Prescaler		0b111

//single ended channel selection

#define MADC_Ch_0				0b0000
#define MADC_Ch_1				0b0001
#define MADC_Ch_2				0b0010
#define MADC_Ch_3				0b0011
#define MADC_Ch_4				0b0100
#define MADC_Ch_5				0b0101
#define MADC_Ch_6				0b0110
#define MADC_Ch_7				0b0111


// voltage reference selection

#define MADC_Ex_AREF			0b00
#define MADC_In_VCC				0b01
#define MADC_IN_REG				0b11


void __vector_16 (void)__attribute__((signal,INTR_ATTRS));


#endif /* MADC_INTERFACE_H_ */
