/*
 * GPIO_Interface.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_

#include "GPIO_Registers.h"
#include "GPIO_Config.h"

#define LOW  0
#define HIGH 1

typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTH=7
}En_Port_t;

void GPIO_initPort(En_Port_t port, GPIO_Config_t* mode);
void GPIO_initPin(En_Port_t port, uint8_t pinNum, GPIO_Config_t* mode);

void GPIO_setPinValue(En_Port_t port, uint8_t pinNum, uint8_t val);
void GPIO_setPortValue(En_Port_t port, uint16_t val);
void GPIO_togglePin(En_Port_t port, uint8_t pinNum);
void GPIO_togglePort(En_Port_t port);

uint8_t GPIO_readPin(En_Port_t port, uint8_t pinNum);
uint16_t GPIO_readPort(En_Port_t port);

#endif /* GPIO_GPIO_INTERFACE_H_ */
