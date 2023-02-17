/*
 * RCC_Program.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "../../Utilities/stm32f401xx.h"
#include "RCC_Registers.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"

void RCC_init()
{
#if HSI
	RCC->CR |= (1<<0);
	RCC->CFGR &= ~(11<<0);
	RCC->CFGR |= (10<<0);
#elif HSE
	RCC->CR |= (1<<16);
	RCC->CFGR &= ~(11<<0);
	RCC->CFGR |= (01<<0);
#elif PLL
	RCC->CR |= (1<<24);
	RCC->CFGR &= ~(11<<0);
	RCC->CFGR |= (10<<0);
#endif
	/* AHB Prescaler */
	if(AHB_PRESCALER == 1){
		RCC->CFGR &= ~(1<<7);
	}
	else{
		RCC->CFGR |= (1<<7);
		RCC->CFGR &= ~(111<<4);
		switch(AHB_PRESCALER)
		{
		case 2:
			RCC->CFGR |= (000<<4);
			break;
		case 4:
			RCC->CFGR |= (001<<4);
			break;
		case 8:
			RCC->CFGR |= (010<<4);
			break;
		case 16:
			RCC->CFGR |= (011<<4);
			break;
		case 64:
			RCC->CFGR |= (100<<4);
			break;
		case 128:
			RCC->CFGR |= (101<<4);
			break;
		case 256:
			RCC->CFGR |= (110<<4);
			break;
		case 512:
			RCC->CFGR |= (111<<4);
			break;
		default:
			// error
			break;
		}
	}
	/* APB1 Prescaler */
	if(APB1_PRESCALER == 1){
			RCC->CFGR &= ~(1<<12);
	}
	else{
		RCC->CFGR |= (1<<12);
		RCC->CFGR &= ~(11<<10);
		switch(AHB_PRESCALER)
		{
		case 2:
			RCC->CFGR |= (00<<10);
			break;
		case 4:
			RCC->CFGR |= (01<<10);
			break;
		case 8:
			RCC->CFGR |= (10<<10);
			break;
		case 16:
			RCC->CFGR |= (11<<10);
			break;
		default:
			//error
			break;
		}
	}
	/* APB2 Prescaler */
	if(APB2_PRESCALER == 1){
			RCC->CFGR &= ~(1<<15);
	}
	else{
		RCC->CFGR |= (1<<15);
		RCC->CFGR &= ~(11<<13);
		switch(AHB_PRESCALER)
		{
		case 2:
			RCC->CFGR |= (00<<13);
			break;
		case 4:
			RCC->CFGR |= (01<<13);
			break;
		case 8:
			RCC->CFGR |= (10<<13);
			break;
		case 16:
			RCC->CFGR |= (11<<13);
			break;
		default:
			//error
			break;
		}
	}
}

