/*
 * ARM_DMA_private.h
 *
 *  Created on: Jul 2, 2019
 *      Author: Hamza
 */

#ifndef ARM_DMA_PRIVATE_H_
#define ARM_DMA_PRIVATE_H_


typedef struct
{
	u32 DMA_ISR;
	u32 DMA_IFCR;
	u32 DMA_CCR1;
	u32 DMA_CNDTR1;
	u32 DMA_CPAR1;
	u32 DMA_CMAR1;
}DMA;


#define MDMA   	((volatile DMA*)(0x40020000))

//#define DMA_ISR 	*((u32*)0x40020000)
//#define DMA_IFCR 	*((u32*)0x40020004)
//#define DMA_CCR1 	*((u32*)0x40020008)
//#define DMA_CNDTR1 	*((u32*)0x4002000C)
//#define DMA_CPAR1 	*((u32*)0x40020010)
//#define DMA_CMAR1 	*((u32*)0x40020014)

#endif /* ARM_DMA_PRIVATE_H_ */
