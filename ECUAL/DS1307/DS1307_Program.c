/*
 * DS1307_Program.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */


#include "DS1307_Interface.h"

I2C_Config_t DS1307rtc = {I2C_STANDARD, I2C_7_BIT, 100, 0x61, I2C_ACK_EN};

static uint8_t binaryToBCD(uint8_t value);
static uint8_t BCDToBinary(uint8_t value);

void DS1307_init(DS1307_Handle_t* rtc)
{
	I2C_init(rtc->I2Cn, &DS1307rtc);

	uint8_t data[8] =   {
						0x00, // To Set Register Pointer to 0x00
						rtc->time->seconds,
						rtc->time->minutes,
						rtc->time->hours,
						rtc->date->day,
						rtc->date->date,
						rtc->date->month,
						rtc->date->year
						};

	for(uint8_t i=0; i<8; i++)
		data[i] = binaryToBCD(data[i]);

	// Set CH bit
	data[0] |= (1<<7);

	// Adjust Time format
	if(rtc->timeFormat == DS1307_FORMAT_24)
		data[3] |= (1<<6);
	else
		data[3] &= ~(1<<6);

	I2C_masterSendData(rtc->I2Cn, DS1307_ADDR, data, 8, I2C_RS_DISABLE);
}

void DS1307_read(DS1307_Handle_t* rtc)
{
	// Set Register Pointer to 0x00
	uint8_t data = 0x00;
	I2C_masterSendData(rtc->I2Cn, DS1307_ADDR, &data, 1, I2C_RS_DISABLE);

	// Read 7 Bytes of Time and Date
	uint8_t buffer[7];
	I2C_masterReceiveData(I2C1, DS1307_ADDR, buffer, 7, I2C_RS_DISABLE);
	rtc->time->seconds = BCDToBinary(buffer[0]);
	rtc->time->minutes = BCDToBinary(buffer[1]);
	rtc->time->hours = BCDToBinary(buffer[2]);

	rtc->date->day = BCDToBinary(buffer[3]);
	rtc->date->date = BCDToBinary(buffer[4]);
	rtc->date->month = BCDToBinary(buffer[5]);
	rtc->date->year = BCDToBinary(buffer[6]);
}

static uint8_t binaryToBCD(uint8_t value)
{
	uint8_t units, tens;
	units = value%10;
	tens = value/10;
	return ( units | (tens<<4) );
}

static uint8_t BCDToBinary(uint8_t value)
{
	uint8_t units, tens;
	units = value & 0x0F;
	tens = (value & 0xF0)>>4;
	return ( (tens*10) + units );
}
