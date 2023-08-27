/*
 * LCD_Config.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

typedef struct{
	u8 mode;
	u8 lines;
	u8 resolution;
	u8	cursor;
	u8 direction;
}LCD_Config_t;

/* Modes */
#define LCD_MODE_8		0
#define LCD_MODE_4		1
/* Lines */
#define LCD_TWO_LINE	0
#define	LCD_ONE_LINE	1
/* Resolution */
#define LCD_5_8	 		0
#define LCD_5_11		1
/* Cursor */
#define LCD_CURSOR_VISIBLE_NO_BLINKING	0
#define LCD_CURSOR_VISIBLE_BLINKINIG	1
/* Cursor direction */
#define LCD_CURSOR_DIRECT	0
#define LCD_CURSOR_INVERSE	1


/* RS Pin */
#define LCD_REG_COMMAND	0
#define LCD_REG_DATA	1

/* R/W Pin */
#define LCD_WRITE		0
#define LCD_READ		1

#endif /* LCD_LCD_CONFIG_H_ */
