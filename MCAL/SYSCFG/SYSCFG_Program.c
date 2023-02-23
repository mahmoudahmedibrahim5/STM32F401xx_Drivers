/*
 * SYSCFG_Program.c
 *
 *  Created on: Feb 23, 2023
 *      Author: ADMIN
 */

#include "../../Utilities/stm32f401xx.h"
#include "SYSCFG_Interface.h"
#include "SYSCFG_Registers.h"

void SYSCFG_EXTIcontrol(En_Port_t port, uint8_t lineNum)
{
	if(lineNum < 4){
		SYSCFG->EXTICR1 |= (port<<lineNum);
	}
	else if(lineNum < 8){
		SYSCFG->EXTICR2 |= (port<<(lineNum-4));
	}
	else if(lineNum < 12){
		SYSCFG->EXTICR3 |= (port<<(lineNum-8));
	}
	else if(lineNum < 16){
		SYSCFG->EXTICR1 |= (port<<(lineNum-12));
	}

}

