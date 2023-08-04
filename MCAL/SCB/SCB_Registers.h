/*
 * SCB_Registers.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Mahmoud Ahmed Ibrahim Ahmed
 */

#ifndef SCB_SCB_REGISTERS_H_
#define SCB_SCB_REGISTERS_H_

#include "../../Utilities/DataTypes.h"

#define SCB_BASE_ADDR		0xE000ED00

typedef struct{
	uint32_t CPUID;
	uint32_t ICSR;
	uint32_t VTOR;
	uint32_t AIRCR;
	uint32_t SCR;
	uint32_t CCR;
	uint32_t SHPR1;
	uint32_t SHPR2;
	uint32_t SHPR3;
	uint32_t SHCSR;
	uint32_t CFSR;
	uint32_t HFSR;
	uint32_t reserved;
	uint32_t MMAR;
	uint32_t BFAR;
	uint32_t AFSR;
}st_SCB_RegDef_t;

#define SCB					((st_SCB_RegDef_t *)SCB_BASE_ADDR)

#endif /* SCB_SCB_REGISTERS_H_ */
