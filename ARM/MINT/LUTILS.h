#ifndef _LUTILS_H_
#define _LUTILS_H_


#define Set_Bit(Var,BitNo)      (Var |  (1<<BitNo))
#define Clr_Bit(Var,BitNo)      (Var & ~(1<<BitNo))
#define Toggle_Bit(Var,BitNo)   (Var ^  (1<<BitNo))
#define GET_Bit(reg,bit)        ((reg >> bit)&1)


#endif
