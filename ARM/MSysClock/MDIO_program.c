#include"LSTR_TYPES.h"
#include"Lutils.h"


#include"MDIO_private.h"
#include"MDIO_interface.h"
#include"MDIO_config.h"



void MDIO_voidIntialize  (void)
{
	#if DIO_U8_PIN0_MODE  ==	DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN0);
			#undef 	DIO_U8_PIN0_MODE
			#define DIO_U8_PIN0_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN1_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN1);
			#undef 	DIO_U8_PIN1_MODE
			#define DIO_U8_PIN1_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN2_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN2);
			#undef 	DIO_U8_PIN2_MODE
			#define DIO_U8_PIN2_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN3_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN3);
			#undef 	DIO_U8_PIN3_MODE
			#define DIO_U8_PIN3_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN4_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN4);
			#undef 	DIO_U8_PIN4_MODE
			#define DIO_U8_PIN4_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN5_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN5);
			#undef 	DIO_U8_PIN5_MODE
			#define DIO_U8_PIN5_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN6_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN6);
			#undef 	DIO_U8_PIN6_MODE
			#define DIO_U8_PIN6_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN7_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN7);
			#undef 	DIO_U8_PIN7_MODE
			#define DIO_U8_PIN7_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN8_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN8);
			#undef 	DIO_U8_PIN8_MODE
			#define DIO_U8_PIN8_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN9_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN9);
			#undef 	DIO_U8_PIN9_MODE
			#define DIO_U8_PIN9_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN10_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN10);
			#undef 	DIO_U8_PIN10_MODE
			#define DIO_U8_PIN10_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN11_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN11);
			#undef 	DIO_U8_PIN11_MODE
			#define DIO_U8_PIN11_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN12_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN12);
			#undef 	DIO_U8_PIN12_MODE
			#define DIO_U8_PIN12_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN13_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN13);
			#undef 	DIO_U8_PIN13_MODE
			#define DIO_U8_PIN13_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN14_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN14);
			#undef 	DIO_U8_PIN14_MODE
			#define DIO_U8_PIN14_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN15_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN15);
			#undef 	DIO_U8_PIN15_MODE
			#define DIO_U8_PIN15_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN16_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN16%16);
			#undef 	DIO_U8_PIN10_MODE
			#define DIO_U8_PIN10_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN17_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN17%16);
			#undef 	DIO_U8_PIN17_MODE
			#define DIO_U8_PIN17_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN18_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN18%16);
			#undef 	DIO_U8_PIN18_MODE
			#define DIO_U8_PIN18_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN19_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN19%16);
			#undef 	DIO_U8_PIN19_MODE
			#define DIO_U8_PIN19_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN20_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN20%16);
			#undef 	DIO_U8_PIN20_MODE
			#define DIO_U8_PIN20_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN21_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN21%16);
			#undef 	DIO_U8_PIN21_MODE
			#define DIO_U8_PIN21_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN22_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN22%16);
			#undef 	DIO_U8_PIN22_MODE
			#define DIO_U8_PIN22_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN23_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN23%16);
			#undef 	DIO_U8_PIN23_MODE
			#define DIO_U8_PIN23_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN24_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN24%16);
			#undef 	DIO_U8_PIN24_MODE
			#define DIO_U8_PIN24_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN25_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN25%16);
			#undef 	DIO_U8_PIN25_MODE
			#define DIO_U8_PIN25_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN26_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN26%16);
			#undef 	DIO_U8_PIN26_MODE
			#define DIO_U8_PIN26_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN27_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN27%16);
			#undef 	DIO_U8_PIN27_MODE
			#define DIO_U8_PIN27_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN28_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOA_ODR=Set_Bit(GPIOA_ODR,DIO_U8_PIN28%16);
			#undef 	DIO_U8_PIN28_MODE
			#define DIO_U8_PIN28_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN29_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN29%16);
			#undef 	DIO_U8_PIN29_MODE
			#define DIO_U8_PIN29_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN30_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN30%16);
			#undef 	DIO_U8_PIN10_MODE
			#define DIO_U8_PIN10_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN31_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOB_ODR=Set_Bit(GPIOB_ODR,DIO_U8_PIN31%16);
			#undef 	DIO_U8_PIN31_MODE
			#define DIO_U8_PIN31_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN32_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOC_ODR=Set_Bit(GPIOC_ODR,DIO_U8_PIN32%16);
			#undef 	DIO_U8_PIN10_MODE
			#define DIO_U8_PIN10_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN33_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOC_ODR=Set_Bit(GPIOC_ODR,DIO_U8_PIN33%16);
			#undef 	DIO_U8_PIN33_MODE
			#define DIO_U8_PIN33_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	#if DIO_U8_PIN34_MODE  ==   DIO_U8_INPUT_PULLUP
			GPIOC_ODR=Set_Bit(GPIOC_ODR,DIO_U8_PIN34%16);
			#undef 	DIO_U8_PIN34_MODE
			#define DIO_U8_PIN34_MODE	DIO_U8_INPUT_PULLDOWN
	#endif

	GPIOA_CRL=(u32) ( (DIO_U8_PIN0_MODE)			|
			 		  (DIO_U8_PIN1_MODE << 4)		|
			 		  (DIO_U8_PIN2_MODE << 8)		|
			 		  (DIO_U8_PIN3_MODE << 12)		|
			 		  (DIO_U8_PIN4_MODE << 16)		|
			 		  (DIO_U8_PIN5_MODE << 20)		|
			 		  (DIO_U8_PIN6_MODE << 24)  	|
			 		  (DIO_U8_PIN7_MODE << 28)    	);

	GPIOA_CRH=(u32) ( (DIO_U8_PIN8_MODE)			|
			 		  (DIO_U8_PIN9_MODE << 4)		|
			 		  (DIO_U8_PIN10_MODE << 8)		|
			 		  (DIO_U8_PIN11_MODE << 12)		|
			 		  (DIO_U8_PIN12_MODE << 16)		|
			 		  (DIO_U8_PIN13_MODE << 20)		|
			 		  (DIO_U8_PIN14_MODE << 24)  	|
			 		  (DIO_U8_PIN15_MODE << 28)    	);	

	GPIOB_CRL=(u32) ( (DIO_U8_PIN16_MODE)			|
			 		  (DIO_U8_PIN17_MODE << 4)		|
			 		  (DIO_U8_PIN18_MODE << 8)		|
			 		  (DIO_U8_PIN19_MODE << 12)		|
			 		  (DIO_U8_PIN20_MODE << 16)		|
			 		  (DIO_U8_PIN21_MODE << 20)		|
			 		  (DIO_U8_PIN22_MODE << 24)  	|
			 		  (DIO_U8_PIN23_MODE << 28)    	);

	GPIOB_CRH=(u32) ( (DIO_U8_PIN24_MODE)			|
			 		  (DIO_U8_PIN25_MODE << 4)		|
			 		  (DIO_U8_PIN26_MODE << 8)		|
			 		  (DIO_U8_PIN27_MODE << 12)		|
			 		  (DIO_U8_PIN28_MODE << 16)		|
			 		  (DIO_U8_PIN29_MODE << 20)		|
			 		  (DIO_U8_PIN30_MODE << 24)  	|
			 		  (DIO_U8_PIN31_MODE << 28)    	);	

	GPIOC_CRH=(u32) ( (DIO_U8_PIN32_MODE << 20)		|
			 		  (DIO_U8_PIN33_MODE << 24)  	|
			 		  (DIO_U8_PIN34_MODE << 28)    	);	

}
void MDIO_voidSetPinValue(u8 Copy_u8PinNo,u8 Copy_u8PinVal)
{
	u8 Local_u8Port = Copy_u8PinNo  /  DIO_U8_PORT_SIZE;
	u8 Local_u8Pin	= Copy_u8PinNo % DIO_U8_PORT_SIZE;

	if(Copy_u8PinVal == DIO_u8_HIGH)
	{
		switch (Local_u8Port)
		{
		case DIO_U8_PORTA:	GPIOA_ODR=Set_Bit(GPIOA_ODR,Local_u8Pin); break;
		case DIO_U8_PORTB:	GPIOB_ODR=Set_Bit(GPIOB_ODR,Local_u8Pin); break;
		case DIO_U8_PORTC:	GPIOC_ODR=Set_Bit(GPIOC_ODR,Local_u8Pin); break;
		default: /*report error*/									  break;
			
		}
	}
	else if (Copy_u8PinVal == DIO_u8_LOW )
	{
		switch (Local_u8Port)
		{
		case DIO_U8_PORTA:	GPIOA_ODR=Clr_Bit(GPIOA_ODR,Local_u8Pin); break;
		case DIO_U8_PORTB:	GPIOB_ODR=Clr_Bit(GPIOB_ODR,Local_u8Pin); break;
		case DIO_U8_PORTC:	GPIOC_ODR=Clr_Bit(GPIOC_ODR,Local_u8Pin); break;
		default:/*report error*/									  break;
			
		}

	}
}
void MDIO_voidGetPinValue(u8 Copy_u8PinNo,u8 *Copy_u8PinVal)
{
	u8 Local_u8Port = Copy_u8PinNo  /  DIO_U8_PORT_SIZE;
	u8 Local_u8Pin	= Copy_u8PinNo % DIO_U8_PORT_SIZE;

	switch(Local_u8Port)
	{
	case PORTA:		*Copy_u8PinVal= GET_BIT( GPIOA_IDR , Local_u8Pin);				break;
	case PORTB:		*Copy_u8PinVal= GET_BIT( GPIOB_IDR , Local_u8Pin);				break;
	case PORTC:		*Copy_u8PinVal= GET_BIT( GPIOC_IDR , Local_u8Pin);				break;
	default: /*report errors*/														break;
	}
	return ;
}
void MDIO_voidSetPinMode (u8 Copy_u8pinNo,u8 Copy_PinMode)
{
	u8 Local_u8Port = Copy_u8pinNo  /  DIO_U8_PORT_SIZE;
	u8 Local_u8Pin	= Copy_u8pinNo % DIO_U8_PORT_SIZE;
	Copy_PinMode &= 0x0f;
	switch (Local_u8Port)
	{
	case DIO_U8_PORTA:
		if(Local_u8Pin<=7)
		{
			GPIOA_CRL &= ~ (0x0F) << (4*Local_u8Pin);
			GPIOA_CRL |= Copy_PinMode << (4*Local_u8Pin);
		}
		else if(Local_u8Pin<=15)
		{
			Local_u8Pin-=8;
			GPIOA_CRH &= ~ (0x0F) << (4*Local_u8Pin);
			GPIOA_CRH |= Copy_PinMode << (4*Local_u8Pin);			
		}				
	break;
	case DIO_U8_PORTB:
		if(Local_u8Pin<=7)
		{
			GPIOB_CRL &= ~ (0x0F) << (4*Local_u8Pin);
			GPIOB_CRL |= Copy_PinMode << (4*Local_u8Pin);
		}
		else if(Local_u8Pin<=15)
		{
			Local_u8Pin-=8;
			GPIOB_CRH &= ~ (0x0F) << (4*Local_u8Pin);
			GPIOB_CRH |= Copy_PinMode << (4*Local_u8Pin);			
		}				
	break;						
	
	
	case DIO_U8_PORTC:
		if((Local_u8Pin >=13) && (Local_u8Pin <=15))
		{					
			Local_u8Pin-=8;
			GPIOB_CRH &= ~ (0x0F) << (4*Local_u8Pin);
			GPIOB_CRH |= Copy_PinMode << (4*Local_u8Pin);
		}	
	break;
	
	default:/*error report*/
		break;
	}

}
