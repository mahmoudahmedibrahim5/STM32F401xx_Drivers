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

#define RISING_EDGE  		0
#define FALLING_EDGE 		1
#define RISING_AND_FALLING 	2

typedef struct{
	En_Port_t port;
	uint8_t lineNum;
	uint8_t triggerType;
}EXTI_Config_t;

void EXTI_hardwareInterruptMask(EXTI_Config_t *p);
void EXTI_hardwareEventMask(EXTI_Config_t *p);
void EXTI_softwareInterruptMask(uint8_t lineNum);
void EXTI_softwareEventMask(uint8_t lineNum);

#endif /* EXTI_EXTI_INTERFACE_H_ */
