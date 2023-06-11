/*
 * NVIC_Program.c
 *
 *  Created on: Feb 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "NVIC_Interface.h"

void NVIC_enableIRQ(uint8_t IRQn)
{
	// To know which register we will use, ex: ISER0, ISER1, ...
	uint8_t index = IRQn/32;
	NVIC_ISER[index] |= (uint32_t)(1<<(IRQn-32*index));
}

void NVIC_disableIRQ(uint8_t IRQn)
{
	// To know which register we will use, ex: ICER0, ICER1, ...
	uint8_t index = IRQn/32;
	NVIC_ICER[index] |= (uint32_t)(1<<(IRQn-32*index));
}

