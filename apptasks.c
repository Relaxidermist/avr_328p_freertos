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

void vUSARTIfaceTask(void *pvParms)
{
	vUSARTInit();
	portTickType xLastWakeTime;
	const portTickType xFrequency = 500;
	xLastWakeTime = xTaskGetTickCount();

	SemaphoreHandle_t xSemaphore = xUSARTGetMutex();

	for(;;) {

		if(xSemaphoreTake(xSemaphore, 0) == pdTRUE)
		{
			vUSARTSetMessage("UART!");
			vUSARTPrint();
			xSemaphoreGive(xSemaphore);
		}

		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}

void vSR04Task(void *pvParms)
{
	portTickType xLastWakeTime;
	const portTickType xFrequency = 200;
	xLastWakeTime = xTaskGetTickCount();

	SemaphoreHandle_t xSemaphore = xUSARTGetMutex();

	for(;;) {
		if(xSemaphoreTake(xSemaphore, 0) == pdTRUE)
		{
			vUSARTSetMessage("SR04!");
			vUSARTPrint();
			xSemaphoreGive(xSemaphore);
		}

		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}


