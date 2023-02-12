/*
 * RCC_Interface.h
 *
 *  Created on: Feb 8, 2023
 *      Author: MAhmoud Ahmed Ibrahim
 */

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_

#include "RCC_Registers.h"

typedef enum {
	GPIOA_EN,
	GPIOB_EN,
	GPIOC_EN,
	GPIOD_EN,
	GPIOE_EN,
	GPIOH_EN,
	CRC_EN,
	DMA1_EN,
	DMA2_EN,
	OTGFS_EN
	// to be continued
}En_peripheral_t;
void RCC_peripheralEn(En_peripheral_t per);

#endif /* RCC_RCC_INTERFACE_H_ */
