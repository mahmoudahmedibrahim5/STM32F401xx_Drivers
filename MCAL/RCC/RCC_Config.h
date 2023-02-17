/*
 * RCC_Config.h
 *
 *  Created on: Feb 16, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_

#define HSI 1
#define HSE 0
#define PLL 0

// 1, 2, 4, 8, 16, 64, 128, 256, 512
#define AHB_PRESCALER  1 // 1, 2, 4, 8, 16, 64, 128, 256, 512
#define APB1_PRESCALER 1 // 2, 4, 8, 16
#define APB2_PRESCALER 1 // 2, 4, 8, 16

#endif /* RCC_RCC_CONFIG_H_ */
