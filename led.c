/*
 * led.c
 *
 *  Created on: Feb 29, 2016
 *      Author: mohamed
 */
#include"hw_types.h"
#include"types.h"
#include"hw_gpio.h"
#include"GPIO.h"
#include"led.h"
portErrorObj_t inil_led(pin_t *ledx)
{
	     ledx->dir=OUTPUT_PIN;
	     ledx->fun=GPIO;
	     ledx->Pur=0;
	     ledx->pdr=0;
	     ledx->pin=DIG;
	init_pin(ledx);
	return S_PASS;
}
portErrorObj_t led_val(pin_t * ledx )
{

	write_pin(ledx);
return S_PASS;
}
portErrorObj_t toggle_led(pin_t *ledx)
{

	toggle_pin(ledx);
return S_PASS;

}


