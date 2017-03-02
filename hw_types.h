/*
 * hw_types.h
 *
 *  Created on: Feb 29, 2016
 *      Author: mohamed
 */

#ifndef HW_TYPES_H_
#define HW_TYPES_H_



/*
 * hw_types.c
 *
 *  Created on: Feb 26, 2016
 *      Author: mohamed
 */
//#include"hw_types.h"
#include"types.h"

static inline uint32  HW_RD_PIN(uint32 reg, uint32 pin )
{

   return  (*(volatile uint32*)(reg) & (1 <<pin)) >>pin;

}

static inline void HW_WR_PIN(uint32 reg, uint32 pin, uint32 val) {

	if (1 == val)
	{
		*(volatile uint32 *) (reg) |= 1 << pin; //or
	}
	else
	{
		*(volatile uint32 *) (reg) &= ~(1 << pin);
	}
}

/*=====================================================================================================================================================*/
static inline void HW_toggle_PIN(uint32 reg, uint32 pin)
{
       *(volatile uint32 *) (reg) ^= 1 << pin ;
}
/*=====================================================================================================================================================*/
static inline void HW_WR_port(uint32 reg ,uint32 val )
{
	*(volatile uint32 *)(reg)=val;
}


static inline uint32 HW_RD_port(uint32 reg  )
{
	return (*(volatile uint32 *)(reg));
}


#endif /* HW_TYPES_H_ */
