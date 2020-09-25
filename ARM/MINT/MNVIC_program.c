#include"LSTR_TYPES.h"
#include"Lutils.h"

#include"MNVIC_interface.h"
#include"MNVIC_private.h"



void MNVIC_Set_Enable(u8 ID)
{
    if (ID<=31)
    {
        MNVIC->ISER[0]=(1<< ID);
    }
    else if (ID<=63)
    {
        ID=ID-32;
        MNVIC->ISER[1]=(1<< ID);  
    }
    else
    {
        ID=ID-64;
        MNVIC->ISER[2]=(1<< ID);  
    }
}
void MNVIC_Clr_Enable(u8 ID)
{
    if (ID<=31)
    {
        MNVIC->ICER[0]=(1<< ID);
    }
    else if (ID<=63)
    {
        ID=ID-32;
        MNVIC->ICER[1]=(1<< ID);  
    }
    else
    {
        ID=ID-64;
        MNVIC->ICER[2]=(1<< ID);  
    }
}
void MNVIC_Set_Pending_Flag(u8 ID)
{
    if (ID<=31)
    {
        MNVIC->ISPR[0]=(1<< ID);
    }
    else if (ID<=63)
    {
        ID=ID-32;
        MNVIC->ISPR[1]=(1<< ID);  
    }
    else
    {
        ID=ID-64;
        MNVIC->ISPR[2]=(1<< ID);  
    }
}
void MNVIC_CLr_Pending_Flag(u8 ID)
{
    if (ID<=31)
    {
        MNVIC->ICPR[0]=(1<< ID);
    }
    else if (ID<=63)
    {
        ID=ID-32;
        MNVIC->ICPR[1]=(1<< ID);  
    }
    else
    {
        ID=ID-64;
        MNVIC->ICPR[2]=(1<< ID);  
    }
}

void MNVIC_Set_Priority(u8 ID,u8 Group_Priority,u8 Sup_Priority)
{
	u8 Register_no=ID/4;
	u8 offset_In_Register=ID%4;

	MNVIC_IPR[Register_no] &= ~(0b1111 << offset_In_Register);

	//u8 temp1=(Group_Priority <<2);

	//u8 temp2 =(( temp1 | Sup_Priority) );

	MNVIC_IPR[Register_no] |=  (  (  (( (Group_Priority <<Group_Shift_To_Higher_2_Bits) | Sup_Priority) )  << ((offset_In_Register*INT_Bit_Size_In_IPR)+4))  );

}


