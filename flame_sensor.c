/*
 * flame_sensor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: farah
 */

#include "flame_sensor.h"

void FlameSensor_init(void)
{
	GPIO_setupPinDirection(flame_sensor_port,flame_sensor_pin,PIN_INPUT);
}

uint8 FlameSensor_getValue(void)
{
	return GPIO_readPin(flame_sensor_port,flame_sensor_pin);
}
