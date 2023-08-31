/*
 * SCB_Registers.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Mahmoud Ahmed Ibrahim Ahmed
 */

#ifndef SCB_SCB_REGISTERS_H_
#define SCB_SCB_REGISTERS_H_

#define SCB_BASE_ADDR			0xE000ED00U

typedef volatile struct{
	u32 CPUID;
	u32 ICSR;
	u32 VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3;
	u32 SHCSR;
	u32 CFSR;
	u32 HFSR;
	u32 reserved;
	u32 MMAR;
	u32 BFAR;
	u32 AFSR;
}st_SCB_RegDef_t;

#define SCB					((st_SCB_RegDef_t *)SCB_BASE_ADDR)

#endif /* SCB_SCB_REGISTERS_H_ */
