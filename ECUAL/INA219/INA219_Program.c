/*
 * INA219_Program.c
 *
 *  Created on: Jul 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "INA219_Interface.h"

I2C_Config_t INA219_I2C_config = {I2C_STANDARD, I2C_7_BIT, 100, 0x61, I2C_ACK_EN};

void INA219_init(INA219_t* config)
{
	// Initialize I2C
	I2C_init(config->I2Cn, &INA219_I2C_config);

	// Adjust Configuration Register


	// Adjust Calibration Register
	// Cal = 40 for MAX_CURRENT = 100 mA and Shunt Resistance = 330 Ω
}


sint16_t INA219_readShuntVoltage(INA219_t* config)
{
	uint8_t data[2];
	uint8_t address = INA219_REG_SHUNT_VOLTAGE;
	I2C_masterSendData(config->I2Cn, config->slaveAddress, &address, 1, I2C_RS_DISABLE);
	I2C_masterReceiveData(config->I2Cn, config->slaveAddress, data, 2, I2C_RS_DISABLE);
	return ((data[0]<<8) | data[1]);
}

uint16_t INA219_readBusVoltage(INA219_t* config)
{
	uint8_t data[2];
	uint8_t address = INA219_REG_BUS_VOLTAGE;
	I2C_masterSendData(config->I2Cn, config->slaveAddress, &address, 1, I2C_RS_DISABLE);
	I2C_masterReceiveData(config->I2Cn, config->slaveAddress, data, 2, I2C_RS_DISABLE);
	return ((data[0]<<8) | data[1]);
}

sint16_t INA219_readCurrent(INA219_t* config);
uint16_t INA219_readPower(INA219_t* config);
