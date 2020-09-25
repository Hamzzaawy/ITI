
// including utilities header and custom named data types header
#include "LSTR_Types.h"
#include "LUTILS.h"

#include "MDIO_private.h"
#include "MDIO_interface.h"

//set direction of specific pin
void MDIO_SetDirection(u8 PORT,u8 Bit,u8 Status)
{
	switch(PORT)
	{
		case PORTA:
			switch(Status)
			{
				case OUTPUT:		Set_Bit(MDIO_DDRA,Bit);					break;
				case INPUT_FLOAT:	Clr_Bit(MDIO_DDRA,Bit);					break;
				case INPUT_PULLUP:	Clr_Bit(MDIO_DDRA,Bit);
							Set_Bit(MDIO_PORTA,Bit);				break;
			}
			break;

		case PORTB:
			switch(Status)
			{
				case OUTPUT: 		 Set_Bit(MDIO_DDRB,Bit);				break;
				case INPUT_FLOAT:	 Clr_Bit(MDIO_DDRB,Bit);				break;
				case INPUT_PULLUP:	 Clr_Bit(MDIO_DDRB,Bit);
							 Set_Bit(MDIO_PORTB,Bit);				break;
			}
			break;

		case PORTC:
			switch(Status)
			{
				case OUTPUT:		 Set_Bit(MDIO_DDRC,Bit);				break;
				case INPUT_FLOAT:	 Clr_Bit(MDIO_DDRC,Bit);				break;
				case INPUT_PULLUP:	 Clr_Bit(MDIO_DDRC,Bit);
							 Set_Bit(MDIO_PORTC,Bit);				break;
				}
				break;

		case PORTD:
			switch(Status)
			{
				case OUTPUT:		 Set_Bit(MDIO_DDRD,Bit);				break;
				case INPUT_FLOAT:	 Clr_Bit(MDIO_DDRD,Bit);				break;
				case INPUT_PULLUP:	 Clr_Bit(MDIO_DDRD,Bit);
						  	 Set_Bit(MDIO_PORTD,Bit);				break;
			}
			break;
	}
	return;
}

// setting a value for the hole port
void MDIO_SetPortValue(u8 PORT,u8 Value)
{
	switch(PORT)
	{
		case PORTA:			 MDIO_PORTA=Value;								break;
		case PORTB:			 MDIO_PORTB=Value;								break;
		case PORTC:			 MDIO_PORTC=Value;								break;
		case PORTD:			 MDIO_PORTD=Value;								break;
	}
	return;
}

// setting a value for a specific pin
void MDIO_SetPinValue(u8 PORT,u8 Bit,u8 Value)
{
	switch(PORT)
	{
	case PORTA:
		switch(Value)
		{
		case HIGH:			 Set_Bit(MDIO_PORTA,Bit);				break;
		case LOW:			 Clr_Bit(MDIO_PORTA,Bit);				break;
		}
	break;
	case PORTB:
		switch(Value)
		{
		case HIGH:			Set_Bit(MDIO_PORTB,Bit);				break;
		case LOW:			Clr_Bit(MDIO_PORTB,Bit);				break;
		}
	break;
	case PORTC:
		switch(Value)
		{
		case HIGH:			Set_Bit(MDIO_PORTC,Bit);				break;
		case LOW:			Clr_Bit(MDIO_PORTC,Bit);				break;
		}
	break;
	case PORTD:
		switch(Value)
		{
		case HIGH:			Set_Bit(MDIO_PORTD,Bit);				break;
		case LOW:			Clr_Bit(MDIO_PORTD,Bit);				break;
		}
	break;
	}
	return;
}

// reading the value of the hole port
u8 MDIO_GetPortValue (u8 PORT)
{
	u8 output=0;
	switch(PORT)
	{
	case PORTA:		output=MDIO_PINA;			break;
	case PORTB:		output=MDIO_PINB;			break;
	case PORTC:		output=MDIO_PINC;			break;
	case PORTD:		output=MDIO_PIND;			break;
	}
  	return output;
}

// reading the value of a specific pin 
u8 MDIO_GetPinValue(u8 PORT,u8 Bit)
{
	switch(PORT)
	{
	case PORTA:			return GET_Bit(MDIO_PINA,Bit);				break;
	case PORTB:			return GET_Bit(MDIO_PINB,Bit);				break;
	case PORTC:			return GET_Bit(MDIO_PINC,Bit);				break;
	case PORTD:			return GET_Bit(MDIO_PIND,Bit);				break;
	default:			return 0;						break;
	}

}
