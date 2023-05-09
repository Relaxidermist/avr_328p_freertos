/*
 * i2c.h
 *
 *  Created on: 3 May 2023
 *      Author: ingram
 */

#ifndef DRIVERS_I2C_H_
#define DRIVERS_I2C_H_

// This code borrows from http://www.embedds.com/programming-avr-I2C-interface/

#include <avr/io.h>

void I2C_init();
char I2C_start();
char I2C_repeated_start();
char I2C_stop();
char I2C_write(char byte);
char I2C_read_ack();
char I2C_read_nack();

#endif /* DRIVERS_I2C_H_ */
