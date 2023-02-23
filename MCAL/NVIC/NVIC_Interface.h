/*
 * NVIC_Interface.h
 *
 *  Created on: Feb 22, 2023
 *      Author: ADMIN
 */

#ifndef NVIC_NVIC_INTERFACE_H_
#define NVIC_NVIC_INTERFACE_H_

#include "../SYSCFG/SYSCFG_Interface.h"

#define RISING_EDGE  		0
#define FALLING_EDGE 		1
#define RISING_AND_FALLING 	2

typedef struct{
	En_Port_t port;
	uint8_t lineNum;
	uint8_t triggerType;
}EXTI_Config_t;

void NVIC_hardwareInterruptMask(EXTI_Config_t *p);
void NVIC_hardwareEventMask(EXTI_Config_t *p);
void NVIC_softwareInterruptMask(uint8_t lineNum);
void NVIC_softwareEventMask(uint8_t lineNum);

#endif /* NVIC_NVIC_INTERFACE_H_ */
