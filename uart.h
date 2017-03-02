/*
 * uart.h
 *
 *  Created on: Mar 15, 2016
 *      Author: mohamed
 */

#ifndef UART_H_
#define UART_H_

typedef struct uart{
	uint32 uart_no;
	float uart_baud_rate;
}uart_t;

void UART_SEL(uart_t * uartx);
void UART_BAUD_SET(uart_t * uartx);
void SEND_DATA(uart_t * uartx);




#endif /* UART_H_ */
