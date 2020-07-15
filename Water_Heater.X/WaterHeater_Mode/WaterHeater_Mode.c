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
	Read_UP_DOWN_BUTTONS();     //Check if up or down buttons pressed to switch mode from normal to setting mode

   if(Mode.Select_Mode==Setting_Mode)
   {

	   Start_Setting_Timer(Setting_Time,Setting_Timer_TaskPeroid); //Start Setting Timer to switch mode from setting to normal mode if up or down buttons not pressed
	   if((READ_PIN(UP_BUTTON_PORT,UP_BUTTON_PIN)==Button_Pressed) &&(READ_PIN(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN)==Button_NotPressed) && Temperature.Set_Temp !=MAX_SET_TEMP) //Check the up button pressed and down button not pressed and setting limit time not expired
	    {
	  	  Temperature.Set_Temp += TEMP_STEP;  //increase the set temperature by 5 degrees
	  	  Reset_Setting_Timer;                //reset the setting time counter
	    }
	    else if((READ_PIN(UP_BUTTON_PORT,UP_BUTTON_PIN)==Button_NotPressed) &&(READ_PIN(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN)==Button_Pressed) && Temperature.Set_Temp !=MIN_SET_TEMP) //Check the down button pressed and up button not pressed and setting limit time not expired
	    {
	  	  Temperature.Set_Temp -= TEMP_STEP; //decrease the set temperature by 5 degrees
	  	  Reset_Setting_Timer;               //reset the setting time counter

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

	}
	else
	{
		Mode.Setting_Mode_Timer++;
	}

}
