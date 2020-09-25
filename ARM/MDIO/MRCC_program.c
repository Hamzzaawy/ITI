#include"LSTR_TYPES.h"
#include"Lutils.h"

#include"MRCC_interface.h"
#include"MRCC_private.h"

void MRCC_voidEnablePeriphClk(u8 Copy_u8PeriphIdx)
{
    u8 Local_u8Bus          = Copy_u8PeriphIdx / MRCC_U8_REG_SIZE;
    u8 Local_u8Peripheral   = Copy_u8PeriphIdx % MRCC_U8_REG_SIZE;

switch (Local_u8Bus)
{
case MRCC_U8_AHB  :  MRCC_AHBENR =Set_Bit(MRCC_AHBENR,Local_u8Peripheral);      break;
case MRCC_U8_APB1 :  MRCC_APB1ENR=Set_Bit(MRCC_APB1ENR,Local_u8Peripheral);     break;
case MRCC_U8_APB2 :  MRCC_APB2ENR=Set_Bit(MRCC_APB2ENR,Local_u8Peripheral);     break;

default:    /*Report Errors*/                            break;
}


}
