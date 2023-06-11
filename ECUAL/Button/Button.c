/*
 * Button.c
 *
 *  Created on: Apr 24, 2023
 *      Author: Mahmoud Ahmed
 */

#include "Button.h"

void Button_init(Button_t* btn){
	GPIO_Config_t Button_config;
	Button_config.mode = IN;
	Button_config.speed = LOW_SPEED;
	Button_config.pupdState = PULL_UP;
	GPIO_initPin(btn->port, btn->pin, &Button_config);
}

uint8_t Button_read(Button_t* btn){
	return GPIO_readPin(btn->port, btn->pin);
}

void Button_setInterrupt(Button_t* btn, uint8_t triggerType){
	// This works only for EXTI0, EXTI1, .... , EXTI4
	NVIC_enableIRQ(btn->pin + 6);
	EXTI_Config_t button = {btn->port, btn->pin, triggerType};
	EXTI_hardwareInterruptMask(&button);
}
