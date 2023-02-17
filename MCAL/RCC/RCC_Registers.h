/*
 * RCC_Registers.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef RCC_RCC_REGISTERS_H_
#define RCC_RCC_REGISTERS_H_

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	uint32_t r1[2]; //reserved
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	uint32_t r2[2]; //reserved
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	uint32_t r3[2]; //reserved
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	uint32_t r4[2]; //reserved
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	uint32_t r5[2]; //reserved
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	uint32_t r6[2]; //reserved
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	uint32_t r7[2]; //reserved
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	uint32_t r8; //reserved
	volatile uint32_t DCKCFGR;
}st_RCC_RegDef_t;

#define RCC		((st_RCC_RegDef_t *)RCC_BASE_ADDR)

#endif /* RCC_RCC_REGISTERS_H_ */
