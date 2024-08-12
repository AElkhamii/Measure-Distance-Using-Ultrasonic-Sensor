/*
 ================================================================================================
 Name        : mini_project4.c
 Author      : Abdelrahman Ehab
 Description : Application for measuring the distance by using ultrasonic driver
 Date        : 10/18/2021
 ================================================================================================
 */


#define F_CPU 8000000

#include <avr/io.h>
#include "ultrasonic.h"
#include "lcd.h"
#include "icu.h"

uint16 g_distance; 	/* Variable to save the distance value in it */

int main(void)
{
	SREG |= (1<<7); /* Activate interrupt */

	LCD_init(); 	/* Activate LCD */

	/*
	 * Activate ultrasonic sensor with initiation of ICU driver.
	 * Ultrasonic_edgeProcessing function is called back by the ICU driver used in Ultrasonic_init.
	 */
	Ultrasonic_init();

	LCD_displayString("Distance = "); /* This string will appear on LCD */

	/* This loop will monitor the distance continuously from range 2 to 400 cm */
	while(1)
	{
		g_distance = Ultrasonic_readDistance();/* Get the distance */

		LCD_moveCursor(0,11); /* move cursor to the right place every loop to prevent over right */
		if(g_distance >= 100) /* if the value is more than 100 display it normally */
		{
			LCD_intgerToString(g_distance); /* Convert Distance value to string and then display the value on LCD LCD */
		}
		else if(g_distance < 100) /* if the value is less than 100 display it normally and the tenth number will be replaced with space ' ' */
		{
			LCD_intgerToString(g_distance); /* Convert Distance value to string and then display the value on LCD LCD */
			LCD_displayCharacter(' ');
		}

		LCD_moveCursor(0,14); /* move cursor to the right place every loop to prevent over right */

		LCD_displayString("cm"); /* This string will appear on LCD */
	}
}
