/*
 * main.c
 *
 *  Created on: Jul 2, 2019
 *      Author: Hamza
 */


#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MRCC_interface.h"
#include "MNVIC_interface.h"
#include "ARM_DMA_interface.h"

u8 source[1000]={0};
u8 Dest[1000];
u16 i=0;
void main (void)
{
MRCC_voidEnablePeriphClk(MRCC_U8_DMA1);

MNVIC_Set_Enable(11);

DMA_Init();


for(i=0;i<1000;i++)
{
	Dest[i]=source[i];
}


	while(1);
}


void DMA1_Channel1_IRQHandler(void)
{

}
