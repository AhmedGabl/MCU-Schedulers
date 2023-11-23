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

//Array of structures contains all tasks
Task OS_Tasks[OS_NUMBER_OF_TASKS];

u16 temp_priodicity[OS_NUMBER_OF_TASKS]={0};

void Scheduler(void) {
	u8 i;
    for (i = 0; i < OS_NUMBER_OF_TASKS; i++) {

        if (temp_priodicity[i] == 0 ) {
            temp_priodicity[i] = OS_Tasks[i].Periodicity - 1;
        	OS_Tasks[i].Fptr();
        } else {
            temp_priodicity[i]--;
        }
    }
}

/*
 * OS_voidCreateTask
 */
void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u8Periodicity, void (*ptr)(void)) {
    OS_Tasks[Copy_u8ID].Fptr = ptr;
    OS_Tasks[Copy_u8ID].Periodicity = Copy_u8Periodicity;
    OS_Tasks[Copy_u8ID].TaskID = Copy_u8ID;
    //temp_priodicity[Copy_u8ID] = Copy_u8Periodicity;
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
