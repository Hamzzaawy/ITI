#ifndef _MDIO_INTERFACE_H
#define _MDIO_INTERFACE_H



void MDIO_voidIntialize (void);
void MDIO_voidSetPinValue(u8 Copy_u8PinNo,u8 Copy_u8PinVal);
void MDIO_voidGetPinValue(u8 Copy_u8PinNo,u8 *Copy_u8PinVal);
void MDIO_voidSetPinMode (u8 Copy_u8pinNo,u8 Copy_PinMode);


#define DIO_U8_PIN0         0
#define DIO_U8_PIN1         1
#define DIO_U8_PIN2         2
#define DIO_U8_PIN3         3
#define DIO_U8_PIN4         4
#define DIO_U8_PIN5         5
#define DIO_U8_PIN6         6
#define DIO_U8_PIN7         7
#define DIO_U8_PIN8         8
#define DIO_U8_PIN9         9
#define DIO_U8_PIN10        10
#define DIO_U8_PIN11        11
#define DIO_U8_PIN12        12
#define DIO_U8_PIN13        13
#define DIO_U8_PIN14        14
#define DIO_U8_PIN15        15
#define DIO_U8_PIN16        16
#define DIO_U8_PIN17        17
#define DIO_U8_PIN18        18
#define DIO_U8_PIN19        19
#define DIO_U8_PIN20        20
#define DIO_U8_PIN21        21
#define DIO_U8_PIN22        22
#define DIO_U8_PIN23        23
#define DIO_U8_PIN24        24
#define DIO_U8_PIN25        25
#define DIO_U8_PIN26        26
#define DIO_U8_PIN27        27
#define DIO_U8_PIN28        28
#define DIO_U8_PIN29        29
#define DIO_U8_PIN30        30
#define DIO_U8_PIN31        31
#define DIO_U8_PIN32        45
#define DIO_U8_PIN33        46
#define DIO_U8_PIN34        47

#define DIO_u8_LOW  0
#define DIO_u8_HIGH 1




#define PORTA 0
#define PORTB 1
#define PORTC 2

#define DIO_U8_2M_OUT_PP		0b0010
#define DIO_U8_10M_OUT_PP		1
#define DIO_U8_50M_OUT_PP		2
#define DIO_U8_2M_OUT_AF		3
#define DIO_U8_10M_OUT_AF		4
#define DIO_U8_50M_OUT_AF		5
#define DIO_U8_2M_OUT_OD		6
#define DIO_U8_10M_OUT_OD		7
#define DIO_U8_50M_OUT_OD		8
#define DIO_U8_INPUT_ANALOG		9
#define DIO_U8_INPUT_FLOAT		10
#define DIO_U8_INPUT_PULLUP		11
#define DIO_U8_INPUT_PULLDOWN	12










#define INPUT_FLOAT           12
#define INPUT_ANALOG          13







#endif
