/*
 * hw_uart.h
 *
 *  Created on: Mar 16, 2016
 *      Author: mohamed
 */

#ifndef HW_UART_H_
#define HW_UART_H_
#include"types.h"






#define UART0 0x4000c000
#define UART1 0x4000d000
#define UART2 0x4000e000
#define UART3 0x4000f000
#define UART4 0x40010000
#define UART5 0x40011000
#define UART6 0x40012000
#define UART7 0x40013000

#define UARTRMCGC 0x400fe618
#define UARTCTL 0x030
#define UARTIBRD 0X024
#define UARTFBRD 0x028
#define UARTCC 0xfc8
#define UART_LINE_CTL 0X02C
#define UART_DATA 0x000





#endif /* HW_UART_H_ */
