/*
 * MSysClock_Private.h
 *
 *  Created on: Jun 28, 2019
 *      Author: Hamza
 */

#ifndef MSYSTICK_PRIVATE_H_
#define MSYSTICK_PRIVATE_H_

//typedef struct {
//    u32 STK_CTRL	[4];            //Interrupt set-enable registers
//    u32 STK_LOAD	[4];            //Interrupt clear-enable registers
//    u32 TK_VAL		[4];            //Interrupt set-pending registers
//    u32 STK_CALIB	[4];            //Interrupt clear-pending registers
//                //Interrupt active bit registers
//
//}SysTick;
//
//
//#define MSysTick   	((volatile SysTick*)(0xE000E010))

#define STK_CTRL		*((u32*)0xE000E010)
#define STK_LOAD		*((u32*)0xE000E014)
#define TK_VAL			*((u32*)0xE000E018)
#define STK_CALIB		*((u32*)0xE000E01C)


#endif /* MSYSTICK_PRIVATE_H_ */
