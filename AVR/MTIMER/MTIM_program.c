#include "LSTR_Types.h"
#include "LUTILS.h"
#include "LSTRING_UTILS.h"

#include "MDIO_interface.h"
#include "MDIO_private.h"
#include "MTIM_interface.h"
#include "MTIM_private.h"
#include "MTIM_Config.h"
#include "MUART_Interface.h"
#include "util/delay.h"

u8 data[10]={0};

u64 TIM0_Over_Flow_no	= 0;
u64	TIM0_Preload_Value	= 0;

u64 TIM1_Over_Flow_no	= 0;
u64	TIM1_Preload_Value	= 0;



void (*Pointer)(void);



void MTIM_En_Dis_INT_Global(u8 Mode)
{
	switch(Mode)
	{
	case CLR_I:
		MTIM_SREG=Clr_Bit(MTIM_SREG,7);
		break;
	case EN_I:
		MTIM_SREG=Set_Bit(MTIM_SREG,7);
		break;
	}

}


void MTIM_voidInit(u8 Timer)
{

	switch(Timer)
	{
	case TIMER_0:

		//Timer Mode
		MTIM0_TCCR0 &=	~((1<<WGM00)|(1<<WGM01));
		MTIM0_TCCR0 |= 	TIM0_Operation_Mode;

		//Intial State
	#if Intial_State  ==  0
		MTIM0_TCCR0 &= ~(0b111);
		MTIM0_TCCR0 |= Timer_OFF;
	#else
		MTIM0_TCCR0 &= ~(0b111);
		MTIM0_TCCR0 |= TIM0_Operation_State;
	#endif

		//overflow interrupt enabling/disabling
	#if TIM0_OF_Interrupt_State  ==  0
		MTIM_IMSK=Clr_Bit(MTIM_IMSK,TOIE0);
	#else
		MTIM_IMSK=Set_Bit(MTIM_IMSK,TOIE0);
	#endif
		//compare match interrupt enabling/disabling
	#if TIM0_OC_Interrupt_State  ==  0
		MTIM_IMSK=Clr_Bit(MTIM_IMSK,OCIE0);
	#else
		MTIM_IMSK=Set_Bit(MTIM_IMSK,OCIE0);
	#endif

		break;

	case TIMER_1:

		//Timer Mode

		MTIM1_TCCR1A	&=	~(0b11);
		MTIM1_TCCR1A	|=	((TIM1_Operation_Mode << 6)>>6);//shift left 6 times and right back 6 times to get rid of WGM13 and WGN12
		MTIM1_TCCR1B	&=	~((0b11)<<3);
		MTIM1_TCCR1B	|=	((TIM1_Operation_Mode >> 2)<<3);//shifting right 2 and then left 3 to get rid of the lower bits

		//Intial State
	#if TIM1_Intial_State  ==  0
		MTIM1_TCCR1B &= ~(0b111);
		MTIM1_TCCR1B |= Timer_OFF;
	#else
		MTIM1_TCCR1B &= ~(0b111);
		MTIM1_TCCR1B |= TIM1_Operation_State;
	#endif

		//overflow interrupt enabling/disabling
	#if TIM1_OF_Interrupt_State  ==  TIM1_Disable_OF_Interrupt
		MTIM_IMSK=Clr_Bit(MTIM_IMSK,TOIE1);
	#else
		MTIM_IMSK=Set_Bit(MTIM_IMSK,TOIE1);
	#endif



		//compare A match interrupt enabling/disabling
	#if TIM1_OC_A_Interrupt_State  ==  TIM1_Disable_OC_Interrupt
		MTIM_IMSK=Clr_Bit(MTIM_IMSK,OCIE1A);
	#else
		MTIM_IMSK=Set_Bit(MTIM_IMSK,OCIE1A);
	#endif


		//compare B match interrupt enabling/disabling
	#if TIM1_OC_B_Interrupt_State  ==  0
		MTIM_IMSK=Clr_Bit(MTIM_IMSK,OCIE1B);
	#else
		MTIM_IMSK=Set_Bit(MTIM_IMSK,OCIE1B);
	#endif


		//INPUT CAPTURE  interrupt enabling/disabling
	#if TIM1_ICU_Interrupt_State  ==  Disable_ICU_Interrupt
		MTIM_IMSK=Clr_Bit(MTIM_IMSK,TICIE1);
	#else
		MTIM_IMSK=Set_Bit(MTIM_IMSK,TICIE1);
	#endif
		break;
	}
}


