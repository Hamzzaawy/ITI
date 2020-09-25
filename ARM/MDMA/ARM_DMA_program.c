/*
 * ARM_DMA_program.c
 *
 *  Created on: Jul 2, 2019
 *      Author: Hamza
 */

#include "LSTR_Types.h"
#include "LUTILS.h"

#include "ARM_DMA_interface.h"
#include "ARM_DMA_private.h"


u32 Source[1000]={0};
u32 Dest[1000];

void DMA_Init(void)
{
	MDMA->DMA_CNDTR1=1000;
	MDMA->DMA_CMAR1=Source;
	MDMA->DMA_CPAR1=Dest;

	MDMA->DMA_CCR1=0x00004AD3;

}
