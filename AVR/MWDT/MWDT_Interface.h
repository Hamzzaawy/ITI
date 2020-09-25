/*
 * MWDT_Interface.h
 *
 *  Created on: Jun 26, 2019
 *      Author: Hamza
 */

#ifndef MWDT_INTERFACE_H_
#define MWDT_INTERFACE_H_


#define WDP0			0
#define WDP1			1
#define WDP2			2
#define WDE				3
#define WDTOE			4

#define Delay_16_MS			0b000
#define Delay_32_MS			0b001
#define Delay_65_MS			0b010
#define Delay_130_MS		0b011
#define Delay_260_MS		0b100
#define Delay_520_MS		0b101
#define Delay_1_S			0b110
#define Delay_2_S			0b111





void MWDT_voidStartTimer(u8 Time_Out);
void MWDT_voidStopTimer	(void);
void MWDT_voidRefreshTimer(void);
void MWDT_voidSycReset(void);

#endif /* MWDT_INTERFACE_H_ */