void RCC_peripheralEn(En_peripheral_t per)
{
	switch(per)
	{
	/* AHB1 */
	case GPIOA_EN:
			RCC->AHB1ENR |= (1<<0);
			break;
	case GPIOB_EN:
			RCC->AHB1ENR |= (1<<1);
			break;
	case GPIOC_EN:
			RCC->AHB1ENR |= (1<<2);
			break;
	case GPIOD_EN:
			RCC->AHB1ENR |= (1<<3);
			break;
	case GPIOE_EN:
			RCC->AHB1ENR |= (1<<4);
			break;
	case GPIOH_EN:
			RCC->AHB1ENR |= (1<<7);
			break;
	case CRC_EN:
			RCC->AHB1ENR |= (1<<12);
			break;
	case DMA1_EN:
			RCC->AHB1ENR |= (1<<21);
			break;
	case DMA2_EN:
			RCC->AHB1ENR |= (1<<22);
			break;
	/* AHB2 */
	case OTGFS_EN:
			RCC->AHB2ENR |= (1<<7);
			break;
	/* APB1 */
	case TIM2_EN:
			RCC->APB1ENR |= (1<<0);
			break;
	case TIM3_EN:
			RCC->APB1ENR |= (1<<1);
			break;
	case TIM4_EN:
			RCC->APB1ENR |= (1<<2);
			break;
	case TIM5_EN:
			RCC->APB1ENR |= (1<<3);
			break;
	case WWDG_EN:
			RCC->APB1ENR |= (1<<11);
			break;
	case SPI2_EN:
			RCC->APB1ENR |= (1<<14);
			break;
	case SPI3_EN:
			RCC->APB1ENR |= (1<<15);
			break;
	case USART2_EN:
			RCC->APB1ENR |= (1<<17);
			break;
	case I2C1_EN:
			RCC->APB1ENR |= (1<<21);
			break;
	case I2C2_EN:
			RCC->APB1ENR |= (1<<22);
			break;
	case I2C3_EN:
			RCC->APB1ENR |= (1<<23);
			break;
	case PWR_EN:
			RCC->APB1ENR |= (1<<28);
			break;
	/* APB2 */
	case TIM1_EN:
			RCC->APB2ENR |= (1<<0);
			break;
	case USART1_EN:
			RCC->APB2ENR |= (1<<4);
			break;
	case USART6_EN:
			RCC->APB2ENR |= (1<<5);
			break;
	case ADC1_EN:
			RCC->APB2ENR |= (1<<8);
			break;
	case SDIO_EN:
			RCC->APB2ENR |= (1<<11);
			break;
	case SPI1_EN:
			RCC->APB2ENR |= (1<<12);
			break;
	case SPI4_EN:
			RCC->APB2ENR |= (1<<13);
			break;
	case SYSCFG_EN:
			RCC->APB2ENR |= (1<<14);
			break;
	case TIM9_EN:
			RCC->APB2ENR |= (1<<16);
			break;
	case TIM10_EN:
			RCC->APB2ENR |= (1<<17);
			break;
	case TIM11_EN:
			RCC->APB2ENR |= (1<<18);
			break;
	default:
		break;
	}
}

void RCC_peripheralLowPowerEn(En_peripheral_t per)
{
	switch(per)
		{
		/* AHB1 */
		case GPIOA_EN:
				RCC->AHB1LPENR |= (1<<0);
				break;
		case GPIOB_EN:
				RCC->AHB1LPENR |= (1<<1);
				break;
		case GPIOC_EN:
				RCC->AHB1LPENR |= (1<<2);
				break;
		case GPIOD_EN:
				RCC->AHB1LPENR |= (1<<3);
				break;
		case GPIOE_EN:
				RCC->AHB1LPENR |= (1<<4);
				break;
		case GPIOH_EN:
				RCC->AHB1LPENR |= (1<<7);
				break;
		case CRC_EN:
				RCC->AHB1LPENR |= (1<<12);
				break;
		case DMA1_EN:
				RCC->AHB1LPENR |= (1<<21);
				break;
		case DMA2_EN:
				RCC->AHB1LPENR |= (1<<22);
				break;
		/* AHB2 */
		case OTGFS_EN:
				RCC->AHB2LPENR |= (1<<7);
				break;
		/* APB1 */
		case TIM2_EN:
				RCC->APB1LPENR |= (1<<0);
				break;
		case TIM3_EN:
				RCC->APB1LPENR |= (1<<1);
				break;
		case TIM4_EN:
				RCC->APB1LPENR |= (1<<2);
				break;
		case TIM5_EN:
				RCC->APB1LPENR |= (1<<3);
				break;
		case WWDG_EN:
				RCC->APB1LPENR |= (1<<11);
				break;
		case SPI2_EN:
				RCC->APB1LPENR |= (1<<14);
				break;
		case SPI3_EN:
				RCC->APB1LPENR |= (1<<15);
				break;
		case USART2_EN:
				RCC->APB1LPENR |= (1<<17);
				break;
		case I2C1_EN:
				RCC->APB1LPENR |= (1<<21);
				break;
		case I2C2_EN:
				RCC->APB1LPENR |= (1<<22);
				break;
		case I2C3_EN:
				RCC->APB1LPENR |= (1<<23);
				break;
		case PWR_EN:
				RCC->APB1LPENR |= (1<<28);
				break;
		/* APB2 */
		case TIM1_EN:
				RCC->APB2LPENR |= (1<<0);
				break;
		case USART1_EN:
				RCC->APB2LPENR |= (1<<4);
				break;
		case USART6_EN:
				RCC->APB2LPENR |= (1<<5);
				break;
		case ADC1_EN:
				RCC->APB2LPENR |= (1<<8);
				break;
		case SDIO_EN:
				RCC->APB2LPENR |= (1<<11);
				break;
		case SPI1_EN:
				RCC->APB2LPENR |= (1<<12);
				break;
		case SPI4_EN:
				RCC->APB2LPENR |= (1<<13);
				break;
		case SYSCFG_EN:
				RCC->APB2LPENR |= (1<<14);
				break;
		case TIM9_EN:
				RCC->APB2LPENR |= (1<<16);
				break;
		case TIM10_EN:
				RCC->APB2LPENR |= (1<<17);
				break;
		case TIM11_EN:
				RCC->APB2LPENR |= (1<<18);
				break;
		default:
			break;
		}
}

