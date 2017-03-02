/*
 * uart.c
 *
 *  Created on: Mar 15, 2016
 *      Author: mohamed
 */
#include"hw_types.h"
#include"hw_gpio.h"
#include"GPIO.h"
#include"led.h"
#include"types.h"
#include"led.h"
#include"keypad.h"
#include"HW_Timer.h"
#include"hw_uart.h"
#include"uart.h"

void UART_SEL(uart_t * uartx){

switch(uartx->uart_no)
	{
	case 0:                                        //PORT A && PIN 0-1
	       HW_WR_PIN(UARTRMCGC,0,1);
          HW_WR_PIN(GPIO_RMCGC,0,1);
          HW_WR_PIN((BASE_A+GPIO_DIG),0,1);
          HW_WR_PIN((BASE_A+GPIO_DIG),1,1);
          HW_WR_PIN((BASE_A+GPIO_AFS),0,1);
          HW_WR_PIN((BASE_A+GPIO_AFS),1,1);
          HW_WR_PIN((BASE_A+GPIO_PORT_CTL),0,1);
          HW_WR_PIN((BASE_A+GPIO_PORT_CTL),4,1);
		   break;
	  case 1 :                                    //PORT B && PIN 0-1
	  	   HW_WR_PIN(UARTRMCGC,1,1);
	      HW_WR_PIN(GPIO_RMCGC,1,1);
	      HW_WR_PIN((BASE_B+GPIO_DIG),0,1);
	      HW_WR_PIN((BASE_B+GPIO_DIG),1,1);
	      HW_WR_PIN((BASE_B+GPIO_AFS),0,1);
	      HW_WR_PIN((BASE_B+GPIO_AFS),1,1);
	      HW_WR_PIN((BASE_B+GPIO_PORT_CTL),0,1);
	      HW_WR_PIN((BASE_B+GPIO_PORT_CTL),4,1);
	      break;
	  case 2:                                    //PORT D && PIN 6-7
	  	   HW_WR_PIN(UARTRMCGC,2,1);
	      HW_WR_PIN(GPIO_RMCGC,3,1);
	      HW_WR_PIN((BASE_D+GPIO_DIG),6,1);
	      HW_WR_PIN((BASE_D+GPIO_DIG),7,1);
	      HW_WR_PIN((BASE_D+GPIO_AFS),6,1);
	      HW_WR_PIN((BASE_D+GPIO_AFS),7,1);
	      HW_WR_PIN((BASE_D+GPIO_PORT_CTL),24,1);
	      HW_WR_PIN((BASE_D+GPIO_PORT_CTL),28,1);
	      break;
	  case 3:                                     //PORT C && PIN 6-7
	  	   HW_WR_PIN(UARTRMCGC,3,1);
	      HW_WR_PIN(GPIO_RMCGC,2,1);
	      HW_WR_PIN((BASE_C+GPIO_DIG),6,1);
	      HW_WR_PIN((BASE_C+GPIO_DIG),7,1);
	      HW_WR_PIN((BASE_C+GPIO_AFS),6,1);
	      HW_WR_PIN((BASE_C+GPIO_AFS),7,1);
	      HW_WR_PIN((BASE_C+GPIO_PORT_CTL),24,1);
	      HW_WR_PIN((BASE_C+GPIO_PORT_CTL),28,1);
	      break;
	  case 4:                                     //PORT C && PIN 4-5
	  	   HW_WR_PIN(UARTRMCGC,4,1);
	      HW_WR_PIN(GPIO_RMCGC,2,1);
	      HW_WR_PIN((BASE_C+GPIO_DIG),4,1);
	      HW_WR_PIN((BASE_C+GPIO_DIG),5,1);
	      HW_WR_PIN((BASE_C+GPIO_AFS),4,1);
	      HW_WR_PIN((BASE_C+GPIO_AFS),5,1);
	      HW_WR_PIN((BASE_A+GPIO_PORT_CTL),20,1);
	      HW_WR_PIN((BASE_A+GPIO_PORT_CTL),16,1);
	      break;
	  case 5:                                     //PORT E && PIN 4-5
	  	   HW_WR_PIN(UARTRMCGC,5,1);
	      HW_WR_PIN(GPIO_RMCGC,4,1);
	      HW_WR_PIN((BASE_E+GPIO_DIG),4,1);
	      HW_WR_PIN((BASE_E+GPIO_DIG),5,1);
	      HW_WR_PIN((BASE_E+GPIO_AFS),4,1);
	      HW_WR_PIN((BASE_E+GPIO_AFS),5,1);
	      HW_WR_PIN((BASE_E+GPIO_PORT_CTL),20,1);
	      HW_WR_PIN((BASE_E+GPIO_PORT_CTL),16,1);
	  		   break;
	  case 6:                                     //PORT D && PIN 4-5
	  	   HW_WR_PIN(UARTRMCGC,6,1);
	      HW_WR_PIN(GPIO_RMCGC,3,1);
	      HW_WR_PIN((BASE_D+GPIO_DIG),4,1);
	      HW_WR_PIN((BASE_D+GPIO_DIG),5,1);
	      HW_WR_PIN((BASE_D+GPIO_AFS),4,1);
	      HW_WR_PIN((BASE_D+GPIO_AFS),5,1);
	      HW_WR_PIN((BASE_D+GPIO_PORT_CTL),20,1);
	      HW_WR_PIN((BASE_D+GPIO_PORT_CTL),16,1);
	      break;
	  case 7:                                     //PORT E && PIN 0-1
	  	   HW_WR_PIN(UARTRMCGC,7,1);                   //enable clk to uart7
	      HW_WR_PIN(GPIO_RMCGC,4,1);                   //enable clk to gpio
	      HW_WR_PIN((BASE_E+GPIO_DIG),0,1);            //set bet as a dig
	      HW_WR_PIN((BASE_E+GPIO_DIG),1,1);            //set bit as a dig
	      HW_WR_PIN((BASE_E+GPIO_AFS),0,1);            //choose af
	      HW_WR_PIN((BASE_E+GPIO_AFS),1,1);            //choose af
	      HW_WR_PIN((BASE_E+GPIO_PORT_CTL),0,1);       //SET GPIO AF CTL
	      HW_WR_PIN((BASE_E+GPIO_PORT_CTL),4,1);	   //SET GPIO AF CTL
	  default:
;

}
}

