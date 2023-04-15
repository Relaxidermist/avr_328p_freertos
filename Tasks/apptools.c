/*
 * tasks.c
 *
 *  Created on: Feb 4, 2015
 *      Author: jcobb
 */

#include "FreeRTOS.h"
#include "task.h"
//#include "tasks.h"
#include "led.h"
#include "usart.h"
#include "semphr.h"


SemaphoreHandle_t xUSARTGetMutex()
{
	static SemaphoreHandle_t xUSARTMutex = NULL;

	if(xUSARTMutex == NULL)
	{
		xUSARTMutex = xSemaphoreCreateMutex();
	}

	return xUSARTMutex;
}

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