void RCC_peripheralReset(En_peripheral_t per)
{
	switch(per)
	{
		/* AHB1 */
		case GPIOA_EN:
				RCC->AHB1RSTR |= (1<<0);
				break;
		case GPIOB_EN:
				RCC->AHB1RSTR |= (1<<1);
				break;
		case GPIOC_EN:
				RCC->AHB1RSTR |= (1<<2);
				break;
		case GPIOD_EN:
				RCC->AHB1RSTR |= (1<<3);
				break;
		case GPIOE_EN:
				RCC->AHB1RSTR |= (1<<4);
				break;
		case GPIOH_EN:
				RCC->AHB1RSTR |= (1<<7);
				break;
		case CRC_EN:
				RCC->AHB1RSTR |= (1<<12);
				break;
		case DMA1_EN:
				RCC->AHB1RSTR |= (1<<21);
				break;
		case DMA2_EN:
				RCC->AHB1RSTR |= (1<<22);
				break;
		/* AHB2 */
		case OTGFS_EN:
				RCC->AHB2RSTR |= (1<<7);
				break;
		/* APB1 */
		case TIM2_EN:
				RCC->APB1RSTR |= (1<<0);
				break;
		case TIM3_EN:
				RCC->APB1RSTR |= (1<<1);
				break;
		case TIM4_EN:
				RCC->APB1RSTR |= (1<<2);
				break;
		case TIM5_EN:
				RCC->APB1RSTR |= (1<<3);
				break;
		case WWDG_EN:
				RCC->APB1RSTR |= (1<<11);
				break;
		case SPI2_EN:
				RCC->APB1RSTR |= (1<<14);
				break;
		case SPI3_EN:
				RCC->APB1RSTR |= (1<<15);
				break;
		case USART2_EN:
				RCC->APB1RSTR |= (1<<17);
				break;
		case I2C1_EN:
				RCC->APB1RSTR |= (1<<21);
				break;
		case I2C2_EN:
				RCC->APB1RSTR |= (1<<22);
				break;
		case I2C3_EN:
				RCC->APB1RSTR |= (1<<23);
				break;
		case PWR_EN:
				RCC->APB1RSTR |= (1<<28);
				break;
		/* APB2 */
		case TIM1_EN:
				RCC->APB2RSTR |= (1<<0);
				break;
		case USART1_EN:
				RCC->APB2RSTR |= (1<<4);
				break;
		case USART6_EN:
				RCC->APB2RSTR |= (1<<5);
				break;
		case ADC1_EN:
				RCC->APB2RSTR |= (1<<8);
				break;
		case SDIO_EN:
				RCC->APB2RSTR |= (1<<11);
				break;
		case SPI1_EN:
				RCC->APB2RSTR |= (1<<12);
				break;
		case SPI4_EN:
				RCC->APB2RSTR |= (1<<13);
				break;
		case SYSCFG_EN:
				RCC->APB2RSTR |= (1<<14);
				break;
		case TIM9_EN:
				RCC->APB2RSTR |= (1<<16);
				break;
		case TIM10_EN:
				RCC->APB2RSTR |= (1<<17);
				break;
		case TIM11_EN:
				RCC->APB2RSTR |= (1<<18);
				break;
		default:
			break;
	}
}

void RCC_softwareReset(void)
{
	// AIRCR
}
