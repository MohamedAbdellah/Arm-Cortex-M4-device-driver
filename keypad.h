#ifndef _keypad_
#define _keypad_

#include "types.h"
#include "hw_gpio.h"
#include "hw_types.h"
#include "GPIO.h"

#define COL 4
#define ROW 3

typedef struct keypad{
	pin_t  pin_str;
	uint32 row_no;
	uint32 col_no;
	uint32 row_port[ROW];
	uint32 col_port[COL];
	uint32 row_pin[ROW];
	uint32 col_pin[COL];
	uint32 val;
	uint32 keypad[COL][ROW];
	uint32 switch_p;
}keypad_t;



portErrorObj_t init_keypad(keypad_t *keypadx);
uint32 keypad_scan(keypad_t *keypadx,uint32 *val);


#endif
