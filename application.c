/*
 * application.c
 *
 *  Created on: Oct 7, 2024
 *      Author: farah
 */

#include "lcd.h"
#include "motor.h"
#include "lm35_sensor.h"
#include "adc.h"
#include "ldr.h"
#include "led.h"
#include <avr/io.h>
int main(void)
{
	LCD_init();
	ADC_init();
	LEDS_init();
	Buzzer_init();
	DcMotor_Init();
	while(1)
	{
		LCD_moveCursor(0,4);
		LCD_displayString("FAN IS");
		LCD_moveCursor(1,0);
		LCD_displayString("Temp=");
		LCD_moveCursor(1,8);
		LCD_displayString("LDR=");
		LCD_moveCursor(1,15);
		LCD_displayString("%");

    	int temp = LM35_getTemperature();
		if(temp<25)
		{
			DcMotor_Rotate(CW,0);
			LCD_moveCursor(0,11);
			LCD_displayString("OFF");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);

		}
		else if((temp>=25) && (temp<30))
		{
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);
		}
		else if((temp>=30) && (temp<35))
		{
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);
		}
		else if((temp>=35) && (temp<40))
		{
			DcMotor_Rotate(CW,75);
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);
		}
		else if((temp>=40))
		{
			DcMotor_Rotate(CW,100);
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);
		}
		uint16 light_int=LDR_getLightIntensity();
		if(light_int<=15)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
			LCD_moveCursor(1,12);
			LCD_intgerToString(light_int);
			LCD_displayString(" ");
		}
		else if((light_int>15) && (light_int<=50))
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);
			LCD_moveCursor(1,12);
			LCD_intgerToString(light_int);
			LCD_displayString(" ");
		}
		else if((light_int>50) && (light_int<=70))
		{
			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
			LCD_moveCursor(1,12);
			LCD_intgerToString(light_int);
			LCD_displayString(" ");
		}
		else if(light_int>70)
		{
			if(light_int==100)
			{
				LCD_moveCursor(1,12);
				LCD_intgerToString(light_int);
			}
			else
			{
				LED_off(LED_RED);
				LED_off(LED_GREEN);
				LED_off(LED_BLUE);
				LCD_moveCursor(1,12);
				LCD_intgerToString(light_int);
				LCD_displayString(" ");
			}
		}
		if(FlameSensor_getValue())
		{
		while(FlameSensor_getValue())
		{
			Buzzer_on();
			LCD_displayStringRowColumn(0,1,"Critical alert!");
			LCD_displayStringRowColumn(1,0,"                  ");
		}
		Buzzer_off();
		LCD_displayStringRowColumn(0,0,"                  ");
//		LCD_moveCursor(0,7);
//		LCD_intgerToString(temp);
//		LCD_moveCursor(1,7);
//		LCD_intgerToString(light_int);
		}
		}
	return 0;
}

