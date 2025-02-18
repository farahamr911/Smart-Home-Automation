/*
 * buzzer.h
 *
 *  Created on: Oct 7, 2024
 *      Author: farah
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include"gpio.h"

#define buzzer_port    PORTD_ID
#define buzzer_pin     PIN3_ID

void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);

#endif /* BUZZER_H_ */
