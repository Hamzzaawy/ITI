/*
 * Config.h
 *
 *  Created on: Jun 20, 2019
 *      Author: Hamza
 */

#ifndef MUART_CONFIG_H_
#define MUART_CONFIG_H_


//configuration macros


#define F_osc					8000000UL

#define BAUD					9400UL

#define	Operation_Mode			Async_Normal

//the values in this macro represents the number of stop bits 0->1 stop bit		1-> 2 stop bit
#define Stop_Bits					0

//the values in this macro represents the parity condition
#define Parity_Condition			Parity_Disable

//the values in this macro represents the data size in the frame
#define Data_Size					Data_8_Bits

//the value in this macro represent the enabling or disabling the RX interrupt
#define RX_INT_En					0

//the value in this macro represent the enabling or disabling the TX interrupt
#define TX_INT_En					0

//the value in this macro represent the enabling or disabling the UDRE interrupt
#define UDR_INT_En					0


#endif /* MUART_CONFIG_H_ */
