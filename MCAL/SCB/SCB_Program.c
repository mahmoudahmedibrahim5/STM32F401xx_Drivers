/*
 * SCB_Program.c
 *
 *  Created on: Aug 4, 2023
 *      Author: Mahmoud Ahmed Ibrahim Ahmed
 */


#include "SCB_Interface.h"

void SCB_voidInterruptPriorityConfig(void)
{
	SCB->AIRCR = 0x05FA0000 | ((u32)(SCB_PRIGROUP<<8));
}
