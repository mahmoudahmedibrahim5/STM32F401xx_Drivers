/*
 * GPIO_Program.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */


#include "GPIO_Interface.h"

void GPIO_initPort(En_Port_t port, GPIO_Config_t* mode)
{
	st_GPIO_RegDef_t *pGPIO;
	switch(port)
	{
	case PORTA:
			pGPIO = pGPIOA;
			break;
	case PORTB:
			pGPIO = pGPIOB;
			break;
	case PORTC:
			pGPIO = pGPIOC;
			break;
	case PORTD:
			pGPIO = pGPIOD;
			break;
	case PORTE:
			pGPIO = pGPIOE;
			break;
	case PORTH:
			pGPIO = pGPIOH;
			break;
	default:
			// error (will be edited later)
			break;
	}
	for(uint8_t i=0; i<16; i++)
	{
		// Configure the mode
		pGPIO->MODE  &= ~(0x3<<((2*i)));
		pGPIO->MODE  |= (mode->mode << (2*i));
		// Configure output type in case mode is output
		if(mode->mode == OUT){
		pGPIO->TYPE  &= ~(1<<(i));
		pGPIO->TYPE  |= (mode->outType << i);
		}
		// Configure speed
		pGPIO->SPEED &= ~(0x3<<((2*i)));
		pGPIO->SPEED |= (mode->speed << (2*i));
		// Configure pull up and pull down resistors in case mode is input or open drain output
		if((mode->mode == IN) || ((mode->mode == OUT)&&(mode->outType == OPEN_DRAIN))){
		pGPIO->PUPDR &= ~(0x3<<((2*i)));
		pGPIO->PUPDR |= (mode->pupdState << (2*i));
		}
		// Configure Alternate function
		if(mode->mode == ALT_FN){
			if(mode->AltFuncMode<8)
				pGPIO->AFRL |= (mode->AltFuncMode << (4*i));
			else
				pGPIO->AFRH |= ((mode->AltFuncMode-8) << (4*i));
		}
	}
}
void GPIO_initPin(En_Port_t port, uint8_t pinNum, GPIO_Config_t* mode)
{
		st_GPIO_RegDef_t *pGPIO;
		switch(port)
		{
		case PORTA:
				pGPIO = pGPIOA;
				break;
		case PORTB:
				pGPIO = pGPIOB;
				break;
		case PORTC:
				pGPIO = pGPIOC;
				break;
		case PORTD:
				pGPIO = pGPIOD;
				break;
		case PORTE:
				pGPIO = pGPIOE;
				break;
		case PORTH:
				pGPIO = pGPIOH;
				break;
		default:
				// error (will be edited later)
				break;
		}
		// Configure the mode
		pGPIO->MODE  &= ~(0x3<<((2*pinNum)));
		pGPIO->MODE  |= (mode->mode << (2*pinNum));
		// Configure output type in case mode is output
		if(mode->mode == OUT){
		pGPIO->TYPE  &= ~(1<<(pinNum));
		pGPIO->TYPE  |= (mode->outType << pinNum);
		}
		// Configure speed
		pGPIO->SPEED &= ~(0x3<<((2*pinNum)));
		pGPIO->SPEED |= (mode->speed << (2*pinNum));
		// Configure pull up and pull down resistors in case mode is input or open drain output
		if((mode->mode == IN) || ((mode->mode == OUT)&&(mode->outType == OPEN_DRAIN))){
		pGPIO->PUPDR &= ~(0x3<<((2*pinNum)));
		pGPIO->PUPDR |= (mode->pupdState << (2*pinNum));
		}
		// Configure Alternate function
		if(mode->mode == ALT_FN){
			if(mode->AltFuncMode<8)
				pGPIO->AFRL |= (mode->AltFuncMode << (4*pinNum));
			else
				pGPIO->AFRH |= ((mode->AltFuncMode-8) << (4*pinNum));
		}
}

