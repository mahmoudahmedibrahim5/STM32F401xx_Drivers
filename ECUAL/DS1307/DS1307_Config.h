/*
 * DS1307_Config.h
 *
 *  Created on: Jul 6, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef DS1307_DS1307_CONFIG_H_
#define DS1307_DS1307_CONFIG_H_

#include "../Utilities/DataTypes.h"

typedef enum{
	SATURDAY,
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY
}EN_day_t;

typedef struct{
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
}DS1307_time_t;

typedef struct{
	EN_day_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}DS1307_date_t;

typedef struct{
	st_I2C_RegDef_t* I2Cn;
	uint8_t timeFormat;
	DS1307_time_t* time;
	DS1307_date_t* date;
}DS1307_Handle_t;

/* Time Format */
#define DS1307_FORMAT_24	0
#define DS1307_FORMAT_12	1

/* Clock and Calendar Registers */
#define DS1307_REG_SECONDS	0x00
#define DS1307_REG_MINUTES	0x01
#define DS1307_REG_HOURS	0x02
#define DS1307_REG_DAY		0x03
#define DS1307_REG_DATE		0x04
#define DS1307_REG_MONTH	0x05
#define DS1307_REG_YEAR		0x06
#define DS1307_REG_CONTROL	0x07

#endif /* DS1307_DS1307_CONFIG_H_ */
