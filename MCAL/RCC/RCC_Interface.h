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
	// AHB1
	GPIOA_EN,
	GPIOB_EN,
	GPIOC_EN,
	GPIOD_EN,
	GPIOE_EN,
	GPIOH_EN,
	CRC_EN,
	DMA1_EN,
	DMA2_EN,
	// AHB2
	OTGFS_EN,
	// APB1
	TIM2_EN,
	TIM3_EN,
	TIM4_EN,
	TIM5_EN,
	WWDG_EN,
	SPI2_EN,
	SPI3_EN,
	USART2_EN,
	I2C1_EN,
	I2C2_EN,
	I2C3_EN,
	PWR_EN,
	// APB2
	TIM1_EN,
	USART1_EN,
	USART6_EN,
	ADC1_EN,
	SDIO_EN,
	SPI1_EN,
	SPI4_EN,
	SYSCFG_EN,
	TIM9_EN,
	TIM10_EN,
	TIM11_EN
}En_peripheral_t;

void RCC_peripheralEn(En_peripheral_t per);
void RCC_peripheralLowPowerEn(En_peripheral_t per);
void RCC_peripheralReset(En_peripheral_t per);

#endif /* RCC_RCC_INTERFACE_H_ */
