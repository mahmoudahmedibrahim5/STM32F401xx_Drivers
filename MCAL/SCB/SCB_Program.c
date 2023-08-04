/*
 * SCB_Program.c
 *
 *  Created on: Aug 4, 2023
 *      Author: Mahmoud Ahmed Ibrahim Ahmed
 */


#include "SCB_Interface.h"

void SCB_interruptPriorityConfig(void)
{
	SCB->AIRCR = 0x05FA0000 | ((uint32_t)(SCB_PRIGROUP<<8));
}