void MTIM_voidEnable(u8 Timer)
{
	switch(Timer)
	{
	case TIMER_0:	MTIM0_TCCR0  |= TIM0_Operation_State; 		break;
	case TIMER_1:	MTIM1_TCCR1B |= TIM1_Operation_State; 		break;
	default :		/*report error*/							break;
	}
}

void MTIM_voidDisable(u8 Timer)
{
	switch(Timer)
	{
	case TIMER_0:	MTIM0_TCCR0  |= Timer_OFF; 					break;
	case TIMER_1:	MTIM1_TCCR1B |= Timer_OFF; 					break;
	default :		/*report error*/							break;
	}
}

void MTIM_voidSetOCR(u8 Timer,u16 OCR,u64 Time_s,u8 uint)
{
	u64 UINT=0,Temp=0;
	switch(uint)
	{
	case UINT_SEC  :	UINT=1;				break;
	case UINT_MIL  :	UINT=1000;			break;
	case UINT_MICRO:	UINT=1000000;		break;
	default:								break;
	}
	switch(Timer)
	{
	case TIMER_0:
					TIM0_Over_Flow_no		=(	Time_s	*	(u64) System_Clock	)	/	(  UINT *	(u32) Prescaler_Value	*		OCR) ;
					Temp=(((Time_s	*(u64)	System_Clock)/(UINT		*(u32)	Prescaler_Value))	% OCR);
					if (Temp>0)
					{
						TIM0_Over_Flow_no++;
						TIM0_Preload_Value	=	OCR	-	Temp;
					}
					else
					{
						TIM0_Preload_Value=0;
					}
					MTIM0_OCR0=OCR;

					break;
	case TIMER_1 :
					TIM1_Over_Flow_no		=(	Time_s	*	(u64) System_Clock	)	/	(  UINT *	(u32) Prescaler_Value	*		OCR) ;
					Temp=(((Time_s	*(u64)	System_Clock)/(UINT		*	Prescaler_Value))	% OCR);
					if(Temp>0)
					{
						TIM1_Over_Flow_no++;
						TIM1_Preload_Value	=	OCR	-	Temp;
					}
					else
					{
						TIM1_Preload_Value=0;
					}
					MTIM1_OCR1A=OCR;

					break;
	default :		/*report error*/							break;
	}

}

void MTIM_voidSetDesiredTime(u8 Timer,u64 Time_s,u8 uint)

{
	u64 Temp=0, UINT;
	switch(uint)
	{
	case UINT_SEC  :	UINT=1;				break;
	case UINT_MIL  :	UINT=1000;			break;
	case UINT_MICRO:	UINT=1000000;		break;
	default:								break;
	}
	switch(Timer)
	{
	//problem with timer 0 in generating delays with micro seconds because of the calculations of the overflow counts and the preload value
	case TIMER_0:
					TIM0_Over_Flow_no=(	Time_s	*	(u64) System_Clock	)	/	(  UINT*	(u32) Prescaler_Value	*		Max_Timer_0_Count);
					Temp= (((Time_s	*(u64)	System_Clock)/( UINT * (u32)Prescaler_Value))	% Max_Timer_0_Count);
					if(Temp>0)
					{
						TIM0_Over_Flow_no++;
						TIM0_Preload_Value		= Max_Timer_0_Count - Temp	;
					}
					else
					{
						TIM0_Preload_Value		= 0	;
					}
					MTIM0_TCNT0=TIM0_Preload_Value;
					break;
	case TIMER_1 :
					TIM1_Over_Flow_no = (	Time_s	*	(u64) System_Clock	)	/	(  UINT *	(u32) Prescaler_Value	*		Max_Timer_1_Count);
					Temp=(((Time_s	*(u64)	System_Clock)/(UINT		*	(u32)Prescaler_Value))	% Max_Timer_1_Count );
					if(Temp>0)
					{
						TIM1_Over_Flow_no++;
						TIM1_Preload_Value	=	Max_Timer_1_Count- Temp;
					}
					else
					{
						TIM1_Preload_Value		= 0 ;
					}
					MTIM1_TCNT1=TIM1_Preload_Value;

					break;
	default :		/*report error*/							break;
	}


}

void MTIM_voidSetCallBack(void (*ptr)(void))
{
	Pointer=ptr;
}

