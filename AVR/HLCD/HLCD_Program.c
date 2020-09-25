#include "MDIO_interface.h"
#include "util/delay.h"
#include "LUTILS.h"
#include "LSTR_Types.h"


#define Rs	5
#define R_W	6
#define En	7

#define PORT_Control    PORTC
#define PORT_DATA		PORTA
#define mode	8

#define Left 1
#define Right 0


void HLCD_Init_LCD (void)
{
	//configuring the control pins in the Mc pins
	MDIO_SetDirection(PORT_Control,Rs,OUTPUT);
	MDIO_SetDirection(PORT_Control,R_W,OUTPUT);
	MDIO_SetDirection(PORT_Control,En,OUTPUT);
	if (mode==8)
	{
		//steps of initialisation 8-bits mode of data lines(page13 in data sheet)
		_delay_ms(50);


		for (u8 i=0;i<8;i++)
		{
			MDIO_SetDirection(PORT_DATA,i,OUTPUT);
		}

		//editing the FUNCTION_SET register
		// 0x38 DL=1 (8 bit data used not 4) N=1 (for two lines of data) F=0 (to use smaller font)
		//HLCD_Write_Commmand(0x38);
		HLCD_Write_Commmand(0x38);
		//recommended delay from1 data Sheet
		_delay_ms(1);


		//editing the display on/off register
		// 0x0f D=1 (for powering the lcd)  C=1(for displaying a cursor) B=1(to make the cursor Blink
		HLCD_Write_Commmand(0x0f);


		_delay_ms(1);


		//editing the display clear register
		HLCD_Write_Commmand(0x01);


		_delay_ms(2);


		//editing the entry mode register
		HLCD_Write_Commmand(0x06);

	}
	else if(mode==4)
	{
		_delay_ms(50);


		for (u8 i=4;i<8;i++)
		{
			MDIO_SetDirection(PORT_DATA,i,HIGH);
		}

		//editing the FUNCTION_SET register
		// 0x38 DL=0 (4 bit data used not 8) N=1 (for two lines of data) F=0 (to use smaller font)
		HLCD_Write_Commmand(0x02);
		HLCD_Write_Commmand(0x28);


		_delay_ms(1);


		//editing the display on/off register
		// 0x0f D=1 (for powering the lcd)  C=1(for displaying a cursor) B=1(to make the cursor Blink

		HLCD_Write_Commmand(0x0f);


		_delay_ms(1);


		//editing the display clear register

		HLCD_Write_Commmand(0x01);


		_delay_ms(2);


		//editing the entery mode register
		HLCD_Write_Commmand(0x06);

	}

}

void HLCD_Write_Commmand(u8 Command)
{
	//set the Rs pin to zero for writing command
	MDIO_SetPinValue(PORT_Control,Rs,LOW);

	//set the read write pin to zero for writing data to the LCD
	MDIO_SetPinValue(PORT_Control,R_W,LOW);
	if (mode ==8)
	{
		//writing the command to the port
		MDIO_SetPortValue(PORT_DATA,Command);
		//sitting the enable pin tohigh for 5 ms and then to zero to notify the lcd to read the data
		MDIO_SetPinValue(PORT_Control,En,HIGH);
		_delay_ms(5);
		MDIO_SetPinValue(PORT_Control,En,LOW);
		//sitting the enable pin tohigh for 5 ms and then to zero to notify the lcd to read the data
		MDIO_SetPinValue(PORT_Control,En,HIGH);
		_delay_ms(5);
		MDIO_SetPinValue(PORT_Control,En,LOW);


	}
	else if(mode == 4)
	{

			u8 data1=0;
			//masking the left nibble
			data1=Command & 0xf0;
			//writing the left nibble of the command to the port
			MDIO_SetPortValue(PORT_DATA,data1);

			//latching the enable pin
			//sitting the enable pin tohigh for 5 ms and then to zero to notify the lcd to read the data
			MDIO_SetPinValue(PORT_Control,En,HIGH);
			_delay_ms(5);
			MDIO_SetPinValue(PORT_Control,En,LOW);

			//shifting the right nibble to the left one and masking it
			data1=((Command <<4) & 0xf0);
			//writing the right nibble of the command to the port
			MDIO_SetPortValue(PORT_DATA,data1);

			//latching the enable pin again to read the next part of the command
			//sitting the enable pin tohigh for 5 ms and then to zero to notify the lcd to read the data
			MDIO_SetPinValue(PORT_Control,En,HIGH);
			_delay_ms(5);
			MDIO_SetPinValue(PORT_Control,En,LOW);

	}
	return;
}

