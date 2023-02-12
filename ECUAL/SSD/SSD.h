/*
 * SSD.h
 *
 *  Created on: Feb 12, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SSD_H_
#define SSD_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"

#define ON 	1
#define OFF 0

/* Seven segment type */
#define COM_CATHODE 	0
#define COM_ANODE 		1

typedef struct{
	En_Port_t port;
	uint8_t pins[8]; // pins in order [a, b, c, d, e, f, g, DB]
}SSD_t;

void SSD_init(SSD_t *SSD, uint8_t type);
void SSD_setNumber(SSD_t *SSD, uint8_t num);
void SSD_setDecimalPoint(SSD_t *SSD, uint8_t value);
void SSD_turnOFF(SSD_t *SSD);

#endif
