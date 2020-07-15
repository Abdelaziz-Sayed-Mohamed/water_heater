/*
 * WaterHeater_Mode.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#include "WaterHeater_Mode.h"
#include"WaterHeater_Mode_Cfg.h"
#include "../Temperature/Temperature.h"
#include"../Buttons/Buttons.h"
#include"../EEPROM/EEPROM.h"




void Mode_Init(void)
{
	Mode.Select_Mode=Off_Mode;     //The System will start in Off mode until On_Off_ Button pressed 
    #if EEPROM           	
    #else
    Temperature.Set_Temp=DEFAULT_SET_TEMP;
    #endif
}



void Mode_MainFunction(void)
{
	

   if(Mode.Select_Mode==Setting_Mode)
   {

	   Start_Setting_Timer(Setting_Time,Setting_Timer_TaskPeroid); //Start Setting Timer to switch mode from setting to normal mode if up or down buttons not pressed
	   if(Buttons.UpFlag &&!Buttons.DownFlag && Temperature.Set_Temp !=MAX_SET_TEMP) //Check the up button pressed and down button not pressed and setting limit time not expired
	    {
	  	  Temperature.Set_Temp += TEMP_STEP;  //increase the set temperature by 5 degrees
	  	  Reset_Setting_Timer;                //reset the setting time counter
          Reset_UpButton_Flag;
	    }
	    else if(Buttons.DownFlag &&!Buttons.UpFlag&& Temperature.Set_Temp !=MIN_SET_TEMP) //Check the down button pressed and up button not pressed and setting limit time not expired
	    {
	  	  Temperature.Set_Temp -= TEMP_STEP; //decrease the set temperature by 5 degrees
	  	  Reset_Setting_Timer;               //reset the setting time counter
          Reset_DownButton_Flag;
	    }
   }


}



void Start_Setting_Timer(uint16_t Timer_Ms ,uint16_t Peroid_Task)
{
	if(Mode.Setting_Mode_Timer*Peroid_Task==Timer_Ms)
	{
		Set_Store_Set_Temp_Flag;
		Mode.Select_Mode=Normal_Mode;
		Reset_Setting_Timer;
        Reset_UpButton_Flag;
        Reset_DownButton_Flag;

	}
	else
	{
		Mode.Setting_Mode_Timer++;
	}

}
