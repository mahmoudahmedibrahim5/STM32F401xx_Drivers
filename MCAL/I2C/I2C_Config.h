/*
 * I2C_Config.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef I2C_I2C_CONFIG_H_
#define I2C_I2C_CONFIG_H_

// Write the frequency in MHz
#define FREQ	16
// Write the time in microseconds
#define T_SCL	10 // TL and TH recommended to be 5

typedef struct{
	uint8_t speedMode;
	uint8_t addressSize;
	uint16_t address;
	uint8_t ACK;
}I2C_Config_t;

/* Speed Modes */
#define STANDARD	0
#define FAST		1

/* Address Sizes */
#define _7_BIT		0
#define _10_BIT		1

/* ACK */
#define ACK_DIS		0
#define ACK_EN		1

#endif /* I2C_I2C_CONFIG_H_ */
