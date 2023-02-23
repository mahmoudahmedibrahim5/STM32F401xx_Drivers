/*
 * NVIC_Registers.h
 *
 *  Created on: Feb 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef NVIC_NVIC_REGISTERS_H_
#define NVIC_NVIC_REGISTERS_H_

typedef struct{
	uint32_t IMR;
	uint32_t EMR;
	uint32_t RTSR;
	uint32_t FTSR;
	uint32_t SWIER;
	uint32_t PR;
}st_EXTI_RegDef_t;

#define EXTI	((st_EXTI_RegDef_t *) EXTI_BASE_ADDR)

#endif /* NVIC_NVIC_REGISTERS_H_ */
