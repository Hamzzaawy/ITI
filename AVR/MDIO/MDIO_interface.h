
//multiple inclusion guard
#ifndef MDIO_INTERFACE_H
#define MDIO_INTERFACE_H

// including utilities header and custom named data types header
#include "LUTILS.h"
#include "LSTR_Types.h"


// organizing difinations 
#define PORTA	1
#define PORTB	2
#define PORTC	3
#define	PORTD	4

#define HIGH 1
#define LOW  0

#define OUTPUT 			1
#define INPUT_FLOAT		2
#define	INPUT_PULLUP	3


// functions prototypes 

//set direction of specific pin
void MDIO_SetDirection(u8 PORT,u8 Bit,u8 Status);

// setting a value for the hole port
void MDIO_SetPortValue(u8 PORT,u8 Value);

// setting a value for a specific pin
void MDIO_SetPinValue(u8 PORT,u8 Bit,u8 Value);

// reading the value of the hole port
u8 MDIO_GetPortValue (u8 PORT);

// reading the value of a specific pin
u8 MDIO_GetPinValue(u8 PORT,u8 Bit);




#endif
