/*
 * Button.h
 *
 *  Created on: Apr 24, 2023
 *      Author: Mahmoud Ahmed
 *
 *      since I am usually use the same configuration for Buttons
 *      I decided to write this driver so I don't need to write this
 *      configuration every time I use Button and it also make the main code more readable
 */

#ifndef BUTTON_BUTTON_H_
#define BUTTON_BUTTON_H_

#include "../../Utilities/stm32f401xx.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"

typedef struct Button{
	uint8_t port;
	uint8_t pin;
}Button_t;

void Button_init(Button_t* btn);
uint8_t Button_read(Button_t* btn);

#endif /* BUTTON_BUTTON_H_ */
