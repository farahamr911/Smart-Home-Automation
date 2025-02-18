/*
 * ldr.c
 *
 *  Created on: Oct 7, 2024
 *      Author: farah
 */


#include "ldr.h"
#include "adc.h"

uint16 LDR_getLightIntensity(void)
{
	uint16 inensty_value=0;
	uint16 adc_int_value = 0;

	/* Read ADC channel where the sensor is connected */
	adc_int_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);
	inensty_value = (uint16)(((uint32)adc_int_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));
	return inensty_value;
}
