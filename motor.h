/*
 * motor.h
 *
 *  Created on: Oct 7, 2024
 *      Author: farah
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
#include "gpio.h"
typedef enum
{
	CW,A_CW,Stop
}DcMotor_State;

#define PORT_MOTOR_INIT1 PORTB_ID
#define PORT_MOTOR_INIT2 PORTB_ID

#define PIN_MOTOR_INIT1 PIN0_ID
#define PIN_MOTOR_INIT2 PIN1_ID


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);


#endif /* MOTOR_H_ */
