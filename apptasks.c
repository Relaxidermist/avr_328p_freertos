/*
 * tasks.c
 *
 *  Created on: Feb 4, 2015
 *      Author: jcobb
 */

#include "FreeRTOS.h"
#include "task.h"
//#include "tasks.h"
#include "Drivers/led.h"
#include "Drivers/usart.h"


void vLEDFlashTask(void *pvParms)
{
	vLEDInit();
	portTickType xLastWakeTime;
	const portTickType xFrequency = 500;
	xLastWakeTime = xTaskGetTickCount();

	for(;;) {
		vLEDToggle();
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}

void vUSARTIfaceTask(void *pvParms)
{
	vUSARTInit();
	portTickType xLastWakeTime;
	const portTickType xFrequency = 10000;
	xLastWakeTime = xTaskGetTickCount();

	vUSARTSetMessage("Hello, world!");

	for(;;) {
		vUSARTPrint();
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}

