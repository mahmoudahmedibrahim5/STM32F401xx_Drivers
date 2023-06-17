/*
 * SPI_Interface.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_

#include "SPI_Registers.h"
#include "SPI_Config.h"

void SPI_init(st_SPI_RegDef_t* SPIn, SPI_Config_t* config);
void SPI_enable(st_SPI_RegDef_t* SPIn);
void SPI_disable(st_SPI_RegDef_t* SPIn);
void SPI_configurePins(st_SPI_RegDef_t* SPIn);
void SPI_sendData(st_SPI_RegDef_t* SPIn, uint8_t data);
void SPI_receiveData(st_SPI_RegDef_t* SPIn, uint8_t* data);

#endif /* SPI_SPI_INTERFACE_H_ */
