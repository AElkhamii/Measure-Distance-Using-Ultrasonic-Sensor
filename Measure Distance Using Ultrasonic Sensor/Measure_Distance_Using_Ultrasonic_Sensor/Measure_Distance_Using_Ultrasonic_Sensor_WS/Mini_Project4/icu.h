/****************************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.h
 *
 * Discretion: Header file for the AVR ICU driver
 *
 * Author: Abdelrahman Ehab
 *
 ****************************************************************************************/

#ifndef ICU_H_
#define ICU_H_

/*******************************************************************************
 *                    	     	Include Header	                               *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                         	Types Declaration                                  *
 *******************************************************************************/
typedef enum{
	NO_CLK, F_CPU_1, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024, EXTERN_CLK_FALLING_EDGE, EXTERN_CLK_RISING_EDGE
}ICU_Prescaler;

typedef enum{
	FALLING, RISING
}ICU_EdgeSelect;

typedef struct{
	ICU_Prescaler prescaler;
	ICU_EdgeSelect edge;
}ICU_ConfigType;

/*******************************************************************************
 *                         	Function Prototypes                                *
 *******************************************************************************/

/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType * Config_Ptr);

/*
 * Description:
 * Description: Function to set the Call Back function address.
 */
void ICU_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeSelect edgeType);

/*
 * Description:
 * Description: Function to get the Timer1 Value when the input is captured
 * The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void);

/*
 * Description:
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void);

/*
 * Description:
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_DeInit(void);

#endif /* ICU_H_ */
