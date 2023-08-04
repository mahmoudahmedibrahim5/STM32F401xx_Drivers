/*
 * SCB_Config.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Mahmoud Ahmed Ibrahim Ahmed
 */

#ifndef SCB_SCB_CONFIG_H_
#define SCB_SCB_CONFIG_H_

#define SCB_INT_PRIORITY_4GROUP_0SUB	0b000
#define SCB_INT_PRIORITY_3GROUP_1SUB	0b100
#define SCB_INT_PRIORITY_2GROUP_2SUB	0b101
#define SCB_INT_PRIORITY_1GROUP_3SUB	0b110
#define SCB_INT_PRIORITY_0GROUP_4SUB	0b111

/* There 5 options for configuring the interrupt grouping
 * choose one from the above 5 macros and assign it to
 * SCB_PRIGROUP
 * */

#define SCB_PRIGROUP	SCB_INT_PRIORITY_2GROUP_2SUB

#endif /* SCB_SCB_CONFIG_H_ */
