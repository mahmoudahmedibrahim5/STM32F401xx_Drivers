/*
 * EXTI_Registers.h
 *
 *  Created on: Jun 11, 2023
 *      Author: ADMIN
 */

#ifndef EXTI_EXTI_REGISTERS_H_
#define EXTI_EXTI_REGISTERS_H_

typedef struct{
	uint32_t IMR;
	uint32_t EMR;
	uint32_t RTSR;
	uint32_t FTSR;
	uint32_t SWIER;
	uint32_t PR;
}st_EXTI_RegDef_t;

#define EXTI	((st_EXTI_RegDef_t *) EXTI_BASE_ADDR)

#endif /* EXTI_EXTI_REGISTERS_H_ */
