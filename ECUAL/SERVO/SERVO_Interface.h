/*
 * SERVO.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Mahmoud Ahmed
 */

#ifndef SERVO_SERVO_H_
#define SERVO_SERVO_H_

#include "../../MCAL/TIMERS/TIMERS_Interface.h"

typedef struct{
	st_TIM_RegDef_t* TIMx;
	EN_Timers_channel_t channel;
}SERVO_t;

void SERVO_voidInit(SERVO_t *servo);
void SERVO_voidSetAngle(SERVO_t *servo, s8 angle);

#endif /* SERVO_SERVO_H_ */
