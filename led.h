/*
 * led.h
 *
 *  Created on: Feb 29, 2016
 *      Author: mohamed
 */

#ifndef LED_H_
#define LED_H_

#include"hw_types.h"
#include"types.h"
#include"hw_gpio.h"
#include"GPIO.h"

portErrorObj_t inil_led(  pin_t *ledx);
portErrorObj_t led_val(pin_t *led_t);
portErrorObj_t toggle_led(pin_t *led_t);
pin_t led1;

#endif /* LED_H_ */
