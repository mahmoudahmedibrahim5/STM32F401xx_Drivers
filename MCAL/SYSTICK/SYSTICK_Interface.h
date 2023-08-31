/*
 * SYSTICK_Interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SYSTICK_SYSTICK_INTERFACE_H_
#define SYSTICK_SYSTICK_INTERFACE_H_

#include "../../Utilities/STD_TYPES.h"
#include "SYSTICK_Registers.h"
#include "SYSTICK_Config.h"

void SYSTICK_voidInit(void);

void SYSTICK_voidDelayMilliSec(uint32_t ms);
void SYSTICK_voidDelayMicroSec(uint32_t us);

uint32_t SYSTICK_u32GetElapsedTime(void);
uint32_t SYSTICK_u32GetRemainingTime(void);

void SYSTICK_voidEnableInterrupt(void);
void SYSTICK_voidStartCountMilliSeconds(uint32_t ms, void(*ptr)(void));
void SYSTICK_voidStartCountMicroSeconds(uint32_t us, void(*ptr)(void));

void SYSTICK_voidSetCallBackFunction( void(*ptr)(void) );

#endif /* SYSTICK_SYSTICK_INTERFACE_H_ */
