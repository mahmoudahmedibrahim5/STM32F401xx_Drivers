/*
 * SPI_Program.c
 *
 *  Created on: Jun 15, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "SPI_Interface.h"
#include "../GPIO/GPIO_Interface.h"


void SPI_init(st_SPI_RegDef_t* SPIn, SPI_Config_t* config){
	SPI_configurePins(SPIn);

	switch(config->dataOrder)
	{
	case 0: // MSB first
		SPIn->CR1 &= ~(1<<7);
		break;
	case 1: // LSB first
		SPIn->CR1 |= (1<<7);
		break;
	}

	switch(config->dataSize)
	{
	case 0: // 8 bit
		SPIn->CR1 &= ~(1<<11);
		break;
	case 1: // 16 bit
		SPIn->CR1 |= (1<<11);
		break;
	}

	switch(config->software)
	{
	case 0: // Hardware
		SPIn->CR1 &= ~(1<<9);
		break;
	case 1: // Software
		SPIn->CR1 |= (1<<9);
		break;
	}

	switch(config->clockMode)
	{// To be continued
	case 0:
		break;
	case 1:
		break;
	}

	switch(config->mode)
	{
	case 0:
		SPIn->CR2 &= ~(1<<2); // SSOE pin low to make the SS pin input
		SPIn->CR1 &= ~(1<<2); // Slave mode
		break;
	case 1:
		SPIn->CR2 |= (1<<2); // SSOE pin high to make the SS pin output
		// Set the BaudRate
		SPIn->CR1 &= ~(111<<3);
		SPIn->CR1 |= (config->baudrate<<3);
		SPIn->CR1 |= (1<<2); // Master mode
		break;
	}
}

void SPI_enable(st_SPI_RegDef_t* SPIn){
	// Enable SPI
	SPIn->CR1 |= (1<<6);
}

void SPI_disable(st_SPI_RegDef_t* SPIn){
	// wait until communication finished
	while(SPIn->SR &(1<<7));
	// Disable SPI
	SPIn->CR1 &= ~(1<<6);
}

void SPI_configurePins(st_SPI_RegDef_t* SPIn){
	GPIO_Config_t spiConfig;
	spiConfig.mode = ALT_FN;
	spiConfig.outType = PUSH_PULL;
	spiConfig.pupdState = NO_PUPD;
	spiConfig.speed = HIGH_SPEED;

	if(SPIn == SPI1){
		spiConfig.AltFuncMode = AF5;
		GPIO_initPin(PORTA, 4, &spiConfig); // NSS
		GPIO_initPin(PORTA, 5, &spiConfig); // SCK
		GPIO_initPin(PORTA, 6, &spiConfig); // MISO
		GPIO_initPin(PORTA, 7, &spiConfig); // MOSI
	}
	else if(SPIn == SPI2){
		spiConfig.AltFuncMode = AF5;
		GPIO_initPin(PORTB, 12, &spiConfig); // NSS
		GPIO_initPin(PORTB, 13, &spiConfig); // SCK
		GPIO_initPin(PORTB, 14, &spiConfig); // MISO
		GPIO_initPin(PORTB, 15, &spiConfig); // MOSI
	}
	else if(SPIn == SPI3){
		spiConfig.AltFuncMode = AF6;
		GPIO_initPin(PORTA, 15, &spiConfig); // NSS
		GPIO_initPin(PORTB, 3, &spiConfig);  // SCK
		GPIO_initPin(PORTB, 4, &spiConfig);  // MISO
		GPIO_initPin(PORTB, 5, &spiConfig);  // MOSI
	}
}

void SPI_sendData(st_SPI_RegDef_t* SPIn, uint8_t data){
	while(!(SPIn->SR&(1<<1)));
	SPIn->DR = data;
}

void SPI_receiveData(st_SPI_RegDef_t* SPIn, uint8_t* data){
	while(!(SPIn->SR&(1<<0)));
	*data = SPIn->DR;
}
