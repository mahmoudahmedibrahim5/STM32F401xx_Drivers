/*
 * EXTI_Interface.h
 *
 *  Created on: Jun 11, 2023
 *      Author: ADMIN
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

#include "../../Utilities/stm32f401xx.h"
#include "../SYSCFG/SYSCFG_Interface.h"
#include "EXTI_Registers.h"

#define EXTI_RISING_EDGE  			0
#define EXTI_FALLING_EDGE 			1
#define EXTI_RISING_AND_FALLING 	2

typedef struct{
	EN_Port_t port;
	uint8_t lineNum;
	uint8_t triggerType;
}EXTI_Config_t;

void EXTI_hardwareInterruptMask(EXTI_Config_t *p);
void EXTI_hardwareEventMask(EXTI_Config_t *p);
void EXTI_softwareInterruptMask(uint8_t lineNum);
void EXTI_softwareEventMask(uint8_t lineNum);

/* Clear the flag at the end of ISR, line Number = pin Number*/
void EXTI_clearFlag(uint8_t lineNum);

#endif /* EXTI_EXTI_INTERFACE_H_ */
