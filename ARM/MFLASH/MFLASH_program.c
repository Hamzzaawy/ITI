/*
 * MFLASH_program.c
 *
 *  Created on: Aug 14, 2019
 *      Author: Hamza
 */
#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MFLASH_Interface.h"
#include "MFLASH_Private.h"


void MFLASH_voidUnlock(void)
{

	MFLASH->KEYR=KEY_1;
	MFLASH->KEYR=KEY_2;
}

void MFLASH_voidErasePage(u32 Add)
{
	while(GET_Bit(MFLASH->SR,BSY));

	MFLASH->CR=Set_Bit(MFLASH->CR,PER);

	MFLASH->AR=Add;

	MFLASH->CR=Set_Bit(MFLASH->CR,STRT);

	while(GET_Bit(MFLASH->SR,BSY));

	MFLASH->CR=Clr_Bit(MFLASH->CR,PER);
	//check for erasing and report back

}

void MFLASH_voidEraseAll(void)
{

	while(GET_Bit(MFLASH->SR,BSY));

	MFLASH->CR=Set_Bit(MFLASH->CR,MER);

	MFLASH->CR=Set_Bit(MFLASH->CR,STRT);

	while(GET_Bit(MFLASH->SR,BSY));



	//check for the erasing and report back

}

void MFLASH_voidProgram(u32 Add,u16 Data)
{

	while(GET_Bit(MFLASH->SR,BSY));

	MFLASH->CR=Set_Bit(MFLASH->CR,PG);

	MFLASH->AR=Add;

	*(u16*)Add=Data;


	while(GET_Bit(MFLASH->SR,BSY));

	MFLASH->CR=Clr_Bit(MFLASH->CR,PG);

	//check for the written data in the address



}

