/*
 * GPIO.h
 *
 *  Created on: Feb 27, 2016
 *      Author: mohamed
 */

#ifndef GPIO_H_
#define GPIO_H_


typedef enum pinDir{
	INPUT_PIN = 0,
	OUTPUT_PIN
}pinDirObj_t;

typedef enum portDir{
	INPUT_PORT = 0,
	OUTPUT_PORT=255
}portDirObj_t;

typedef enum errorPort{
	E_FAIL = 0,
	S_PASS,
	PINNO_OVF,
	INTVAL_ERORR
}portErrorObj_t;


typedef enum DATA{
	LOW = 0,
	HIGH
}portDataObj_t;


typedef enum PinFun{
	GPIO=0
}PinFunObj_t;

typedef enum dig{
	DIG=1
}DigObj_t;


typedef enum dig_port{
	 DIG_PORT=255
}DigPortObj_t;


typedef struct port{
	uint32 port;
    uint32 data;
    portDirObj_t dir;
    PinFunObj_t fun;
    uint32 pur;
    uint32 pdr;
    DigPortObj_t dig_port;
}port_t;



typedef struct pin{
	uint32 pin_port;
    uint32 pin_no;
    portDataObj_t data;
    pinDirObj_t dir;
    PinFunObj_t fun;
    uint32 Pur;
    uint32 pdr;
    DigObj_t pin;
}pin_t;

/*=================================================================================================================================================*/

portErrorObj_t init_port(port_t *portx);
portErrorObj_t read_port(port_t *portx,uint32 *val);
portErrorObj_t write_port(port_t *portx);


/*==================================================================================================================================================*/

portErrorObj_t init_pin(pin_t * pinx) ;
portErrorObj_t read_pin(pin_t * pinx,uint32 * val);
portErrorObj_t write_pin(pin_t * pinx);
portErrorObj_t toggle_pin(pin_t * pinx);

#endif /* GPIO_H_ */
