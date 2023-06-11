/*
 * SYSCFG_Interface.h
 *
 *  Created on: Feb 23, 2023
 *      Author: ADMIN
 */

#ifndef SYSCFG_SYSCFG_INTERFACE_H_
#define SYSCFG_SYSCFG_INTERFACE_H_

#include "../../Utilities/stm32f401xx.h"
#include "../GPIO/GPIO_Interface.h"
#include "SYSCFG_Registers.h"

void SYSCFG_EXTIcontrol(En_Port_t port, uint8_t lineNum);

#endif /* SYSCFG_SYSCFG_INTERFACE_H_ */
