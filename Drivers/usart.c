/*
 * uart.c
 *
 *  Created on: 11 Apr 2023
 *      Author: ingram
 *
 *      usart code stolen from here:
 *      https://www.coderoasis.com/implementing-uart-on-the-atmega328p/
 */

#include <avr/io.h>
#include <usart.h>


#define UDRE 5

#define TXEN0 3

/*
 * Baud rate calculation
 * (cpu_frequency / (desired_baudrate * 16UL)) - 1
 */
#define USART_BAUD_RATE 57600

#define BAUD_PRESCALAR (((F_CPU / (USART_BAUD_RATE * 16UL))) - 1)


// NOTE: UBBR is a 12 bit register using 8 bits low and 4 bits high

// file scope variable that acts as a 'private data member'
static char* message;
// can only be changed via 'public method' usart_set_message()

// Sets the private member data message
void vUSARTSetMessage(char* msg) {
  message = msg;
}

// initializes the UART for use
void vUSARTInit() {
  // reset USDR0 to empty, emptying RX/TX buffer
  // set baud rate
  UBRR0H = BAUD_PRESCALAR >> 8;
  UBRR0L = BAUD_PRESCALAR;
  // set frame format
  UCSR0C = (0b11<<1); // set to 8 bit format
}

// carriage return line feed
void vUSARTCrlf(){
  while ((UCSR0A & (1<<UDRE))== 0);
  UDR0 = '\r';
  while ((UCSR0A & (1<<UDRE))== 0);
  UDR0 = '\n';
}

// print the message to the uart
void vUSARTPrint() {
  // clear transmit buffer
  UDR0 = 0x00;
  // enable transmit mode
  UCSR0B = (1<<TXEN0);
  for (int idx = 0; message[idx] != 0; idx++) {
    while ((UCSR0A & (1<<UDRE))== 0);
    UDR0 = (char) message[idx];
  }
  vUSARTCrlf();
  // disable transmit mode
  UCSR0B = (0 << TXEN0);
}


