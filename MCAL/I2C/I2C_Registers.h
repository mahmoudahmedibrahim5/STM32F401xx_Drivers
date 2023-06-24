/*
 * I2C_Registers.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef I2C_I2C_REGISTERS_H_
#define I2C_I2C_REGISTERS_H_

#include "../../Utilities/stm32f401xx.h"

typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;
}st_I2C_RegDef_t;

#define I2C1	((st_I2C_RegDef_t *)I2C1_BASE_ADDR)
#define I2C2	((st_I2C_RegDef_t *)I2C2_BASE_ADDR)
#define I2C3	((st_I2C_RegDef_t *)I2C3_BASE_ADDR)

/* CR1 Register Bits */
#define I2C_PE		0
#define I2C_START	8
#define I2C_STOP	9
#define I2C_ACK		10

/* SR1 Register Flags */
#define I2C_SB_FLAG		0
#define I2C_ADDR_FLAG	1
#define	I2C_BTF_FLAG	2
#define I2C_STOPF_FLAG	4
#define I2C_RXNE_FLAG	6
#define I2C_TXE_FLAG	7
#define I2C_AF_FLAG		10

#endif /* I2C_I2C_REGISTERS_H_ */
