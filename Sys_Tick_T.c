/*
 * Sys_Tick_T.c
 *
 *  Created on: Mar 10, 2016
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
//#include"switch.h

void init_timer_sys(void)
{

HW_WR_PIN(Sys_Tick_CON,0,1);
HW_WR_PIN(Sys_Tick_CON,1,1);
HW_WR_PIN(Sys_Tick_CON,2,0);

}
/*=================================================================================================================*/
void load_timer_sys(uint32 x)
{

	HW_WR_port(Sys_Tick_Rel ,((x*4000000)/1000)-1 );
}

