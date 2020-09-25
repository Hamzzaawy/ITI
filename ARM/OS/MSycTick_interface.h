/*
 * MSycClock_interface.h
 *
 *  Created on: Jun 28, 2019
 *      Author: Hamza
 */

#ifndef MSYCTICK_INTERFACE_H_
#define MSYCTICK_INTERFACE_H_


// STK_CTRL register pins

#define COUNTFLAG			16
#define CLKSOURCE			2
#define TICKINT				1
#define ENABLE				0


void MSysTick_voidInit(void);

void MSysTick_voidSetReloadValue(u32	copyValue);


#endif /* MSYCTICK_INTERFACE_H_ */
