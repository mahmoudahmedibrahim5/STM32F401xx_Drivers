/*
 * SERVO.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Mahmoud Ahmed
 */

#include "SERVO_Interface.h"

static f32 SERVO_f32AngleMap(s8 angle);

void SERVO_voidInit(SERVO_t *servo)
{
	TIMERS_voidInit(servo->TIMx);
	TIMERS_voidInitPWM(servo->TIMx, servo->channel, 7.25, 20000);
}

void SERVO_voidSetAngle(SERVO_t *servo, s8 angle)
{
	TIMERS_voidUpdateDutyCycle(servo->TIMx, servo->channel, SERVO_f32AngleMap(angle));
}

static f32 SERVO_f32AngleMap(s8 angle)
{
	f32 positiveAngle = angle + 90;
	return (2.5+(positiveAngle*9.5/180));
}