void GPIO_setPinValue(En_Port_t port, uint8_t pinNum, uint8_t val)
{
	st_GPIO_RegDef_t *pGPIO;
		switch(port)
		{
		case PORTA:
				pGPIO = pGPIOA;
				break;
		case PORTB:
				pGPIO = pGPIOB;
				break;
		case PORTC:
				pGPIO = pGPIOC;
				break;
		case PORTD:
				pGPIO = pGPIOD;
				break;
		case PORTE:
				pGPIO = pGPIOE;
				break;
		case PORTH:
				pGPIO = pGPIOH;
				break;
		default:
				// error
				break;
		}
	if(val == HIGH)
	{
		pGPIO->ODR |= (1<<pinNum);
	}
	else
	{
		pGPIO->ODR &= ~(1<<pinNum);
	}
}
void GPIO_setPortValue(En_Port_t port, uint16_t val)
{
	st_GPIO_RegDef_t *pGPIO;
		switch(port)
		{
		case PORTA:
				pGPIO = pGPIOA;
				break;
		case PORTB:
				pGPIO = pGPIOB;
				break;
		case PORTC:
				pGPIO = pGPIOC;
				break;
		case PORTD:
				pGPIO = pGPIOD;
				break;
		case PORTE:
				pGPIO = pGPIOE;
				break;
		case PORTH:
				pGPIO = pGPIOH;
				break;
		default:
				// error
				break;
		}

		pGPIO->ODR = val;
}

void GPIO_togglePin(En_Port_t port, uint8_t pinNum)
{
	st_GPIO_RegDef_t *pGPIO;
		switch(port)
		{
		case PORTA:
				pGPIO = pGPIOA;
				break;
		case PORTB:
				pGPIO = pGPIOB;
				break;
		case PORTC:
				pGPIO = pGPIOC;
				break;
		case PORTD:
				pGPIO = pGPIOD;
				break;
		case PORTE:
				pGPIO = pGPIOE;
				break;
		case PORTH:
				pGPIO = pGPIOH;
				break;
		default:
				// error
				break;
		}
	pGPIO->ODR ^= (1<<pinNum);
}
void GPIO_togglePort(En_Port_t port)
{
	st_GPIO_RegDef_t *pGPIO;
		switch(port)
		{
		case PORTA:
				pGPIO = pGPIOA;
				break;
		case PORTB:
				pGPIO = pGPIOB;
				break;
		case PORTC:
				pGPIO = pGPIOC;
				break;
		case PORTD:
				pGPIO = pGPIOD;
				break;
		case PORTE:
				pGPIO = pGPIOE;
				break;
		case PORTH:
				pGPIO = pGPIOH;
				break;
		default:
				// error
				break;
		}
	pGPIO->ODR ^= 0xFFFF;
}

uint8_t GPIO_readPin(En_Port_t port, uint8_t pinNum)
{
	st_GPIO_RegDef_t *pGPIO;
			switch(port)
			{
			case PORTA:
					pGPIO = pGPIOA;
					break;
			case PORTB:
					pGPIO = pGPIOB;
					break;
			case PORTC:
					pGPIO = pGPIOC;
					break;
			case PORTD:
					pGPIO = pGPIOD;
					break;
			case PORTE:
					pGPIO = pGPIOE;
					break;
			case PORTH:
					pGPIO = pGPIOH;
					break;
			default:
					// error
					break;
			}
	return (uint8_t)((pGPIO->IDR & (1<<pinNum))>>pinNum);
}
uint16_t GPIO_readPort(En_Port_t port)
{
	st_GPIO_RegDef_t *pGPIO;
				switch(port)
				{
				case PORTA:
						pGPIO = pGPIOA;
						break;
				case PORTB:
						pGPIO = pGPIOB;
						break;
				case PORTC:
						pGPIO = pGPIOC;
						break;
				case PORTD:
						pGPIO = pGPIOD;
						break;
				case PORTE:
						pGPIO = pGPIOE;
						break;
				case PORTH:
						pGPIO = pGPIOH;
						break;
				default:
						// error
						break;
				}
	return (uint16_t)(pGPIO->IDR);
}
