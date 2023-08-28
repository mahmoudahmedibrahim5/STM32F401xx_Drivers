/*
 * DMA_Interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef DMA_DMA_INTERFACE_H_
#define DMA_DMA_INTERFACE_H_

#include "../../Utilities/DataTypes.h"
#include "DMA_Registers.h"
#include "DMA_Config.h"

void DMA_voidInit(st_DMA_RegDef_t* DMAn, u8 stream, DMA_Cofig_t* config);
void DMA_voidStreamEnable(st_DMA_RegDef_t* DMAn, u8 stream);
void DMA_voidSetAddress(u32* src, u32* dst, u32 dataSize, u8 stream);

#endif /* DMA_DMA_INTERFACE_H_ */
