#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

#include "LUTILS.h"
#include "LSTR_Types.h"


#define PORTA	1
#define PORTB	2
#define PORTC	3
#define	PORTD	4



void HLCD_Init_LCD (void);

void HLCD_Write_Commmand(u8 Command);

void HLCD_Write_Data(u8 Data);

void HLCD_Write_String(u8* String,u8 size);

void HLCCD_SetCursor(u8 Row,u8 Col);

void HLCD_Clear(void);

void HLCD_Shift_SC(u8 number,u8 dir);

void HLCD_Shift_CR(u8 number,u8 dir);

void HLCD_2line(void);

void HLCD_Cre_Cus(void);



#endif
