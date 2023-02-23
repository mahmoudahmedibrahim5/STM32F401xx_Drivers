/*
 * NVIC_Program.c
 *
 *  Created on: Feb 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "../../Utilities/stm32f401xx.h"
#include "NVIC_Interface.h"
#include "NVIC_Registers.h"

void NVIC_hardwareInterruptMask(EXTI_Config_t *p)
{
	SYSCFG_EXTIcontrol(p->port, p->lineNum);
	EXTI->IMR |= (1<<(p->lineNum));
	if((p->triggerType) == RISING_EDGE || (p->triggerType) == RISING_AND_FALLING){
		EXTI->RTSR |= (1<<(p->lineNum));
	}
	if((p->triggerType) == FALLING_EDGE){
		EXTI->FTSR |= (1<<(p->lineNum));
	}
}

void NVIC_hardwareEventMask(EXTI_Config_t *p)
{
	SYSCFG_EXTIcontrol(p->port, p->lineNum);
	EXTI->EMR |= (1<<(p->lineNum));
	if((p->triggerType) == RISING_EDGE || (p->triggerType) == RISING_AND_FALLING){
		EXTI->RTSR |= (1<<(p->lineNum));
	}
	if((p->triggerType) == FALLING_EDGE){
		EXTI->FTSR |= (1<<(p->lineNum));
	}
}

void NVIC_softwareInterruptMask(uint8_t lineNum)
{
	EXTI->IMR |=(1<<lineNum);
	EXTI->SWIER |=(1<<lineNum);
}

void NVIC_softwareEventMask(uint8_t lineNum)
{
	EXTI->EMR |=(1<<lineNum);
	EXTI->SWIER |=(1<<lineNum);
}
