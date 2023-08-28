/*
 * DMA_Program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "DMA_Interface.h"

void DMA_voidInit(st_DMA_RegDef_t* DMAn, u8 stream, DMA_Cofig_t* config)
{
	/* Clear Enable */
	DMAn->stream[stream].SCR &= ~(1<<0);

	/* Set The Priority very high */
	DMAn->stream[stream].SCR |= (0b11<<16);

	/* Set Direction mode */
	DMAn->stream[stream].SCR |= (0b10<<6);

	/* Select Circular mode */
	DMAn->stream[stream].SCR |= (1<<8);

	/* Set Source Size */
	DMAn->stream[stream].SCR |= (0b10<<11);

	/* Set Destination Size */
	DMAn->stream[stream].SCR |= (0b10<<13);

	/* Disable Direct mode */
	DMAn->stream[stream].SFCR |= (1<<2);

	/* Set Threshold */
	DMAn->stream[stream].SFCR |= (0b11<<0);

	/* SRC & DIS Increment for Both */
	DMAn->stream[stream].SCR |= (1<<9);
	DMAn->stream[stream].SCR |= (1<<10);

	/* Enable Interrupt of Transfer Complete */
	DMAn->stream[stream].SCR |= (1<<4);
}

void DMA_voidStreamEnable(st_DMA_RegDef_t* DMAn, u8 stream)
{
	DMA1->LIFCR |= (0b111101<<0);
	DMAn->stream[stream].SCR |= (1<<0);
}

void DMA_voidSetAddress(u32* src, u32* dst, u32 dataSize, u8 stream)
{
	DMA1->stream[stream].SPAR = (u32)src;
	DMA1->stream[stream].SM0AR = (u32)dst;
	DMA1->stream[stream].SNDTR = dataSize;
}
