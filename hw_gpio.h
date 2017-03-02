/*
 * hw_gpio.h
 *
 *  Created on: Feb 27, 2016
 *      Author: mohamed
 */

#ifndef HW_GPIO_H_
#define HW_GPIO_H_
/*================================================================APB======================================================================*/
#define BASE_A 0x40004000
#define BASE_B 0x40005000
#define BASE_C 0x40006000
#define BASE_D 0x40007000
#define BASE_E 0x40024000
#define BASE_F 0x40025000

#define GPIO_RMCGC 0x400FE608

//#define GPIO_RMCGC 0x400FE108


#define GPIO_DATA  0x3FC
#define GPIO_DIR   0x400
#define GPIO_AFS   0x420
#define GPIO_PUR   0x510
#define GPIO_PDR   0x514
#define GPIO_DIG   0x51c
#define GPIO_PORT_CTL 0x52c
#define AMSEL_offset 0x528

#endif /* HW_GPIO_H_ */
