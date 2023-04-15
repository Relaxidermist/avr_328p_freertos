/*
 * tasks.h
 *
 *  Created on: Feb 4, 2015
 *      Author: jcobb
 */

#ifndef TASKS_H_
#define TASKS_H_

#include "semphr.h"

void vLEDFlashTask(void *pvParms);
void vIMUTask(void *pvParms);
void vUltraSonicTask(void *pvParms);

SemaphoreHandle_t xUSARTGetMutex();

#endif /* TASKS_H_ */
