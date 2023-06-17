/*
 * SPI_Config.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SPI_SPI_CONFIG_H_
#define SPI_SPI_CONFIG_H_


typedef struct{
	uint8_t mode;
	uint8_t dataSize;
	uint8_t dataOrder;
	uint8_t software;
	uint8_t clockMode; // CPOL and CPHAs
	uint8_t baudrate;
}SPI_Config_t;

/* Main mode */
#define SLAVE		0
#define MASTER		1
/* Data size */
#define _8_BIT		0
#define	_16_BIT		1
/* Data order */
#define	MSB			0 // MSB goes first
#define LSB			1 // LSB goes first
/* NSS pin control */
#define HARDWARE	0
#define SOFTWARE	1
/* Clock modes */
#define MODE0		0
#define MODE1		1
#define MODE2		2
#define MODE3		3
/* BaudRate */
#define PRESCALER2		0
#define PRESCALER4		1
#define PRESCALER8		2
#define PRESCALER16		3
#define PRESCALER32		4
#define PRESCALER64		5
#define PRESCALER128	6
#define PRESCALER256	7

#endif /* SPI_SPI_CONFIG_H_ */
