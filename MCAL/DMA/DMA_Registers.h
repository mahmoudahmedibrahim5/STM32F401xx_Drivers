/*
 * DMA_Registers.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef DMA_DMA_REGISTERS_H_
#define DMA_DMA_REGISTERS_H_

#define DMA1_BASE_ADDR					0x40026000U
#define DMA2_BASE_ADDR					0x40026400U

typedef volatile struct{
	u32 SCR;
	u32 SNDTR;
	u32 SPAR;
	u32 SM0AR;
	u32 SM1AR;
	u32 SFCR;
}st_DMA_Channel_RegDef_t;

typedef volatile struct{
	u32 LISR;
	u32 HISR;
	u32 LIFCR;
	u32 HIFCR;
	st_DMA_Channel_RegDef_t stream[8];
}st_DMA_RegDef_t;

#define DMA1		((st_DMA_RegDef_t *) DMA1_BASE_ADDR)
#define DMA2		((st_DMA_RegDef_t *) DMA2_BASE_ADDR)

#endif /* DMA_DMA_REGISTERS_H_ */
