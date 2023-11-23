/*
 * WD_registers.h
 *
 *  Created on: Nov 13, 2023
 *      Author: AhmedAbogabl
 */

#ifndef MCAL_WD_WD_REGISTERS_H_
#define MCAL_WD_WD_REGISTERS_H_

#define WDTCR    (*(volatile unsigned char*) 0x41)


#define WDP0  0
#define WDP1  1
#define WDP2  2
#define WDE   3
#define WDTOE 4

#endif /* MCAL_WD_WD_REGISTERS_H_ */
