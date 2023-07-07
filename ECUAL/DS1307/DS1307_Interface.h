/*
 * DS1307_Interface.h
 *
 *  Created on: Jul 6, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef DS1307_DS1307_INTERFACE_H_
#define DS1307_DS1307_INTERFACE_H_

#include "../MCAL/I2C/I2C_Interface.h"
#include "DS1307_Config.h"

#define DS1307_ADDR		0x68

void DS1307_init(DS1307_Handle_t* rtc);
void DS1307_read(DS1307_Handle_t* rtc);

#endif /* DS1307_DS1307_INTERFACE_H_ */