void MTIM_voidSetPWM(u8 Timer,u8 Mode,u8 Duty_Cycle,u16 Period,u8 unit)
{
	u64 UINT=1000,TickFreq=((u64)System_Clock/8);//edit this value based on the duty cycle
	u8 Percent=100;
	switch(Timer)
	{
	case TIMER_0:
		switch(Mode)
		{
		case Inverted_Mode:
			MTIM0_TCCR0=Set_Bit(MTIM0_TCCR0,COM00);
			MTIM0_TCCR0=Set_Bit(MTIM0_TCCR0,COM01);
			MTIM0_OCR0=Max_Timer_0_Count-((Duty_Cycle/Percent)*Max_Timer_0_Count);
			break;
		case NON_Inverted_Mode:
			MTIM0_TCCR0=Clr_Bit(MTIM0_TCCR0,COM00);
			MTIM0_TCCR0=Set_Bit(MTIM0_TCCR0,COM01);
			MTIM0_OCR0=(Duty_Cycle*Max_Timer_0_Count)/Percent;
			break;
		}
		break;
	case TIMER_1:

		switch(Mode)
		{
		case Inverted_Mode:
			MTIM1_TCCR1A=Set_Bit(MTIM1_TCCR1A,COM1A0);
			MTIM1_TCCR1A=Set_Bit(MTIM1_TCCR1A,COM1A1);
			MTIM1_ICR1=(Period * (u64)UINT)/TickFreq ;
			MTIM1_OCR1A=Max_Timer_1_Count-((Duty_Cycle*MTIM1_ICR1)/Percent);

			MTIM1_TCCR1A=Set_Bit(MTIM1_TCCR1A,COM1B0);
			MTIM1_TCCR1A=Set_Bit(MTIM1_TCCR1A,COM1B1);
			MTIM1_OCR1B=Max_Timer_1_Count-((Duty_Cycle*Max_Timer_1_Count)/100);
			break;
		case NON_Inverted_Mode:
			MTIM1_TCCR1A=Clr_Bit(MTIM1_TCCR1A,COM1A0);
			MTIM1_TCCR1A=Set_Bit(MTIM1_TCCR1A,COM1A1);

			MTIM1_ICR1=(Period * (u64)System_Clock)/(UINT * 8);//ICR = Period / Tick_Time
			MTIM1_OCR1A=((Duty_Cycle*(u32)MTIM1_ICR1)/Percent);
			//MTIM1_ICR1=20000;//(Period * UINT) / TickTime;

			numberToString(MTIM1_OCR1A,data);
			MUART_voidSendString(data);
			_delay_ms(500);

			MTIM1_TCCR1A=Clr_Bit(MTIM1_TCCR1A,COM1B0);
			MTIM1_TCCR1A=Set_Bit(MTIM1_TCCR1A,COM1B1);
			MTIM1_OCR1B=((Duty_Cycle*(u32)MTIM1_ICR1)/100);

			break;
		}

		break;
	default:/*report errors*/		break;
	}

}

//TIMER0 overflow interrupt(Normal Mode)


void __vector_11 (void)
{
	static u16 count1=0;
	static u16 count2=0;
	//MDIO_SetPinValue(PORTA,1,HIGH);
	count1++;
	if(count1==TIM0_Over_Flow_no)
	{
		//count2++;

		Pointer();

		count1=0;
		MTIM0_TCNT0=TIM0_Preload_Value;

	}

}


//TIMER0 Output_Compare interrupt(CTC Mode)


void __vector_10(void)
{
	static u16 count1=0;
	//static u16 count2=0;
	//static u8  flag=0;
	count1++;
	if(count1==TIM0_Over_Flow_no)
	{
		//count2++;

			Pointer();



		count1=0;
		MTIM0_TCNT0=TIM0_Preload_Value;
	}

}



//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////TIMER_1 Interrupt Vectors///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



// TIMER1 overflow interrupt(NORMAL_MODE)

//
void __vector_9 (void)
{
	static u16 count1=0;
	static u16 count2=0;
	count1++;
	if(count1==TIM1_Over_Flow_no)
	{
		//count2++;

		Pointer();

		count1=0;
		MTIM1_TCNT1=TIM1_Preload_Value;
	}

}
//

//Compare match A interrupt(CTC Mode

void __vector_7 (void)
{
	static u16 count1=0;
	count1++;
	//static u16 count2=0;
	if(count1==TIM1_Over_Flow_no)
	{
		//count2++;

		Pointer();

		count1=0;
		MTIM1_TCNT1=TIM1_Preload_Value;
	}


}
//
//void __vector_6 (void)
//{
//
//}
