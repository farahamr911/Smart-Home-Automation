/*
 * flame_sensor.h
 *
 *  Created on: Oct 7, 2024
 *      Author: farah
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include"std_types.h"
#include"gpio.h"

#define flame_sensor_port    PORTD_ID
#define flame_sensor_pin     PIN2_ID


void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
