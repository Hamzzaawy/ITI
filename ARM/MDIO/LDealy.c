#include"LSTR_Types.h"
#include"LUTILS.h"
/////////////////////////////////////////////////////////////
#define T_CALCULATIONS_TIME     696
#define T_CONTEXTSWITCHING      1710
#define T_ONELOOP_TIME          130
/////////////////////////////////////////////////////////////
void L_Delay_ms(u64 Copy_u64ValueMS)
{
	//Copy_u64ValueMS=1000;
    u64 i=0;
    u64 Local_u64_NoLoops=0;
    u64 Local_u64NewValue=0;
    Local_u64NewValue=(Copy_u64ValueMS*1000000)-(T_CALCULATIONS_TIME+T_CONTEXTSWITCHING);
    Local_u64_NoLoops=(u32)Local_u64NewValue/T_ONELOOP_TIME;
    for(i=0;i<Local_u64_NoLoops;i++)
    {
        asm("NOP");
    }
    return;
}
