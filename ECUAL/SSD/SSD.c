/*
 * SSD.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "SSD.h"

GPIO_Config_t SSD_config = {OUT, PUSH_PULL, LOW_SPEED, NO_PUPD, 0};
uint8_t Type;
uint8_t  SSD_Numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void SSD_init(SSD_t *SSD, uint8_t type)
{
	for(uint8_t i=0; i<8; i++)
	{
		GPIO_initPin(SSD->port, SSD->pins[i], &SSD_config);
	}
	Type = type;
}

void SSD_setNumber(SSD_t *SSD, uint8_t num)
{
	if(num < 10)
	{
		for(uint8_t i=0; i<7; i++)
		{
			GPIO_setPinValue(SSD->port, SSD->pins[i],((SSD_Numbers[num]&(1<<i))>>i));
		}
	}
}

void SSD_setDecimalPoint(SSD_t *SSD, uint8_t value)
{
	GPIO_setPinValue(SSD->port, SSD->pins[7], value);
}

void SSD_turnOFF(SSD_t *SSD)
{
	for(uint8_t i=0; i<8; i++)
	{
		GPIO_setPinValue(SSD->port, SSD->pins[i], LOW);
	}
}
