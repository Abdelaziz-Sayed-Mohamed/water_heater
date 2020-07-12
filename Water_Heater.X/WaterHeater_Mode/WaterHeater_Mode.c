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




void Mode_Init(void)
{

	Temperature.Set_Temp=DEFAULT_SET_TEMP;
	Mode.Select_Mode=Normal_Mode;
	Mode.Setting_Mode_Timer=1;
}



void Mode_MainFunction(void)
{
	Read_UP_DOWN_BUTTONS();

   if(Mode.Select_Mode==Setting_Mode)
   {
	   Start_Setting_Timer(5000,500); //Its Mean Time out event after 5 Sec if we Mapped Mode_MainFunction On 500ms Task Period
	   if((READ_PIN(UP_BUTTON_PORT,UP_BUTTON_PIN)==true) &&(READ_PIN(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN)==false) && Temperature.Set_Temp !=MAX_SET_TEMP) //Check the up button pressed and down button not pressed and setting limit time not expired
	    {
	  	  Temperature.Set_Temp += TEMP_STEP;  //increase the set temperature by 5 degrees
	  	  Reset_Setting_Timer();   //reset the setting time counter
	    }
	    else if((READ_PIN(UP_BUTTON_PORT,UP_BUTTON_PIN)==false) &&(READ_PIN(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN)==true) && Temperature.Set_Temp !=MIN_SET_TEMP) //Check the down button pressed and up button not pressed and setting limit time not expired
	    {
	  	  Temperature.Set_Temp -= TEMP_STEP; //decrease the set temperature by 5 degrees
	  	  Reset_Setting_Timer();  //reset the setting time counter

	    }
   }


}




void Reset_Setting_Timer(void)
{
	if(Mode.Select_Mode==Setting_Mode)
	{
		 Mode.Setting_Mode_Timer=1;
	}

}

void Start_Setting_Timer(uint16_t Timer_Ms ,uint16_t Peroid_Task)
{
	if(Mode.Setting_Mode_Timer*Peroid_Task==Timer_Ms)
	{
		//TODO:Write Temperature.Set_Temp in the flash
		Mode.Select_Mode=Normal_Mode;
		Mode.Setting_Mode_Timer=1;

	}
	else
	{
		Mode.Setting_Mode_Timer++;
	}

}
