/*
 * LCD.c
 *
 *  Created on: Jul 4, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#include "LCD_Interface.h"

LCD_Config_t defaultConfig = {LCD_MODE_8, LCD_TWO_LINE, LCD_5_8, LCD_CURSOR_VISIBLE_BLINKINIG, LCD_CURSOR_DIRECT};
static GPIO_Config_t pinConfig = {GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_LOW_SPEED};
static void LCD_voidDelay(void);
static void LCD_voidSendData(LCD_t* lcd, u8 data);

static void LCD_voidDelay(void)
{
	for(u32 i=0; i<5*1080; i++);
}

static void LCD_voidSendData(LCD_t* lcd, u8 data)
{
	u8 i;
	for(i=0; i<8; i++){
		GPIO_voidSetPinValue(lcd->port, lcd->D[i], ((data & (1<<i))>>i));
	}
	GPIO_voidSetPinValue(lcd->port, lcd->En, GPIO_HIGH);
	LCD_voidDelay();
	GPIO_voidSetPinValue(lcd->port, lcd->En, GPIO_LOW);
	LCD_voidDelay();
}

void LCD_voidInit(LCD_t* lcd)
{
	LCD_voidInitWithConfig(lcd, &defaultConfig);
}

void LCD_voidInitWithConfig(LCD_t* lcd, LCD_Config_t* config)
{
	u8 i, data;

	// Initialize LCD pins
	for(i=0; i<8; i++){
		GPIO_voidInitPin(lcd->port, lcd->D[i], &pinConfig);
	}
	GPIO_voidInitPin(lcd->port, lcd->En, &pinConfig);
	GPIO_voidInitPin(lcd->port, lcd->RS, &pinConfig);
	GPIO_voidInitPin(lcd->port, lcd->RW, &pinConfig);

	// Start Initializing
	GPIO_voidSetPinValue(lcd->port, lcd->RS, LCD_REG_COMMAND);
	GPIO_voidSetPinValue(lcd->port, lcd->RW, LCD_WRITE);


	// Send first instruction
	data = 0x30;
	if(config->mode != LCD_MODE_4)
		data |= (1<<4);
	if(config->lines != LCD_ONE_LINE)
		data |= (1<<3);
	if(config->resolution != LCD_5_11)
		data |= (1<<2);
	LCD_voidSendData(lcd, data);

	// Send Second instruction
	LCD_voidSendData(lcd, data);

	// Send third instruction
	data = 0x0C;
	if(config->cursor == LCD_CURSOR_VISIBLE_NO_BLINKING){
		data |= (1<<1);
	}
	else if(config->cursor == LCD_CURSOR_VISIBLE_BLINKINIG){
		data |= (1<<1);
		data |= (1<<0);
	}
	LCD_voidSendData(lcd, data);

	// Send Fourth instruction (clear display)
	LCD_voidSendData(lcd, 0x01);
	LCD_voidDelay();

	// Send Fifth instruction (Entry mode set)
	data = 0x04;
	if(config->direction != LCD_CURSOR_DIRECT)
		data |= (1<<1);
	LCD_voidSendData(lcd, 0x01);

}

void LCD_voidDataWrite(LCD_t* lcd, u8 data)
{
	GPIO_voidSetPinValue(lcd->port, lcd->RS, LCD_REG_DATA);
	GPIO_voidSetPinValue(lcd->port, lcd->RW, LCD_WRITE);

	LCD_voidSendData(lcd, data);
}

void LCD_voidCommandWrite(LCD_t* lcd, u8 cmd)
{
	GPIO_voidSetPinValue(lcd->port, lcd->RS, LCD_REG_COMMAND);
	GPIO_voidSetPinValue(lcd->port, lcd->RW, LCD_WRITE);

	LCD_voidSendData(lcd, cmd);
}
