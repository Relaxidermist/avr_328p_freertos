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

void vIMUInit();
void vIMUTask(void *pvParms);
void vIMURead();



#endif /* TASKS_IMU_H_ */
