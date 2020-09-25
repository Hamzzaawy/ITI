/*
 * OS_Interface.h
 *
 *  Created on: Jul 14, 2019
 *      Author: Hamza
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_


#define Ready		0
#define Suspended	1

void Scheduler (void);

void CreateTask(void(*ptr)(void),u32 Period,u32 Periority,u8 State);

void DeletTask(u32 Periority);


void Suspend (u32 Periority);


void Resume (u32 Periority);


#endif /* OS_INTERFACE_H_ */