void UART_BAUD_SET(uart_t * uartx)
{

int uart_int;
int uart_frac;
uart_int=(1000000/uartx->uart_baud_rate);
uart_frac=(((1000000/uartx->uart_baud_rate)-uart_int)*64)+.5;
HW_WR_PIN(uartx->uart_no+UARTCTL,0,0);
	switch(uartx->uart_no)
	{
	case 0:
    HW_WR_PIN(UART0+UARTCTL,5,0);
    HW_WR_PIN(UART0+UARTCC,0,1);
    HW_WR_PIN(UART0+UARTCC,2,1);
    HW_WR_port((UART0+UARTIBRD),uart_int);
    HW_WR_port((UART0+UARTFBRD),uart_frac);
    HW_WR_port((UART0+UART_LINE_CTL),0X00000060);
    HW_WR_port((UART0+UARTCTL),0X00000301);
    break;
case 1:
    HW_WR_PIN(UART1+UARTCTL,5,0);
    HW_WR_PIN(UART1+UARTCC,0,1);
    HW_WR_PIN(UART1+UARTCC,2,1);
    HW_WR_port((UART1+UARTIBRD),uart_int);
    HW_WR_port((UART1+UARTFBRD),uart_frac);
    HW_WR_port((UART1+UART_LINE_CTL),0X00000060);
    HW_WR_port((UART1+UARTCTL),0X00000301);
    break;
case 2:
    HW_WR_PIN(UART2+UARTCTL,5,0);
    HW_WR_PIN(UART2+UARTCC,0,1);
    HW_WR_PIN(UART2+UARTCC,2,1);
    HW_WR_port((UART2+UARTIBRD),uart_int);
    HW_WR_port((UART2+UARTFBRD),uart_frac);
    HW_WR_port((UART2+UART_LINE_CTL),0X00000060);
    break;
case 3:
    HW_WR_PIN(UART3+UARTCTL,5,0);
    HW_WR_PIN(UART3+UARTCC,0,1);
    HW_WR_PIN(UART3+UARTCC,2,1);
    HW_WR_port((UART3+UARTIBRD),uart_int);
    HW_WR_port((UART3+UARTFBRD),uart_frac);
    HW_WR_port((UART3+UART_LINE_CTL),0X00000060);
    break;
case 4:
    HW_WR_PIN(UART4+UARTCTL,5,0);
    HW_WR_PIN(UART4+UARTCC,0,1);
    HW_WR_PIN(UART4+UARTCC,2,1);
    HW_WR_port((UART4+UARTIBRD),uart_int);
    HW_WR_port((UART4+UARTFBRD),uart_frac);
    HW_WR_port((UART4+UART_LINE_CTL),0X00000060);
    break;
case 5:
    HW_WR_PIN(UART5+UARTCTL,5,0);
    HW_WR_PIN(UART5+UARTCC,0,1);
    HW_WR_PIN(UART5+UARTCC,2,1);
    HW_WR_port((UART5+UARTIBRD),uart_int);
    HW_WR_port((UART5+UARTFBRD),uart_frac);
    HW_WR_port((UART5+UART_LINE_CTL),0X00000060);
    break;
case 6:
    HW_WR_PIN(UART6+UARTCTL,5,0);
    HW_WR_PIN(UART6+UARTCC,0,1);
    HW_WR_PIN(UART6+UARTCC,2,1);
    HW_WR_port((UART6+UARTIBRD),uart_int);
    HW_WR_port((UART6+UARTFBRD),uart_frac);
    HW_WR_port((UART6+UART_LINE_CTL),0X00000060);
    break;
case 7:
    HW_WR_PIN(UART7+UARTCTL,5,0);
    HW_WR_PIN(UART7+UARTCC,0,1);
    HW_WR_PIN(UART7+UARTCC,2,1);
    HW_WR_port((UART7+UARTIBRD),uart_int);
    HW_WR_port((UART7+UARTFBRD),uart_frac);
    HW_WR_port((UART7+UART_LINE_CTL),0X00000060);
default:
	;}
    HW_WR_PIN(uartx->uart_no+UARTCTL,0,1);
}

void SEND_DATA(uart_t * uartx){
	HW_WR_port(uartx->uart_no+UART_DATA,1);

}
