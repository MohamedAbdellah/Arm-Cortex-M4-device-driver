
/*
 * GPIO.c
 *
 *  Created on: Feb 27, 2016
 *      Author: mohamed and barakat
 */

#include"hw_types.h"
#include"types.h"
#include"hw_gpio.h"
#include"GPIO.h"
portErrorObj_t init_pin(pin_t * pinx)
{
	if (pinx->pin_no > MAX_PINS)
	  {
	    return PINNO_OVF;
      }
	 else
		  {
		    /*Do Nothing*/
	      }
     	 if (pinx->pin_port==BASE_A)
		        HW_WR_PIN(GPIO_RMCGC,0,1);
	else if(pinx->pin_port==BASE_B)
				HW_WR_PIN(GPIO_RMCGC,1,1);
	else if(pinx->pin_port==BASE_C)
				HW_WR_PIN(GPIO_RMCGC,2,1);
	else if(pinx->pin_port==BASE_D)
				HW_WR_PIN(GPIO_RMCGC,3,1);
	else if(pinx->pin_port==BASE_E)
				HW_WR_PIN(GPIO_RMCGC,4,1);
	else if(pinx->pin_port==BASE_F)
				HW_WR_PIN(GPIO_RMCGC,5,1);
	else
	{
		/*MSRA*/
	}


	 HW_WR_PIN((pinx->pin_port + GPIO_DIR ) ,pinx->pin_no,pinx->dir);       /* inil  dir*/

	 HW_WR_PIN((pinx->pin_port + GPIO_AFS ) ,pinx->pin_no,pinx->fun) ;       /* inil  fun*/

	 HW_WR_PIN((pinx->pin_port + GPIO_DIG ) ,pinx->pin_no,pinx->pin)  ;      /* inil  dig*/

	 if(pinx->dir==INPUT_PIN)
	 {
		 if(pinx->Pur==HIGH)
		   {
			 HW_WR_PIN((pinx->pin_port + GPIO_PUR ) ,pinx->pin_no,pinx->pin);
		   }
         else if(pinx->pdr==HIGH)
           {
        	 HW_WR_PIN((pinx->pin_port + GPIO_PDR ) ,pinx->pin_no,pinx->pin);
           }
         else
           {

           }
	 }
  return S_PASS;
}
/*===================================================================================================================================================*/



/*===================================================================================================================================================*/
portErrorObj_t read_pin(pin_t * pinx, uint32 * val)
{
	 *val= HW_RD_PIN( (pinx->pin_port + GPIO_DATA ) ,pinx->pin_no);

			 return S_PASS;
}

/*===================================================================================================================================================*/

portErrorObj_t write_pin(pin_t * pinx)
{
	HW_WR_PIN( (pinx->pin_port + GPIO_DATA ) ,pinx->pin_no,pinx->data);
return S_PASS;
}

/*======================================================================================================================================================*/

portErrorObj_t toggle_pin(pin_t * pinx)
{
	HW_toggle_PIN( (pinx->pin_port + GPIO_DATA ) ,pinx->pin_no);
    return S_PASS;
}

/*======================================================================================================================================================*/
/*======================================================================================================================================================*/

 portErrorObj_t init_port(port_t *portx)
  {

		if (portx->port==BASE_A)
			HW_WR_PIN(GPIO_RMCGC,0,1);

		else if(portx->port==BASE_B)
					HW_WR_PIN(GPIO_RMCGC,1,1);

		else if(portx->port==BASE_C)
						HW_WR_PIN(GPIO_RMCGC,1,1);

		else if(portx->port==BASE_D)
						HW_WR_PIN(GPIO_RMCGC,1,1);

		else if(portx->port==BASE_E)
						HW_WR_PIN(GPIO_RMCGC,1,1);
		else
		{  /*=======================================================================================*/	 }


		 HW_WR_port((portx->port + GPIO_DIR ) ,portx->dir) ;         /* inil  dir*/

		 HW_WR_port((portx->port + GPIO_AFS ) ,portx->fun) ;        /* inil  fun*/

		 HW_WR_port((portx->port + GPIO_DIG ) ,portx->dig_port) ;       /* inil  dig*/

		 if(portx->dir==INPUT_PORT)
		 {

			 if(portx->pur==HIGH)
			    {
			 	  HW_WR_port((portx->port + GPIO_PUR ) , portx->pur);
			    }
	         else if(portx->pdr==HIGH)
	            {
	        	  HW_WR_port((portx->port + GPIO_PDR ) , portx->pdr);
	            }
	         else
	            {

	            }

		 }

		 return S_PASS;
  }




 portErrorObj_t write_port(port_t *portx)
 {

	 HW_WR_port((portx->port + GPIO_DATA ) , portx->data);

	 return S_PASS;

 }



 portErrorObj_t read_port(port_t *portx,uint32 *val)
  {

 	*val= HW_RD_port((portx->port + GPIO_DATA ));

 	 return S_PASS;

  }


