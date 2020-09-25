#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MRCC_interface.h"
#include "MDIO_interface.h"
#include "MNVIC_interface.h"

void main (void)
{
    MRCC_voidEnablePeriphClk(MRCC_U8_GPIOA);
   // MDIO_voidSetPinMode(DIO_U8_PIN32,DIO_U8_2M_OUT_PP);
    //MDIO_voidSetPinMode(DIO_U8_PIN3,DIO_U8_2M_OUT_PP);
    MDIO_voidSetPinMode(DIO_U8_PIN2,DIO_U8_2M_OUT_PP);
    MDIO_voidSetPinMode(DIO_U8_PIN1,DIO_U8_2M_OUT_PP);
    //MDIO_voidSetPinMode(DIO_U8_PIN0,DIO_U8_2M_OUT_PP);
    MNVIC_Set_Enable(6);
    MNVIC_Set_Enable(7);


    MNVIC_Set_Priority(6,0,0);
    MNVIC_Set_Priority(7,0,1);

    MNVIC_Set_Pending_Flag(7);
    //MNVIC_Set_Pending_Flag(6);

    while(1);
}

void EXTI0_IRQHandler(void)
{
	 MDIO_voidSetPinValue(DIO_U8_PIN1,DIO_u8_HIGH);
	 MNVIC_Set_Pending_Flag(7);
	while(1);
}

void EXTI1_IRQHandler(void)
{
	MDIO_voidSetPinValue(DIO_U8_PIN2,DIO_u8_HIGH);
	MNVIC_Set_Pending_Flag(6);

	while(1);
}
