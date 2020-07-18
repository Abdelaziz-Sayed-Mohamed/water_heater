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
#include"../SSD/SSD.h"


/****************************************************************************************/
/*    Function Name           : Mode_Init          			                            */
/*    Function Description    : Init System Mode with Off_Mode and if EEPROM not defined 
 *                              init Set_Temp with DEFAULT_SET_TEMP value               */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/

void ModeManager_Init(void)
{
	Mode.Select_Mode=Off_Mode;     //The System will start in Off mode until On_Off_ Button pressed 
    #if EEPROM           	
    #else
    Temperature.Set_Temp=DEFAULT_SET_TEMP;
    #endif
}


/****************************************************************************************/
/*    Function Name           : ModeManager_MainFunction          			            */
/*    Function Description    : Check Mode and adjust set_temp                          */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void ModeManager_MainFunction(void)
{
	
   if(Mode.Select_Mode==Setting_Mode)
   {

	   Mode_Setting_Timer(Setting_Time); //Start Setting Timer to switch mode from setting to normal mode if up or down buttons not pressed
	   if(Buttons.UpFlag &&!Buttons.DownFlag && Temperature.Set_Temp !=MAX_SET_TEMP) //Check the up button pressed and down button not pressed and setting limit time not expired
	    {
         
	  	  Temperature.Set_Temp += TEMP_STEP;  //increase the set temperature by 5 degrees
          Enable_SSD=Enable_SSD_On;           //Enable SSD once SET_TEMP changed
          ResetSSDCounter;                    //Reset SSD counter
	  	  Reset_Setting_Timer;                //reset the setting time counter
          Reset_UpButton_Flag;                //Reset_DownButton_Flag 
          
	    }
	    else if(Buttons.DownFlag &&!Buttons.UpFlag&& Temperature.Set_Temp !=MIN_SET_TEMP) //Check the down button pressed and up button not pressed and setting limit time not expired
	    {
	  	  Temperature.Set_Temp -= TEMP_STEP; //decrease the set temperature by 5 degrees
          Enable_SSD=Enable_SSD_On;          //Enable SSD once SET_TEMP changed
          ResetSSDCounter;                   // Reset SSD counter
	  	  Reset_Setting_Timer;               //reset the setting time counter
          Reset_DownButton_Flag;             //Reset_DownButton_Flag 
          
	    }
   }

}


/****************************************************************************************/
/*    Function Name           : Mode_Setting_Timer          			                */
/*    Function Description    : Timer to count Timer_Ms  to to return Normal mode again */                                          
/*    Parameter In            : Timer_Ms                                                */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void Mode_Setting_Timer(uint16_t Timer_Ms)
{
	if(Mode.Setting_Mode_Timer*Setting_Timer_TaskPeroid==Timer_Ms)
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
