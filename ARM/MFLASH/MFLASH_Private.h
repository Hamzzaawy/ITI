/*
 * MFLASH_Private.h
 *
 *  Created on: Aug 14, 2019
 *      Author: Hamza
 */

#ifndef MFLASH_PRIVATE_H_
#define MFLASH_PRIVATE_H_

#include "LSTR_Types.h"



typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;

}flash;


#define MFLASH  ((volatile flash*)0x40022000)


#endif /* MFLASH_PRIVATE_H_ */
