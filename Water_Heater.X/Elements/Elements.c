/*
 * Elements.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */
#include"Elements.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"
#include"../Temperature/Temperature.h"



/****************************************************************************************/
/*    Function Name           : Elements_Init          			                        */
/*    Function Description    : Init all elements with off state                        */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void Elements_Init(void)
{
	LED_Status=_LED_OFF;
	HEATER_OFF
	COOLER_OFF

}


/****************************************************************************************/
/*    Function Name           : LED_BLINKING          			                        */
/*    Function Description    : Blinking led every  Time_Ms                             */                                          
/*    Parameter In            : Time_Ms                                                 */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void LED_BLINKING(uint16_t Time_Ms)
{
 static uint8_t Counter=1;

   if(Counter*LED_BLINK_TaskPeroid==Time_Ms)
   {
	   LED_BLINK
       ResetLedCounter;        	   
   }
   else
   {
	   Counter++;
   }
}

/****************************************************************************************/
/*    Function Name           : LED_Control          			                        */
/*    Function Description    : Control LED according to led state                      */                                          
/*    Parameter In            : None                                                 */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void LED_Control(void)
{
    switch(LED_Status)
    {
        case _LED_BLINK : LED_BLINKING(LED_BLINK_TIME);
                          break;
            
        case _LED_ON    : LED_ON;
                          break;                  
                        
        case _LED_OFF   : LED_OFF;
                          break;                 
    }       
         
}

/****************************************************************************************/
/*    Function Name           : Elements_MainFunction          			                */
/*    Function Description    : control  Cooler and heater and set led state according
 *                              to Temperature.Average_Value                            */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
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
