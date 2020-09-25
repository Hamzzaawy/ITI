#ifndef _MDIO_PRIVATE_H
#define _MDIO_PRIVATE_H

#define GPIOA_CRL	*((u32*)0x40010800)
#define GPIOA_CRH	*((u32*)0x40010804)
#define GPIOA_IDR	*((u32*)0x40010808)
#define GPIOA_ODR	*((u32*)0x4001080C)


#define GPIOB_CRL	*((u32*)0x40010C00)
#define GPIOB_CRH	*((u32*)0x40010C04)
#define GPIOB_IDR	*((u32*)0x40010C08)
#define GPIOB_ODR	*((u32*)0x40010C0C)


#define GPIOC_CRL	*((u32*)0x40011000)
#define GPIOC_CRH	*((u32*)0x40011004)
#define GPIOC_IDR	*((u32*)0x40011008)
#define GPIOC_ODR	*((u32*)0x4001100C)


#define DIO_U8_PORT_SIZE		16

#define DIO_U8_PORTA			0
#define DIO_U8_PORTB			1
#define DIO_U8_PORTC			2
/*

typedef struct {
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSR;
	u32 BRR;
	u32 LCK;
}GPIO;


#define GPIOA ((volatile GPIO*)(0x40010800))
#define GPIOB ((volatile GPIO*)(0x40010C00))
#define GPIOC ((volatile GPIO*)(0x40011000))
*/
#endif
