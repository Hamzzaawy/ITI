/*
 * MEEPROM_Interface.h
 *
 *  Created on: Jun 27, 2019
 *      Author: Hamza
 */

#ifndef HEEPROM_INTERFACE_H_
#define HEEPROM_INTERFACE_H_

void HEEPROM_voidInit(void);

void HEEPROM_voidWriteByte(u16 Location,u8 Byte);

void HEEPROM_voidReadByte(u16 Location,u8* Data);




#endif /* HEEPROM_INTERFACE_H_ */
