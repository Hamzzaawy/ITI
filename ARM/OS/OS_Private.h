/*
 * OS_Private.h
 *
 *  Created on: Jul 14, 2019
 *      Author: Hamza
 */

#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_



typedef struct
{
	void (*TaskHandler)(void);
	u32 Periodicity;
	u8 State;
	u32 FirstDelay;
}Task;

#endif /* OS_PRIVATE_H_ */
