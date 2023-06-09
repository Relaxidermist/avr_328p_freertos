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


uint8_t imu_registers[] = {
		MPU_9250_ACCEL_XOUT_H,
		MPU_9250_ACCEL_XOUT_L,
		MPU_9250_ACCEL_YOUT_H,
		MPU_9250_ACCEL_YOUT_L,
		MPU_9250_ACCEL_ZOUT_H,
		MPU_9250_ACCEL_ZOUT_L,
		MPU_9250_TEMP_OUT_H,
		MPU_9250_TEMP_OUT_L,
		MPU_9250_GYRO_XOUT_H,
		MPU_9250_GYRO_XOUT_L,
		MPU_9250_GYRO_YOUT_H,
		MPU_9250_GYRO_YOUT_L,
		MPU_9250_GYRO_ZOUT_H,
		MPU_9250_GYRO_ZOUT_L
};

uint8_t imu_data[sizeof(imu_registers)];

SemaphoreHandle_t xSemaphore = NULL;



void vIMUTask(void *pvParms)
{
	portTickType xLastWakeTime;
	const portTickType xFrequency = 500;
	xLastWakeTime = xTaskGetTickCount();

	xSemaphore = xUSARTGetMutex();

	vIMUInit();

	for(;;) {

		if(xSemaphoreTake(xSemaphore, 0) == pdTRUE)
		{
			memset(imu_data, 0, sizeof(imu_data));

			vUSARTSetMessage(imu_data);
			vIMURead();
			vUSARTPrint();
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
	I2C_init();
}


/*
 * TODO join high/low bytes. remove hack for sending null char
 */
void vIMURead()
{
	for(uint8_t i = 0; i < sizeof(imu_registers) - 1; i++)
	{
		imu_data[i] = vIMURegRead(imu_registers[i]);
		if(imu_data[i] == 0)
		{
			imu_data[i] = 1;
		}
	}
	imu_data[sizeof(imu_data) - 1] = 0;
}

/*
 * Sequence of operations using the I2C peripheral that performs a
 * single byte read sequence on the MPU-9250.
 */
uint8_t vIMURegRead(uint8_t reg)
{
	uint8_t register_value;

	I2C_start();

	I2C_write(MPU_9250_WRITE_OPERATION);
	I2C_write(reg); // physical address register

	I2C_start();

	I2C_write(MPU_9250_READ_OPERATION);

	register_value = I2C_read_nack();

	I2C_stop();

	return register_value;
}


