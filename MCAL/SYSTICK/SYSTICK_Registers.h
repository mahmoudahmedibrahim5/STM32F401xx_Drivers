/*
 * SYSTICK_Registers.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SYSTICK_SYSTICK_REGISTERS_H_
#define SYSTICK_SYSTICK_REGISTERS_H_

#define SYSTICK_BASE_ADDR	0xE000E010

typedef volatile struct{
	uint32_t CTRL;
	uint32_t LOAD;
	uint32_t VAL;
	uint32_t CALIB;
}st_SYSTICK_RegDef_t;

#define SYSTICK		((st_SYSTICK_RegDef_t *) SYSTICK_BASE_ADDR)

#endif /* SYSTICK_SYSTICK_REGISTERS_H_ */
