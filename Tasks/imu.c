/*
 * imu.c
 *
 *  Created on: 15 Apr 2023
 *      Author: ingram
 */

#include "FreeRTOS.h"
#include "task.h"
#include "usart.h"

#include <apptools.h>

void vIMUTask(void *pvParms)
{
	portTickType xLastWakeTime;
	const portTickType xFrequency = 500;
	xLastWakeTime = xTaskGetTickCount();

	SemaphoreHandle_t xSemaphore = xUSARTGetMutex();

	for(;;) {

		if(xSemaphoreTake(xSemaphore, 0) == pdTRUE)
		{
			vUSARTSetMessage("IMU!");
			vUSARTPrint();
			xSemaphoreGive(xSemaphore);
		}

		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}


