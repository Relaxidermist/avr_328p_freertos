/*
 * uart.h
 *
 *  Created on: 11 Apr 2023
 *      Author: ingram
 *
 *      usart code stolen from here:
 *      https://www.coderoasis.com/implementing-uart-on-the-atmega328p/
 *
 */

#ifndef DRIVERS_USART_H_
#define DRIVERS_USART_H_

void vUSARTSetMessage(char* message);

void vUSARTInit();

void vUSARTPrint();

#endif /* DRIVERS_USART_H_ */
