#ifndef HKeyPad_INTERFACE_H
#define HKeyPad_INTERFACE_H


#define C1	3
#define C2	2
#define C3	1
#define C4	0
#define R1	4
#define R2	5
#define R3	6
#define R4	7


#define PORTA	1
#define PORTB	2
#define PORTC	3
#define	PORTD	4



void HkeyPad_Init(void);

u8 HKeyPad_GetKey(void);

#endif
