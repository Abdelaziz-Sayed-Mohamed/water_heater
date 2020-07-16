/*
 * Elements.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */
#include"Elements.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"
#include"../Temperature/Temperature.h"

void Elements_Init(void)
{
	LED_Status=_LED_OFF;
	HEATER_OFF
	COOLER_OFF

}

void LED_BLINKING(uint16_t Time_Ms,uint16_t Task_Peroid)
{
 static uint8_t Counter=1;

   if(Counter*Task_Peroid==Time_Ms)
   {
	   LED_BLINK
       ResetLedCounter;        	   
   }
   else
   {
	   Counter++;
   }
}


void LED_Control(void)
{
    switch(LED_Status)
    {
        case _LED_BLINK : LED_BLINKING(LED_BLINK_TIME,LED_BLINK_TaskPeroid);
                          break;
            
        case _LED_ON    : LED_ON;
                          break;                  
                        
        case _LED_OFF   : LED_OFF;
                          break;                 
    }       
         
}
void Elements_MainFunction(void)
{
  if(IS_Average_Value_Ready && Mode.Select_Mode==Normal_Mode)           //Check if we read at least 10 ADC_VALUE and System in normal mode
  {

        if(Temperature.Average_Value < (Temperature.Set_Temp - MARGIN)) // Check if the Temperature lower than Temperature Set
         {
        	COOLER_OFF                        //Turn Off Cooler
        	HEATER_ON                         //Turn On Heater
            LED_Status=_LED_BLINK;             //LED Blinking Every 1 Sec
			           
         }else if(Temperature.Average_Value > (Temperature.Set_Temp + MARGIN)) // Check if the Temperature Higher than Temperature Set
         {
        	 HEATER_OFF                      //Turn Off Heater
        	 COOLER_ON                        //Turn On Cooler
             LED_Status=_LED_ON;     
         }   
        
  }
  else
  {
	  COOLER_OFF
	  HEATER_OFF
      LED_Status=_LED_OFF;
  }
  LED_Control();
}
