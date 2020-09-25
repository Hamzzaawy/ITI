/*
 * main.c
 *
 *  Created on: Aug 14, 2019
 *      Author: Hamza
 */

#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MFLASH_Interface.h"
#include "MRCC_interface.h"
//#include "stm32f10x_flash.h"


void main (void)
{

	MRCC_voidEnPeriphClk(MRCC_U8_FLITF);
	MFLASH_voidUnlock();
	//MFLASH_voidEraseAll();
	MFLASH_voidProgram(0x0801FC00,0x0033);
	MFLASH_voidErasePage(0x0801FC00);
	MFLASH_voidProgram(0x0801FC00,0x5555);

	//FLASH_Unlock();
	//FLASH_ProgramHalfWord(0x0801FC00,0x11);
	//FLASH_ErasePage(0x0801FC00);
	//FLASH_ProgramHalfWord(0x0801FC00,0x55);

	while (1)
	{

	}

}
