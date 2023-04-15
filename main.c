/*
 * main.c
 *
 *  Created on: Feb 4, 2015
 *      Author: jcobb
 */
#include <avr/io.h>
#include "FreeRTOS.h"

#include "apptasks.h"
#include "task.h"

//#define mainLED_TASK_PRIORITY			(tskIDLE_PRIORITY)
#define mainLED_TASK_PRIORITY 			(tskIDLE_PRIORITY+2)
#define mainUSART_TASK_PRIORITY			(tskIDLE_PRIORITY+1)
#define mainULTRASONIC_TASK_PRIORITY	(tskIDLE_PRIORITY+3)
// #define mainNEXT_TASK_3				(tskIDLE_PRIORITY+3)

void init(void);

void vApplicationIdleHook( void );

portSHORT main(void)
{
	vUSARTInit();

	xTaskCreate(vLEDFlashTask, (int8_t*) "LED", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL);
	xTaskCreate(vUltraSonicTask, (int8_t*) "SR04_1", configMINIMAL_STACK_SIZE, NULL, mainULTRASONIC_TASK_PRIORITY, NULL);
	xTaskCreate(vUltraSonicTask, (int8_t*) "SR04_2", configMINIMAL_STACK_SIZE, NULL, mainULTRASONIC_TASK_PRIORITY, NULL);
	xTaskCreate(vIMUTask, (int8_t*) "USART", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL);

	vTaskStartScheduler();

	return 0;
}

void vApplicationIdleHook( void )
{
	//vCoRoutineSchedule();
}

