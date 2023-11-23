/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
//#define F_CPU 16000000UL

#include "utils/BIT_MATH.h"
#include "utils/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/PORT/PORT_cnf.h"
#include "OS/OS_interface.h"

void LED5(void)
{
	Dio_FlipChannel(PA_5);
}

void LED4(void)
{
	Dio_FlipChannel(PA_4);
}

void LED6(void)
{
	Dio_FlipChannel(PA_6);
}

void HW_Init(void)
{
	GI_voidEnable();
	Port_Init(pin_cfg);
}
int main() {
	HW_Init();
	OS_voidCreateTask(0,200,LED4);
	OS_voidCreateTask(1,200,LED5);
	OS_voidCreateTask(2,200,LED6);

	OS_voidStartScheduler();

	while (1)
	{

	}

return 0;
}
