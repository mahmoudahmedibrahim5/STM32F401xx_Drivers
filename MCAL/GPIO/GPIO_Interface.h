/*
 * GPIO_Interface.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_

#include "GPIO_Registers.h"

#define LOW  0
#define HIGH 1

typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTH
}En_Port_t;

typedef struct{
	uint8_t mode;		// pin modes
	uint8_t outType;	// Output types
	uint8_t speed;		// speed levels
	uint8_t pupdState;	// Pull up pull down states
	uint8_t AltFuncMode;// Alternate functions modes
}GPIO_Config_t;

/* pin modes */
#define IN	 			0
#define OUT	 			1
#define ALT_FN 			2
#define ANALOG 			3
/* Output types */
#define PUSH_PULL		0
#define OPEN_DRAIN		1
/* Speed levels */
#define LOW_SPEED		0
#define MEDUIM_SPEED	1
#define HIGH_SPEED		2
#define VERY_HIGH_SPEED	3
/* Pull up pull down states */
#define NO_PUPD 		0
#define PULL_UP 		1
#define PULL_DOWN		2
/* Alternate functions modes */
typedef enum{
	AF0,AF1,AF2,AF3,AF4,AF5,AF6,AF7,AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15
}En_AlternateFunctions_t;


void GPIO_initPort(En_Port_t port, GPIO_Config_t* mode);
void GPIO_initPin(En_Port_t port, uint8_t pinNum, GPIO_Config_t* mode);

void GPIO_setPinValue(En_Port_t port, uint8_t pinNum, uint8_t val);
void GPIO_setPortValue(En_Port_t port, uint16_t val);
void GPIO_togglePin(En_Port_t port, uint8_t pinNum);
void GPIO_togglePort(En_Port_t port);

uint8_t GPIO_readPin(En_Port_t port, uint8_t pinNum);
uint16_t GPIO_readPort(En_Port_t port);

#endif /* GPIO_GPIO_INTERFACE_H_ */
