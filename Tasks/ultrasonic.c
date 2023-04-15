/*
 * ultrasonic.c
 *
 *  Created on: 15 Apr 2023
 *      Author: ingram
 */

#include "FreeRTOS.h"
#include "task.h"
#include "usart.h"
#include <apptools.h>


void vUltraSonicTask(void *pvParms)
{
	portTickType xLastWakeTime;
	const portTickType xFrequency = 200;
	xLastWakeTime = xTaskGetTickCount();

	TaskHandle_t xTaskHandle = xTaskGetCurrentTaskHandle();

	char * pcTaskName = pcTaskGetTaskName(xTaskHandle);

	SemaphoreHandle_t xSemaphore = xUSARTGetMutex();

	for(;;) {
		if(xSemaphoreTake(xSemaphore, 0) == pdTRUE)
		{
			vUSARTSetMessage(pcTaskName);
			vUSARTPrint();
			xSemaphoreGive(xSemaphore);
		}

		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}


