/*
 * WD_program.c
 *
 * Created on: Nov 13, 2023
 * Author: AhmedAbogabl
 */

#include "../../../utils/STD_TYPES.h"
#include "../../../utils/BIT_MATH.h"

#include "../includes/WDT_interface.h"
#include "../includes/WDT_private.h"
#include "../includes/WDT_registers.h"

/*
 * Function: WDT_voidEnable
 * Description: Enables the Watchdog Timer (WDT) with the specified overflow time.
 * Parameters:
 *   - copy_u8Time: Time for WDT overflow, should be one of the WDT_TIME_X_X_MS options.
 */
void WDT_voidEnable(u8 copy_u8Time)
{
    switch (copy_u8Time)
    {
    // Select overflow time as 16.3ms
    case WDT_TIME_16_3_MS:
        CLR_BIT(WDTCR, WDP0);
        CLR_BIT(WDTCR, WDP1);
        CLR_BIT(WDTCR, WDP2);
        break;

    // Select overflow time as 32.5ms
    case WDT_TIME_32_5_MS:
        SET_BIT(WDTCR, WDP0);
        CLR_BIT(WDTCR, WDP1);
        CLR_BIT(WDTCR, WDP2);
        break;

    // Select overflow time as 65ms
    case WDT_TIME_65_MS:
        CLR_BIT(WDTCR, WDP0);
        SET_BIT(WDTCR, WDP1);
        CLR_BIT(WDTCR, WDP2);
        break;

    // Select overflow time as 0.13s
    case WDT_TIME_0_13_S:
        SET_BIT(WDTCR, WDP0);
        SET_BIT(WDTCR, WDP1);
        CLR_BIT(WDTCR, WDP2);
        break;

    // Select overflow time as 0.26s
    case WDT_TIME_0_26_S:
        CLR_BIT(WDTCR, WDP0);
        CLR_BIT(WDTCR, WDP1);
        SET_BIT(WDTCR, WDP2);
        break;

    // Select overflow time as 0.52s
    case WDT_TIME_0_52_S:
        SET_BIT(WDTCR, WDP0);
        CLR_BIT(WDTCR, WDP1);
        SET_BIT(WDTCR, WDP2);
        break;

    // Select overflow time as 1s
    case WDT_TIME_1_S:
        CLR_BIT(WDTCR, WDP0);
        SET_BIT(WDTCR, WDP1);
        SET_BIT(WDTCR, WDP2);
        break;

    // Select overflow time as 2.1s
    case WDT_TIME_2_1_S:
        SET_BIT(WDTCR, WDP0);
        SET_BIT(WDTCR, WDP1);
        SET_BIT(WDTCR, WDP2);
        break;

    default:
        break;
    }
    //enable watch dog
    SET_BIT(WDTCR , WDE);
}


/*
 * Function: WDT_voidDisable
 * Description: Disables the Watchdog Timer (WDT).
 */
void WDT_voidDisable(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR = (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR = 0x00;
}
