/*
 * LED.c
 *
 *  Created on: Apr 24, 2023
 *      Author: Mahmoud Ahmed
 */

#include "LED_Interface.h"

void LED_voidInit(LED_t* led){
	GPIO_Config_t LED_config;
	LED_config.mode = GPIO_OUTPUT;
	LED_config.outType = GPIO_PUSH_PULL;
	LED_config.speed = GPIO_LOW_SPEED;
	LED_config.pupdState = GPIO_NO_PUPD;
	GPIO_initPin(led->port, led->pin, &LED_config);
}

void LED_voidTurnON(LED_t* led){
	GPIO_setPinValue(led->port, led->pin, HIGH);
}

void LED_voidTurnOFF(LED_t* led){
	GPIO_setPinValue(led->port, led->pin, LOW);
}

void LED_voidToggle(LED_t* led){
	GPIO_togglePin(led->port, led->pin);
}

uint8_t LED_voidRead(LED_t* led){
	return GPIO_readPin(led->port, led->pin);
}
