/*
 * MFLASH_Interface.h
 *
 *  Created on: Aug 14, 2019
 *      Author: Hamza
 */

#ifndef MFLASH_INTERFACE_H_
#define MFLASH_INTERFACE_H_


//unlocking keys

#define KEY_1	 0x45670123
#define KEY_2	 0xCDEF89AB


//status register bits
#define EOP			5
#define WRPRTERR	4
#define PGERR		2
#define BSY			0


//control register bits
#define EOPIE		12
#define ERRIE		10
#define OPTWRE		9
#define LOCK		7
#define STRT		6
#define OPTER		5
#define OPTPG		4
#define MER			2
#define PER			1
#define PG			0


void MFLASH_voidUnlock(void);

void MFLASH_voidErasePage(u32 Add);

void MFLASH_voidEraseAll(void);

void MFLASH_voidProgram(u32 Add,u16 Data);



#endif /* MFLASH_INTERFACE_H_ */
