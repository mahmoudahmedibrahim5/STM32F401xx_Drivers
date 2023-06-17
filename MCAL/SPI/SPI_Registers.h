/*
 * SPI_Registers.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SPI_SPI_REGISTERS_H_
#define SPI_SPI_REGISTERS_H_

#include "../../Utilities/stm32f401xx.h"

typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;
}st_SPI_RegDef_t;

#define SPI1		((st_SPI_RegDef_t *)SPI1_BASE_ADDR)
#define SPI2		((st_SPI_RegDef_t *)SPI2_BASE_ADDR)
#define SPI3		((st_SPI_RegDef_t *)SPI3_BASE_ADDR)
#define SPI4		((st_SPI_RegDef_t *)SPI4_BASE_ADDR)

#endif /* SPI_SPI_REGISTERS_H_ */
