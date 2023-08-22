/*
 * SYSTICK_Program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */


#include "SYSTICK_Interface.h"

void SYSTICK_voidInit(void)
{
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1)
	SYSTICK->CTRL |= (1<<2);
#else
	SYSTICK->CTRL &= ~(1<<2);
#endif
}

/* Delay Functions */
void SYSTICK_voidDelayMilliSec(uint32_t ms)
{
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1)
	SYSTICK->LOAD = 16000*ms;
#elif(SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV8)
	SYSTICK->LOAD = 2000*ms;
#endif
	SYSTICK->VAL = 0;
	SYSTICK->CTRL |= (1<<0);
	while(!((SYSTICK->CTRL>>16) & 1));
	SYSTICK->CTRL &= ~(1<<0);
}

void SYSTICK_voidDelayMicroSec(uint32_t us)
{
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1)
	SYSTICK->LOAD = 16*us;
#elif(SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV8)
	SYSTICK->LOAD = 2*us;
#endif
	SYSTICK->VAL = 0;
	SYSTICK->CTRL |= (1<<0);
	while(!((SYSTICK->CTRL>>16) & 1));
	SYSTICK->CTRL &= ~(1<<0);
}

/* Elapsed and remaining time */
uint32_t SYSTICK_uint32_tGetElapsedTime(void)
{
	return (SYSTICK->LOAD - SYSTICK->VAL);
}

uint32_t SYSTICK_uint32_tGetRemainingTime(void)
{
	return SYSTICK->VAL;
}

/* Interrupt Functions */
void SYSTICK_voidEnableInterrupt(void)
{
	SYSTICK->CTRL |= (1<<1);
}

void SYSTICK_voidStartCountMilliSeconds(uint32_t ms, void(*ptr)(void))
{
	SYSTICK_voidEnableInterrupt();
	SYSTICK_voidSetCallBackFunction(ptr);
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1)
	SYSTICK->LOAD = 16000*ms;
#elif(SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV8)
	SYSTICK->LOAD = 2000*ms;
#endif
	SYSTICK->VAL = 0;
	SYSTICK->CTRL |= (1<<0);
}

void SYSTICK_voidStartCountMicroSeconds(uint32_t us, void(*ptr)(void))
{
	SYSTICK_voidEnableInterrupt();
	SYSTICK_voidSetCallBackFunction(ptr);
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1)
	SYSTICK->LOAD = 16*us;
#elif(SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV8)
	SYSTICK->LOAD = 2*us;
#endif
	SYSTICK->VAL = 0;
	SYSTICK->CTRL |= (1<<0);
}

void (*SYSTICK_CallBack)(void);

void SYSTICK_voidSetCallBackFunction( void(*ptr)(void) )
{
	SYSTICK_CallBack = ptr;
}

void SysTick_Handler(void)
{
	SYSTICK_CallBack();
#if	(SYSTICK_INTERPUT == SYSTICK_NON_PERIODIC)
	SYSTICK->CTRL &= ~(1<<2); // Stop the timer
#endif
}
