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
	const portTickType xFrequency = 1000;
	xLastWakeTime = xTaskGetTickCount();

	for(;;) {
		vLEDToggle();
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}

void vUARTIfaceTask(void *pvParms)
{
	;
}