void HLCD_Write_Data(u8 Data)

{
	//set the Rs pin to zero for writing data
	MDIO_SetPinValue(PORT_Control,Rs,HIGH);

	//set the read write pin to zero for writing data to the LCD
	MDIO_SetPinValue(PORT_Control,R_W,LOW);

	if(mode == 8)
	{
		//writing the command to the port
		MDIO_SetPortValue(PORT_DATA,Data);

		//sitting the enable pin to high for 5 ms and then to zero to notify the lcd to read the data
		MDIO_SetPinValue(PORT_Control,En,HIGH);
		_delay_ms(5);
		MDIO_SetPinValue(PORT_Control,En,LOW);
	}
	else if(mode == 4)
	{
		u8 data1=0;
		//masking the left nibble
		data1=Data & 0xf0;
		//writing the left nibble of the command to the port
		MDIO_SetPortValue(PORT_DATA,data1);

		//latching the enable pin
		//sitting the enable pin tohigh for 5 ms and then to zero to notify the lcd to read the data
		MDIO_SetPinValue(PORT_Control,En,HIGH);
		_delay_ms(5);
		MDIO_SetPinValue(PORT_Control,En,LOW);

		//shifting the right nibble to the left one and masking it
		data1=((Data <<4) & 0xf0);
		//writing the right nibble of the command to the port
		MDIO_SetPortValue(PORT_DATA,data1);

		//latching the enable pin again to read the next part of the command
		//sitting the enable pin tohigh for 5 ms and then to zero to notify the lcd to read the data
		MDIO_SetPinValue(PORT_Control,En,HIGH);
		_delay_ms(5);
		MDIO_SetPinValue(PORT_Control,En,LOW);
	}

	return;

}


void HLCD_Write_String(u8* String,u8 size)
{


	for(u8 j=0;(j<size);j++)
	{
		HLCD_Write_Data(String[j]);
	}

}

void HLCD_Clear(void)
{
	HLCD_Write_Commmand(0x01);
	_delay_ms(2);
}

void HLCD_Shift_SC(u8 number,u8 dir)
{

	if (dir==Right)
	{
		while (number >0)
		{
			HLCD_Write_Commmand(0x18);
			_delay_ms(1);
			number--;
		}
	}
	else if (dir==Left)
	{
		while (number >0)
		{
			HLCD_Write_Commmand(0x1c);
			_delay_ms(1);
			number--;
		}
	}
}

void HLCD_Shift_CR(u8 number,u8 dir)
{


	if (dir==Left)
	{
		while (number >0)
		{
			HLCD_Write_Commmand(0x010);
			_delay_ms(1);
			number--;
		}
	}
	else if (dir==Right)
	{
		while (number >0)
		{
			HLCD_Write_Commmand(0x016);
			_delay_ms(1);
			number--;
		}
	}
}


void HLCD_2line()
{
	HLCD_Write_Commmand(0xc0);
	_delay_ms(1);
}


void HLCCD_SetCursor(u8 Row,u8 Col)
{
	switch(Row)
	{
	case 0:
		HLCD_Write_Commmand(((0b10000000)|Col));
		break;
	case 1:
		HLCD_Write_Commmand(((0b11000000)|Col));
		break;

	}
}


void HLCD_Cre_Cus(void)
{
	HLCD_Write_Commmand(0b01000000);

		HLCD_Write_Data(0x00);
		HLCD_Write_Data(0x0E);
		HLCD_Write_Data(0x1F);
		HLCD_Write_Data(0x1F);
		HLCD_Write_Data(0x0E);
		HLCD_Write_Data(0x04);
		HLCD_Write_Data(0x00);
		HLCD_Write_Data(0x00);

	/*HLCD_Write_Data(0b00010010);
	HLCD_Write_Data(0b00011111);
	HLCD_Write_Data(0b00011111);
	HLCD_Write_Data(0b00011111);
	HLCD_Write_Data(0b00001110);
	HLCD_Write_Data(0b00001110);
	HLCD_Write_Data(0b00000100);
	HLCD_Write_Data(0b00000000);*/

	//u8 SOLID_HEART_PATTERN[8] = { 0x00, 0x0E, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };
	//u8 EMPTY_HEART_PATTERN[8] = { 0x00, 0x0E, 0x11, 0x11, 0x0A, 0x04, 0x00, 0x00 };

	HLCD_Write_Commmand(0b10000000);
}
