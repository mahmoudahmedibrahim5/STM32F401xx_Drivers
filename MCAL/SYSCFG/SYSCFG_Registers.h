/*
 * SYSCFG_Registers.h
 *
 *  Created on: Feb 23, 2023
 *      Author: ADMIN
 */

#ifndef SYSCFG_SYSCFG_REGISTERS_H_
#define SYSCFG_SYSCFG_REGISTERS_H_

typedef struct{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t CMPCR;
}st_SYSCFG_RegDef_t;

#define SYSCFG	((st_SYSCFG_RegDef_t *) SYSCFG_BASE_ADDR)

#endif /* SYSCFG_SYSCFG_REGISTERS_H_ */
