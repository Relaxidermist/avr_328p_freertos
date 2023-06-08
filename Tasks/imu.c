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
	const portTickType xFrequency = 500;
	xLastWakeTime = xTaskGetTickCount();

	SemaphoreHandle_t xSemaphore = xUSARTGetMutex();

	vIMUInit();

	for(;;) {

		if(xSemaphoreTake(xSemaphore, 0) == pdTRUE)
		{
			vUSARTSetMessage("IMU!");
			vUSARTPrint();
			vIMURead();
			xSemaphoreGive(xSemaphore);
		}


		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}


/*
 * Initialise the I2C and IMU here
 */
void vIMUInit()
{
	char address_payload_write;
	address_payload_write = ((MPU_9250_ADDRESS_AD0_0 << 1));

	I2C_init();
}


/*
 * TODO Read IMU Data into struct
 */
void vIMURead()
{
	char address_payload_read, address_payload_write;
	static int sent = 0;
	//char query_payload;

	address_payload_read = ((MPU_9250_ADDRESS_AD0_0 << 1) | 1);
	address_payload_write = ((MPU_9250_ADDRESS_AD0_0 << 1));

	vIMURegRead(MPU_9250_ACCEL_XOUT_H);
	vIMURegRead(MPU_9250_ACCEL_XOUT_L);
	vIMURegRead(MPU_9250_ACCEL_YOUT_H);
	vIMURegRead(MPU_9250_ACCEL_YOUT_L);
	vIMURegRead(MPU_9250_ACCEL_ZOUT_H);
	vIMURegRead(MPU_9250_ACCEL_ZOUT_L);

	vIMURegRead(MPU_9250_TEMP_OUT_H);
	vIMURegRead(MPU_9250_TEMP_OUT_L);

	vIMURegRead(MPU_9250_GYRO_XOUT_H);
	vIMURegRead(MPU_9250_GYRO_XOUT_L);
	vIMURegRead(MPU_9250_GYRO_YOUT_H);
	vIMURegRead(MPU_9250_GYRO_YOUT_L);
	vIMURegRead(MPU_9250_GYRO_ZOUT_H);
	vIMURegRead(MPU_9250_GYRO_ZOUT_L);
}

/*
 * Sequence of operations using the I2C peripheral that performs a
 * single byte read sequence on the MPU-9250.
 */
void vIMURegRead(char reg)
{
	char address_payload_read, address_payload_write;

	address_payload_read = ((MPU_9250_ADDRESS_AD0_0 << 1) | 1);
	address_payload_write = ((MPU_9250_ADDRESS_AD0_0 << 1));

	I2C_start();

	I2C_write(address_payload_write);
	I2C_write(reg); // physical address register

	I2C_start();

	I2C_write(address_payload_read);

	I2C_read_nack();

	I2C_stop();
}


