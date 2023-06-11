/*
 * NVIC_Registers.h
 *
 *  Created on: Feb 22, 2023
 *      Author: Mahmoud Ahmed Ibrahim
 */

#ifndef NVIC_NVIC_REGISTERS_H_
#define NVIC_NVIC_REGISTERS_H_

#define NVIC_BASE_ADDR					0xE000E000

typedef uint32_t arr8_uint32_t[8];
typedef uint32_t arr60_uint32_t[60];

#define NVIC_ISER						*((volatile arr8_uint32_t *)(NVIC_BASE_ADDR + 0x100))
#define NVIC_ICER						*((volatile arr8_uint32_t *)(NVIC_BASE_ADDR + 0x180))
#define NVIC_ISPR						*((volatile arr8_uint32_t *)(NVIC_BASE_ADDR + 0x200))
#define NVIC_ICPR						*((volatile arr8_uint32_t *)(NVIC_BASE_ADDR + 0x280))
#define NVIC_IABR						*((volatile arr8_uint32_t *)(NVIC_BASE_ADDR + 0x300))
#define NVIC_IPR						*((volatile arr60_uint32_t *)(NVIC_BASE_ADDR + 0x400))
/*
#define NVIC_ISER0						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x100))
#define NVIC_ISER1						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x104))
#define NVIC_ISER2						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x108))
#define NVIC_ISER3						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x10C))
#define NVIC_ISER4						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x110))
#define NVIC_ISER5						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x114))
#define NVIC_ISER6						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x118))
#define NVIC_ISER7						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x11C))
*/

/*
#define NVIC_ICER0						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x180))
#define NVIC_ICER1						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x184))
#define NVIC_ICER2						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x188))
#define NVIC_ICER3						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x18C))
#define NVIC_ICER4						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x190))
#define NVIC_ICER5						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x194))
#define NVIC_ICER6						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x198))
#define NVIC_ICER7						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x19C))
*/

/*
#define NVIC_ISPR0						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x200))
#define NVIC_ISPR1						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x204))
#define NVIC_ISPR2						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x208))
#define NVIC_ISPR3						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x20C))
#define NVIC_ISPR4						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x210))
#define NVIC_ISPR5						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x214))
#define NVIC_ISPR6						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x218))
#define NVIC_ISPR7						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x21C))
*/

/*
#define NVIC_ICPR0						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x280))
#define NVIC_ICPR1						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x284))
#define NVIC_ICPR2						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x288))
#define NVIC_ICPR3						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x28C))
#define NVIC_ICPR4						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x290))
#define NVIC_ICPR5						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x294))
#define NVIC_ICPR6						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x298))
#define NVIC_ICPR7						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x29C))
*/

/*
#define NVIC_IABR0						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x300))
#define NVIC_IABR1						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x304))
#define NVIC_IABR2						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x308))
#define NVIC_IABR3						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x30C))
#define NVIC_IABR4						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x310))
#define NVIC_IABR5						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x314))
#define NVIC_IABR6						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x318))
#define NVIC_IABR7						*((volatile uint32_t *)(NVIC_BASE_ADDR + 0x31C))
*/

#endif /* NVIC_NVIC_REGISTERS_H_ */
