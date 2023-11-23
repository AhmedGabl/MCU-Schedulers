/*
 * HICU_program.c
 *
 *  Created on: Nov 13, 2023
 *      Author: AhmedAbogabl
 */

#include "../includes/HICU_interface.h"
#include "../includes/HICU_registers.h"
#include "../../../utils/BIT_MATH.h"
#include "../../../utils/STD_TYPES.h"

volatile static u16 Private_u16OnPeriod;
volatile static u16 Private_u16OffPeriod;

void ICU_voidInit(void) {
//	Lcd_PutString("inside init");
	//select mode = Normal mode
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);
#if ICU_STARTING_EDGE == ICU_RISING_EDGE
	//select ICU Edge RISING edge
		SET_BIT(TCCR1B, ICES1);
#else if ICU_STARTING_EDGE == ICU_FALLING_EDGE
	//select ICU Edge falling edge
		CLR_BIT(TCCR1B, ICES1);

	#endif

	//enable interrupt
	SET_BIT(TIMSK, TICIE1);

	//Select Prescaler Value = 64  void ICU_voidStart(void);

	SET_BIT(TCCR1B, CS10);
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);
}

void ICU_voidGetDutyCycle(u8* copy_pu8Duty) {
	//Lcd_PutString("inside duty ");

	if (copy_pu8Duty != NULL) {
		//Lcd_PutString("inside duty if ");
		Lcd_PutString("ONPeriod ");

		Lcd_PutInt(Private_u16OnPeriod);
		Lcd_PutString("OffPeriod ");

		Lcd_PutInt(Private_u16OffPeriod);

		*copy_pu8Duty = ((u32) Private_u16OnPeriod * 100) / (Private_u16OnPeriod + Private_u16OffPeriod);
	}
}


void ICU_voidGetFrequency(u32* copy_pu32Frequency_hz) {
//	Lcd_PutString("inside freq ");
	if (copy_pu32Frequency_hz != NULL) {
	//	Lcd_PutString("inside freq if ");
		*copy_pu32Frequency_hz = 1000000UL
				/ (Private_u16OnPeriod + Private_u16OffPeriod);
	}
}

// ISR for ICU
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	static u8 Local_u8EdgeFlag = ICU_STARTING_EDGE;
	static u16 Local_u16OldValue =0;
	static u16 Local_u16CounterValue =0;

	Local_u16CounterValue = ICR1;

	if(Local_u8EdgeFlag ==ICU_RISING_EDGE)
	{
		Private_u16OffPeriod = (Local_u16CounterValue- Local_u16OldValue)*4;

		Local_u8EdgeFlag =ICU_FALLING_EDGE;

		//selest icu edge
		CLR_BIT(TCCR1B,ICES1);

	}
	else if (Local_u8EdgeFlag ==ICU_FALLING_EDGE)
	{
		Private_u16OnPeriod = (Local_u16CounterValue- Local_u16OldValue)*4;

		Local_u8EdgeFlag =ICU_RISING_EDGE;

		//selest icu edge
		SET_BIT(TCCR1B,ICES1);
	}
	Local_u16OldValue = ICR1;
}
