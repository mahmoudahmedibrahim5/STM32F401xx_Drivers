/*
 * RCC_Program.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "RCC_Registers.h"
#include "RCC_Interface.h"

void RCC_peripheralEn(En_peripheral_t per)
{
	switch(per)
	{
	case GPIOA_EN:
			RCC->AHB1ENR |= (1<<0);
			break;
	case GPIOB_EN:
			RCC->AHB1ENR |= (1<<1);
			break;
	case GPIOC_EN:
			RCC->AHB1ENR |= (1<<2);
			break;
	case GPIOD_EN:
			RCC->AHB1ENR |= (1<<3);
			break;
	case GPIOE_EN:
			RCC->AHB1ENR |= (1<<4);
			break;
	case GPIOH_EN:
			RCC->AHB1ENR |= (1<<7);
			break;
	default:
		break;
	}
}
