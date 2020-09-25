/*
 * OS_program.c
 *
 *  Created on: Jul 14, 2019
 *      Author: Hamza
 */


#include "LSTR_Types.h"
#include "LUTILS.h"

#include "OS_Interface.h"
#include "OS_Private.h"
#include "OS_Config.h"

Task SysTasks[NumOfTasks];

u32 TickCount=0;

void Scheduler (void)
{

	u32 i;
	TickCount++;

	for(i=0;i<NumOfTasks;i++)
	{
		if(SysTasks[i].Periodicity != 0)
		{
			if (SysTasks[i].State== Ready)
			{
				SysTasks[i].FirstDelay--;
				if(SysTasks[i].FirstDelay == 0)
				{
					(SysTasks[i].TaskHandler)();
					SysTasks[i].FirstDelay=SysTasks[i].Periodicity;
				}
//				if(TickCount % SysTasks[i].Periodicity == 0)
//				{
//					(SysTasks[i].TaskHandler)();
//				}

			}
		}

	}
}

void CreateTask(void(*ptr)(void),u32 Period,u32 Periority,u8 InitState,u8 FirstDelay)
{
	if (Periority<NumOfTasks)
	{
		SysTasks[Periority].Periodicity=Period;
		SysTasks[Periority].TaskHandler=ptr;
		SysTasks[Periority].State=InitState;
		SysTasks[Periority].FirstDelay=FirstDelay;
	}

}

void DeletTask(u32 Periority)
{
	if ( Periority< NumOfTasks )
	{
		SysTasks[Periority].Periodicity=0;
	}
}


void Suspend (u32 Periority)
{
	if ( Periority< NumOfTasks )
	{
		SysTasks[Periority].State=Suspended;
	}
}


void Resume (u32 Periority)
{
	if ( Periority< NumOfTasks )
	{
		SysTasks[Periority].State=Ready;
	}
}
