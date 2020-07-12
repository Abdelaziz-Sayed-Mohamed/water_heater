/*
 * Elements.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */
#include"Elements.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"
#include"../Temperature/Temperature.h"

typedef enum _LED_STATUS_t
{
	 LED_OFF=0,
	 LED_ON=1,
	 LED_BLINK=2
}LED_STATUS_t ;

LED_STATUS_t LED_Status;

void Elements_Init(void)
{
	_LED_OFF
	_HEATER_OFF
	_COOLER_OFF

}


void LED_BLINKING(uint16_t Time_Ms,uint16_t Task_Peroid)
{
 static uint8_t Counter=1;

   if(Counter*Task_Peroid==Time_Ms)
   {
	   _LED_BLINK
	   Counter=1;
   }
   else
   {
	   Counter++;
   }

}

void LED_MainFunction(void)
{
	if(LED_Status==LED_BLINK && Mode.Select_Mode==Normal_Mode)
	{
		LED_BLINKING(1000,100);  //Its mean LED_MainFunction mapped on Task_peroid 100 ms and we need LED blink every 1 Sec
	}
	else if(LED_Status==LED_ON && Mode.Select_Mode==Normal_Mode)
	{
		_LED_ON
	}
	else if((Mode.Select_Mode==Off_Mode) || (Mode.Select_Mode==Setting_Mode))
	{
		_LED_OFF
	}

}




void Elements_Control(uint8_t Average_Temp)
{
  if(Temperature.Average_Value_Ready_Flag==1 && Mode.Select_Mode==Normal_Mode)
  {

        if(Average_Temp < (Temperature.Set_Temp - MARGIN)) // Check if the Temperature lower than Temperature Set
         {
        	_COOLER_OFF                        //Turn Off Cooler
        	_HEATER_ON                         //Turn On Heater
			LED_Status=LED_BLINK ;             //LED Blinking Every 1 Sec

         }else if(Average_Temp > (Temperature.Set_Temp + MARGIN)) // Check if the Temperature Higher than Temperature Set
         {

        	 _HEATER_OFF                      //Turn Off Heater
        	 _COOLER_ON                        //Turn On Cooler
			 LED_Status=LED_ON ;

         }
  }
  else
  {
	  _COOLER_OFF
	  _HEATER_OFF
  }
}
