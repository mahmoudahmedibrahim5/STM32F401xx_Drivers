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
uint8_t NVIC_getPendingIRQ(uint8_t IRQn);


#endif /* NVIC_NVIC_INTERFACE_H_ */
