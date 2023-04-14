/*
 * main.c
 *
 *  Created on: Feb 4, 2015
 *      Author: jcobb
 */
#include <avr/io.h>
#include "apptasks.h"
#include "FreeRTOS.h"
#include "task.h"

//#define mainLED_TASK_PRIORITY			(tskIDLE_PRIORITY)
#define mainLED_TASK_PRIORITY 			(tskIDLE_PRIORITY+1)
#define mainUSART_TASK_PRIORITY			(tskIDLE_PRIORITY+1)
// #define mainNEXT_TASK_2				(tskIDLE_PRIORITY+2)
// #define mainNEXT_TASK_3				(tskIDLE_PRIORITY+3)

void init(void);

void vApplicationIdleHook( void );

portSHORT main(void)
{
	xTaskCreate(vLEDFlashTask, (int8_t*) "LED", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL);
	xTaskCreate(vSR04Task, (int8_t*) "SR04", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL);
	xTaskCreate(vUSARTIfaceTask, (int8_t*) "USART", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL);

	vTaskStartScheduler();

	return 0;
}

void vApplicationIdleHook( void )
{
	//vCoRoutineSchedule();
}

