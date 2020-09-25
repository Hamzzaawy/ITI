#ifndef MTIMER_INTERFACE_H
#define MTIMER_INTERFACE_H



//prescaling parameters
#define Timer_OFF			        0b000

#define Timer_ON_Pre_0              0b001
#define Timer_ON_Pre_8              0b010
#define Timer_ON_Pre_64             0b011
#define Timer_ON_Pre_256            0b100
#define Timer_ON_Pre_1024           0b101

#define Prescaler_Value				8

#define Max_Timer_0_Count				256
#define Max_Timer_1_Count				65536

#define Disable_Timer				0
#define Enable_Timer				1

#define Inverted_Mode					0
#define NON_Inverted_Mode				1

#define Disable_OF_Interrupt		0
#define Enable_OF_Interrupt			1

#define Disable_OC_Interrupt		0
#define Enable_OC_Interrupt			1

#define Disable_ICU_Interrupt			0
#define Enable_ICU_Interrupt			1

//mode parameters
#define Normal_Mode             0b00000000
#define Clear_On_Compare        0b00001000
#define PWM_Phase_Correct       0b01000000
#define PWM_Fast                0b01001000

//mode parameters for timer1
#define	TIM1_Normal_Mode			0b0000
#define	TIM1_CTC_Mode				0b0100
#define	TIM1_Fast_PWM_Mode			0b1110


#define TIM1_Disable_OF_Interrupt	0
#define TIM1_Enable_OF_Interrupt	1

#define TIM1_Disable_OC_Interrupt	0
#define TIM1_Enable_OC_Interrupt	1



#define CLR_I 					1
#define EN_I 					0

#define TIMER_0					0
#define TIMER_1					1

#define UINT_SEC				0
#define UINT_MIL				1
#define UINT_MICRO				2


void MTIM_En_Dis_INT_Global(u8 Mode);

void MTIM_voidInit(u8 Timer);

void MTIM_voidEnable(u8 Timer);

void MTIM_voidDisable(u8 Timer);

void MTIM_voidSetOCR(u8 Timer,u16 OCR,u64 Time_s,u8 uint);

void MTIM_voidSetDesiredTime(u8 Timer,u64 Time_s,u8 uint);

void MTIM_voidSetPWM(u8 Timer,u8 Mode,u8 Duty_Cycle,u16 Period,u8 unit);

void MTIM_voidSetCallBack(void (*ptr)(void));

//TIMER0 OVF
void __vector_11 (void)__attribute__((signal,INTR_ATTRS));

//TIMER0 COMP
void __vector_10 (void)__attribute__((signal,INTR_ATTRS));

//TIMER1 OVF
void __vector_9 (void)__attribute__((signal,INTR_ATTRS));

//TIMER1 COMPA
void __vector_7 (void)__attribute__((signal,INTR_ATTRS));

//TIMER1 CAPT
void __vector_6 (void)__attribute__((signal,INTR_ATTRS));

#endif
