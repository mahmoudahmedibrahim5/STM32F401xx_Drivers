/*
 * I2C_Program.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "I2C_Interface.h"

void I2C_init(st_I2C_RegDef_t* I2Cn, I2C_Config_t* config){
	I2C_configurePins(I2Cn);

	/* Clock and speed Configuration */
	I2Cn->CR2 |= FREQ;
	if(config->speedMode == STANDARD){
		I2Cn->CCR &= ~(1<<15);
		I2Cn->CCR |= FREQ * (T_SCL/2);
	}
	else if(config->speedMode == FAST){
		I2Cn->CCR |= (1<<15);
	}
	I2Cn->TRISE |= (FREQ + 1);

	/* Configure Address */
	if(config->addressSize == _7_BIT){
		I2Cn->OAR1 &= ~(1<<15);
		I2Cn->OAR1 |= (1<<14);
		// clear address
		I2Cn->OAR1 &= ~(0b1111111<<1);
		// write the address
		I2Cn->OAR1 |= (config->address<<1);
	}
	else{
		// 10 bit addressing mode
	}

	/* ACK Control */
	if(config->ACK == ACK_EN){
		I2Cn->CR1 |= (1<<10);
	}
	else{
		I2Cn->CR1 &= ~(1<<10);
	}

	I2Cn->CR1 |= (1<<I2C_PE);
}

void I2C_masterSendData(st_I2C_RegDef_t* I2Cn, uint8_t address, uint8_t* data, uint32_t len){
	// Send Start bit
	I2Cn->CR1 |= (1<<I2C_START);

	// Send the address
	while(!(I2Cn->SR1 & (1<<I2C_SB_FLAG)));
	I2Cn->DR = address;
	// Wait for address to be sent
	while(!(I2Cn->SR1 & (1<<I2C_ADDR_FLAG)));
	uint8_t readSR2 = I2Cn->SR2; // Clear ADDR flag
	(void)readSR2;

	// Send the data
	for(uint32_t i=0; i<len; i++){
		while(!(I2Cn->SR1 & (1<<I2C_TXE_FLAG)));
		I2Cn->DR = data[i];
	}

	// Send Stop bit
	while( (!(I2Cn->SR1 & (1<<I2C_TXE_FLAG))) );// || (!(I2Cn->SR1 & (1<<2))) );
	I2Cn->CR1 |= (1<<I2C_STOP);
}

void I2C_masterReceiveData(st_I2C_RegDef_t* I2Cn,  uint8_t address, uint8_t* data, uint32_t len){
	uint32_t i=0;
	// Send Start bit
	I2Cn->CR1 |= (1<<I2C_START);

	// Send the address
	while(!(I2Cn->SR1 & (1<<I2C_SB_FLAG)));
	I2Cn->DR = address;
	// Wait for address to be sent
	while(!(I2Cn->SR1 & (1<<I2C_ADDR_FLAG)));
	if(len==1) // Send Stop bit in case 1 Byte
		I2Cn->CR1 |= (1<<I2C_STOP);

	uint8_t readSR2 = I2Cn->SR2; // Clear ADDR flag
	(void)readSR2;

	// Receive the data
	for(i=0; i<len-1; i++){
		while(!(I2Cn->SR1 & (1<<I2C_RXNE_FLAG)));
		data[i] = I2Cn->DR;
	}

	// Send Stop bit in case more than 1 Byte
	if(len != 1)
		I2Cn->CR1 |= (1<<I2C_STOP);
	while(!(I2Cn->SR1 & (1<<I2C_RXNE_FLAG)));
	data[i] = I2Cn->DR;
}

void I2C_slaveSendData(st_I2C_RegDef_t* I2Cn, uint8_t* data, uint32_t len){
	// Wait for the master to start the communication
	while(!(I2Cn->SR1 & (1<<I2C_ADDR_FLAG)));
	uint8_t readSR2 = I2Cn->SR2; // Clear ADDR flag
	(void)readSR2;

	// Send the data
	for(uint32_t i=0; i<len; i++){
		while(!(I2Cn->SR1 & (1<<I2C_TXE_FLAG)));
		I2Cn->DR = data[i];
		if(I2Cn->SR1 & (1<<I2C_AF_FLAG))
			break;
	}
	I2Cn->SR1 &= ~(1<<I2C_AF_FLAG); // Clear the AF flag
}

void I2C_slaveReceiveData(st_I2C_RegDef_t* I2Cn, uint8_t* data, uint32_t len){
	// Wait for the master to start the communication
	while(!(I2Cn->SR1 & (1<<I2C_ADDR_FLAG)));
	uint8_t readSR2 = I2Cn->SR2; // Clear ADDR flag
	(void)readSR2;

	// Receive the data
	for(uint32_t i=0; i<len-1; i++){
		if(I2Cn->SR1 & (1<<I2C_STOPF_FLAG))
				break;
		while(!(I2Cn->SR1 & (1<<I2C_RXNE_FLAG)));
		data[i] = I2Cn->DR;
	}

	uint32_t readCR1 = I2Cn->CR1;
	I2Cn->CR1 = readCR1; // Clear STOPF flag
	(void)readCR1;
}


void I2C_configurePins(st_I2C_RegDef_t* I2Cn){
	GPIO_Config_t I2C_config;
	I2C_config.mode = ALT_FN;
	I2C_config.outType = OPEN_DRAIN;
	I2C_config.pupdState = PULL_UP;
	I2C_config.speed = HIGH_SPEED;

	if(I2Cn == I2C1){
		I2C_config.AltFuncMode = AF4;
		GPIO_initPin(PORTB, 6, &I2C_config); // SCL
		GPIO_initPin(PORTB, 7, &I2C_config); // SDA
	}
	else if(I2Cn == I2C2){
		I2C_config.AltFuncMode = AF4;
		GPIO_initPin(PORTB, 10, &I2C_config); // SCL
		I2C_config.AltFuncMode = AF9;
		GPIO_initPin(PORTB, 3, &I2C_config); // SDA
	}
	else if(I2Cn == I2C3){
		I2C_config.AltFuncMode = AF4;
		GPIO_initPin(PORTA, 8, &I2C_config); // SCL
		I2C_config.AltFuncMode = AF9;
		GPIO_initPin(PORTB, 4, &I2C_config); // SDA
	}
}

void I2C_reset(st_I2C_RegDef_t* I2Cn)
{
	I2Cn->CR1 |= (1<<15);
}
