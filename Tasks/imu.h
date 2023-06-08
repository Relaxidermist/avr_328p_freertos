/*
 * imu.h
 *
 *  Created on: 15 Apr 2023
 *      Author: ingram
 */

#ifndef TASKS_IMU_H_
#define TASKS_IMU_H_

#include "i2c.h"

#define MPU_9250_ADDRESS_AD0_0 0x68
#define MPU_9250_ADDRESS_AD0_1 0x69
#define MPU_9250_ADDRESS_QUERY 0x25

#define MPU_9250_ACCEL_XOUT_H 0x3B
#define MPU_9250_ACCEL_XOUT_L 0x3C
#define MPU_9250_ACCEL_YOUT_H 0x3D
#define MPU_9250_ACCEL_YOUT_L 0x3E
#define MPU_9250_ACCEL_ZOUT_H 0x3F
#define MPU_9250_ACCEL_ZOUT_L 0x40

void vIMUInit();
void vIMUTask(void *pvParms);
void vIMURead();
void vIMURegRead(char reg);



#endif /* TASKS_IMU_H_ */
