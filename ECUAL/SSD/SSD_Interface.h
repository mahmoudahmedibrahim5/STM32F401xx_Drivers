/*
 * SSD.h
 *
 *  Created on: Feb 12, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SSD_H_
#define SSD_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"

typedef struct{
	EN_Port_t port;
	u8 pins[8]; // pins in order [a, b, c, d, e, f, g, DB]
}SSD_t;

void SSD_voidInit(SSD_t *SSD);
void SSD_voidSetNumber(SSD_t *SSD, u8 num);
void SSD_voidSetDecimalPoint(SSD_t *SSD, u8 value);
void SSD_voidTurnOFF(SSD_t *SSD);

#endif
