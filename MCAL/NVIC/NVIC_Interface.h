/*
 * NVIC_Interface.h
 *
 *  Created on: Feb 22, 2023
 *      Author: ADMIN
 */

#ifndef NVIC_NVIC_INTERFACE_H_
#define NVIC_NVIC_INTERFACE_H_

#include "../../Utilities/stm32f401xx.h"
#include "NVIC_Registers.h"

void NVIC_enableIRQ(uint8_t IRQn);
void NVIC_disableIRQ(uint8_t IRQn);

void NVIC_setPendingIRQ(uint8_t IRQn);
void NVIC_clearPendingIRQ(uint8_t IRQn);

void NVIC_setPriority(uint8_t IRQn, uint8_t priority);
uint8_t NVIC_getPriority(uint8_t IRQn);

#define EXTI0		6
#define EXTI1		7
#define EXTI2		8
#define EXTI3		9
#define EXTI4		10

#define I2C1_EV		31
#define I2C1_ER		32
#define I2C2_EV		33
#define I2C2_ER		34
#define I2C3_EV		72
#define I2C3_ER		73

#endif /* NVIC_NVIC_INTERFACE_H_ */
