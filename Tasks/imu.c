/*
 * imu.c
 *
 *  Created on: 15 Apr 2023
 *      Author: ingram
 */

#include "FreeRTOS.h"
#include "task.h"
#include "usart.h"
#include "i2c.h"
#include "imu.h"

#include <apptools.h>



void vIMUTask(void *pvParms)
{
	portTickType xLastWakeTime;
	const portTickType xFrequency = 1000;
	xLastWakeTime = xTaskGetTickCount();

	SemaphoreHandle_t xSemaphore = xUSARTGetMutex();

	vIMUInit();

	for(;;) {

		if(xSemaphoreTake(xSemaphore, 0) == pdTRUE)
		{
			vUSARTSetMessage("IMU!");
			vUSARTPrint();
			xSemaphoreGive(xSemaphore);
		}

		vIMURead();

		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}


/*
 * Initialise the I2C and IMU here
 */
void vIMUInit()
{
	I2C_init();
}


/*
 * TODO Read IMU Data into struct
 */
void vIMURead()
{
	I2C_start();
	I2C_write(MPU_9250_ADDRESS_AD0_0 << 1);
	I2C_stop();
}


