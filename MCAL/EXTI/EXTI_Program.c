/*
 * EXTI_Program.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "EXTI_Interface.h"

void EXTI_hardwareInterruptMask(EXTI_Config_t *p)
{
	// Enable SYSCFG clock
	RCC_peripheralEn(SYSCFG_EN);
	// Choose certain line for certain port
	SYSCFG_EXTIcontrol(p->port, p->lineNum);
	// Enable Interrupt mask
	EXTI->IMR |= (1<<(p->lineNum));

	// Choose the trigger mode
	if((p->triggerType) == EXTI_RISING_EDGE){
		// Enable Rising Edge trigger
		EXTI->RTSR |= (1<<(p->lineNum));
		EXTI->FTSR &= ~(1<<(p->lineNum));
	}
	if((p->triggerType) == EXTI_FALLING_EDGE){
		// Enable Falling Edge trigger
		EXTI->FTSR |= (1<<(p->lineNum));
		EXTI->RTSR &= ~(1<<(p->lineNum));
	}
	if((p->triggerType) == EXTI_RISING_AND_FALLING){
		// Enable Rising Edge trigger
		EXTI->RTSR |= (1<<(p->lineNum));
		// Enable Falling Edge trigger
		EXTI->FTSR |= (1<<(p->lineNum));
	}
}

void EXTI_hardwareEventMask(EXTI_Config_t *p)
{
	SYSCFG_EXTIcontrol(p->port, p->lineNum);
	EXTI->EMR |= (1<<(p->lineNum));
	if((p->triggerType) == EXTI_RISING_EDGE || (p->triggerType) == EXTI_RISING_AND_FALLING){
		EXTI->RTSR |= (1<<(p->lineNum));
	}
	if((p->triggerType) == EXTI_FALLING_EDGE){
		EXTI->FTSR |= (1<<(p->lineNum));
	}
}

void EXTI_softwareInterruptMask(uint8_t lineNum)
{
	EXTI->IMR |=(1<<lineNum);
	EXTI->SWIER |=(1<<lineNum);
}

void EXTI_softwareEventMask(uint8_t lineNum)
{
	EXTI->EMR |=(1<<lineNum);
	EXTI->SWIER |=(1<<lineNum);
}

void EXTI_clearFlag(uint8_t lineNum)
{
	EXTI->PR |=(1<<lineNum);
}
