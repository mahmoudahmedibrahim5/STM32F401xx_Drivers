/*
 * DMA_Config.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef DMA_DMA_CONFIG_H_
#define DMA_DMA_CONFIG_H_

typedef struct{
	u8 transferDirection;
	u8 srcDataSize;
	u8 dstDataSize;
	u8 mode;
}DMA_Cofig_t;

/* Transfer Directions */
#define DMA_PERIPHERAL_TO_MEMORY	0
#define DMA_MEMORY_TO_MEMORY		1
#define DMA_MEMORY_TO_PERIPHERAL	2

/* Data Size */
#define DMA_DATA_SIZE_8_BIT			0
#define DMA_DATA_SIZE_16_BIT		1
#define DMA_DATA_SIZE_32_BIT		2

/* Modes */
#define DMA_MODE_DIRECT				0
#define DMA_MODE_CIRCULAR			1

#endif /* DMA_DMA_CONFIG_H_ */
