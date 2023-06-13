/*
 * imu.h
 *
 *  Created on: 15 Apr 2023
 *      Author: ingram
 */

#ifndef TASKS_IMU_H_
#define TASKS_IMU_H_

#include "i2c.h"

#define ROOM_TEMPERATURE_OFFSET 21.0		// Degrees C
#define SENSITIVITY 			333.87 // LSB/Degrees C

#define MPU_9250_ADDRESS_AD0_0 0x68
#define MPU_9250_ADDRESS_AD0_1 0x69
#define MPU_9250_ADDRESS_QUERY 0x25

// Use the correct address here
#define MPU_9250_ADDRESS 			MPU_9250_ADDRESS_AD0_0
#define MPU_9250_READ_OPERATION 	MPU_9250_ADDRESS << 1 | 1
#define MPU_9250_WRITE_OPERATION 	MPU_9250_ADDRESS << 1

#define MPU_9250_ACCEL_XOUT_H 0x3B
#define MPU_9250_ACCEL_XOUT_L 0x3C
#define MPU_9250_ACCEL_YOUT_H 0x3D
#define MPU_9250_ACCEL_YOUT_L 0x3E
#define MPU_9250_ACCEL_ZOUT_H 0x3F
#define MPU_9250_ACCEL_ZOUT_L 0x40

#define MPU_9250_TEMP_OUT_H 0x41
#define MPU_9250_TEMP_OUT_L 0x42

#define MPU_9250_GYRO_XOUT_H 0x43
#define MPU_9250_GYRO_XOUT_L 0x44
#define MPU_9250_GYRO_YOUT_H 0x45
#define MPU_9250_GYRO_YOUT_L 0x46
#define MPU_9250_GYRO_ZOUT_H 0x47
#define MPU_9250_GYRO_ZOUT_L 0x48

#define NUMBER_OF_DATA_ELEMENTS 7

void vIMUInit();
void vIMUTask(void *pvParms);
void vIMURead();
void vIMUJoinBytes(uint8_t * raw_data, uint16_t * processed_data);
void vIMUPrint();
void vUMUPrintTemperature();
uint8_t vIMURegRead(uint8_t reg);



#endif /* TASKS_IMU_H_ */
