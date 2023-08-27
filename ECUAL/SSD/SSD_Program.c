/*
 * SSD.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "SSD_Interface.h"

GPIO_Config_t SSD_config = {GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_LOW_SPEED, GPIO_NO_PUPD, 0};
u8 SSD_Numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void SSD_voidInit(SSD_t *SSD)
{
	for(u8 i=0; i<8; i++)
	{
		GPIO_initPin(SSD->port, SSD->pins[i], &SSD_config);
	}
}

void SSD_voidSetNumber(SSD_t *SSD, u8 num)
{
	if(num < 10)
	{
		for(u8 i=0; i<7; i++)
		{
			GPIO_setPinValue(SSD->port, SSD->pins[i],((SSD_Numbers[num]&(1<<i))>>i));
		}
	}
}

void SSD_voidSetDecimalPoint(SSD_t *SSD, u8 value)
{
	GPIO_setPinValue(SSD->port, SSD->pins[7], value);
}

void SSD_voidTurnOFF(SSD_t *SSD)
{
	for(u8 i=0; i<8; i++)
	{
		GPIO_setPinValue(SSD->port, SSD->pins[i], LOW);
	}
}
