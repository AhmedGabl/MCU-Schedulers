/*
 * OS_program.c
 *
 *  Created on: Nov 17, 2023
 *      Author: AhmedAbogabl
 */

#include "../utils/BIT_MATH.h"
#include "../MCAL/TIMERS/TIMER2/includes/TMR2_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"

Task OS_Tasks[OS_NUM_PRIORITY_LEVELS][OS_NUM_SAME_PRIORITY_TASKS];

u32 TickCount = 0;

void Scheduler(void) {
	for (u8 i = 0; i < OS_NUM_PRIORITY_LEVELS; i++) {
        for (u8 j = 0; j < OS_NUM_SAME_PRIORITY_TASKS; j++) {
            if (OS_Tasks[i][j].State == OS_TASK_READY) {
                if (OS_Tasks[i][j].InitialDelay == 0) {
                    OS_Tasks[i][j].InitialDelay = OS_Tasks[i][j].Periodicity - 1;
                    OS_Tasks[i][j].Fptr();
                } else {
                    OS_Tasks[i][j].InitialDelay--;
                }
            }
        }
    }
    TickCount++;
}

/*
 * OS_voidCreateTask
 */
void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u8Periodicity, u16 Copy_u8InitialDelay, void (*ptr)(void)) {
	 u8 taskLevel = 0;
	 static u8 Tasks_Init = 0;

	if(Tasks_Init == 0)
	{
		 for (u8 i = 0; i < OS_NUM_PRIORITY_LEVELS; i++) {
		        for (u8 j = 0; j < OS_NUM_SAME_PRIORITY_TASKS; j++) {
		            OS_Tasks[i][j].Fptr = NULL;
		            OS_Tasks[i][j].State = OS_TASK_DELETED;
		        }
		    }
		 Tasks_Init = 1 ;
	}
	// Find the first available slot for the task with the same priority
    while (taskLevel < OS_NUM_SAME_PRIORITY_TASKS && OS_Tasks[Copy_u8ID][taskLevel].Fptr != NULL) {
        taskLevel++;
    }

    if (taskLevel < OS_NUM_SAME_PRIORITY_TASKS) {
        OS_Tasks[Copy_u8ID][taskLevel].Fptr = ptr;
        OS_Tasks[Copy_u8ID][taskLevel].InitialDelay = Copy_u8InitialDelay;
        OS_Tasks[Copy_u8ID][taskLevel].Periodicity = Copy_u8Periodicity;
        OS_Tasks[Copy_u8ID][taskLevel].State = OS_TASK_READY;
        OS_Tasks[Copy_u8ID][taskLevel].TaskID = Copy_u8ID;
    }
}

/*
 * OS_voidDeleteTask
 */
void OS_voidDeleteTask(u8 Copy_u8ID) {
    for (u8 j = 0; j < OS_NUM_SAME_PRIORITY_TASKS; j++) {
        OS_Tasks[Copy_u8ID][j].State = OS_TASK_DELETED;
    }
}

/*
 * OS_voidSuspendTask
 */
void OS_voidSuspendTask(u8 Copy_u8ID, u8 Copy_u8SuspendTime) {
    for (u8 j = 0; j < OS_NUM_SAME_PRIORITY_TASKS; j++) {
        OS_Tasks[Copy_u8ID][j].State = OS_TASK_SUSPENDED;
        OS_Tasks[Copy_u8ID][j].SuspendTime = Copy_u8SuspendTime + TickCount;
    }
}

/*
 * OS_voidStartScheduler
 */
void OS_voidStartScheduler(void) {
    // Initialize Timer/Counter 2
    TMR2_voidInit();

    // Start Timer/Counter 2
    TMR2_voidStart();

    // Set a callback function to be called on Timer/Counter 2 overflow
    TMR2_voidSetCallBackOVF(Scheduler);
}

/*
 * OS_voidResumeTask
 */
void OS_voidResumeTask(u8 Copy_u8ID) {
    for (u8 j = 0; j < OS_NUM_SAME_PRIORITY_TASKS; j++) {
        OS_Tasks[Copy_u8ID][j].State = OS_TASK_READY;
    }
}

/*
 * OS_u8GetTaskState
 */
u8 OS_u8GetTaskState(u8 Copy_u8ID, u8 Copy_u8Level) {
    return OS_Tasks[Copy_u8ID][Copy_u8Level].State;
}
