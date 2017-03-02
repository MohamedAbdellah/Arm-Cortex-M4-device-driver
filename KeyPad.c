#include "hw_types.h"
//#include<util/delay.h>
#include"types.h"
#include"hw_gpio.h"
#include"GPIO.h"
#include"led.h"
//#include"switch.h"
#include"keypad.h"



portErrorObj_t init_keypad(keypad_t * keypadx)
	{int i;
	keypadx->pin_str.dir=OUTPUT_PIN;
	keypadx->pin_str.fun=GPIO;
	keypadx->pin_str.Pur=0;
	keypadx->pin_str.pdr=0;
    keypadx->pin_str.pin=DIG;
	   for ( i=0; i<ROW;i++)
	  {
		    keypadx->pin_str.pin_port=keypadx->row_port[i];
	        keypadx->pin_str.pin_no=keypadx->row_pin[i];
		    init_pin(&(keypadx->pin_str));
		    write_pin(&(keypadx->pin_str));
      }
	//init_port(keypadx->row_port,255); nnnn
	// write_port(keypadx->,255);nnn
	/*===============================================================================*/
		keypadx->pin_str.dir=INPUT_PIN;
		keypadx->pin_str.fun=GPIO;
		keypadx->pin_str.Pur=1;
		keypadx->pin_str.pdr=0;
	    keypadx->pin_str.pin=DIG;
	for ( i = 0; i < COL; i++)
	{
	    keypadx->pin_str.pin_port=keypadx->col_port[i];
        keypadx->pin_str.pin_no=keypadx->col_pin[i];
	    init_pin(&(keypadx->pin_str));
	    write_pin(&(keypadx->pin_str));
	}
	/*================================================================================*/
	return S_PASS;
}

uint32 keypad_scan(keypad_t *keypadx,uint32 *val)
{
	uint32 row;
	uint32 col ;

	     keypadx->pin_str.data=LOW;
for ( row = 0; row <= 2; row++)
	{
		        keypadx->pin_str.pin_port=keypadx->row_port[row];
		        keypadx->pin_str.pin_no=keypadx->row_pin[row];
				write_pin(&(keypadx->pin_str));

	   for ( col = 0; col <= 3; col++)
		  {
		     keypadx->pin_str.pin_port=keypadx->col_port[col];
		     keypadx->pin_str.pin_no=keypadx->col_pin[col];
	         read_pin(&(keypadx->pin_str),&keypadx->val);

			if (keypadx->val == 0)
			{
				keypadx->pin_str.pin_port=keypadx->row_port[row];
			    keypadx->pin_str.pin_no=keypadx->row_pin[row];
				keypadx->pin_str.data=HIGH;
				write_pin(&(keypadx->pin_str));
				return (keypadx->keypad[col][row]);
			}

		  }
	                keypadx->pin_str.pin_port=keypadx->row_port[row];
	  		        keypadx->pin_str.pin_no=keypadx->row_pin[row];
		write_pin(&(keypadx->pin_str));
	}
	return 0;
}

