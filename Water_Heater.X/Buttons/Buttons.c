/*
 * Buttons.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#include "Buttons.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"
#include"stdbool.h"
#include"../SSD/SSD.h"

/****************************************************************************************/
/*    Function Name           : On_Off_Init          			                        */
/*    Function Description    : Init on-of button as EXTI                               */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void On_Off_Init(void)
{

    INTCONbits.INTE=1;           //Enable External Interrupt
    INTEDG=1;                    //Configure Interrupt In Rising Edge
    RESET_EXTI_ON_OFF_FLAG;      //Clear External Interrupt Flag
   
}


/****************************************************************************************/
/*    Function Name           : EXTI_On_Off_CallBack          			                */
/*    Function Description    : Toggling mode from on to off or from off to on          */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void EXTI_On_Off_CallBack(void)
{
	if((Mode.Select_Mode==Setting_Mode) || (Mode.Select_Mode==Normal_Mode))
	{

		Mode.Select_Mode=Off_Mode;

	}
	else if (Mode.Select_Mode==Off_Mode)
	{

		Mode.Select_Mode=Normal_Mode;

	}
}




/****************************************************************************************/
/*    Function Name           : Buttons_MainFunction          			                */
/*    Function Description    : Check if the up or down buttons pressed to change mode
 *                              frome normal to setting mode or set up/down flags 
 *                              set_temp                                                */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void Buttons_MainFunction(void)
{
    if(((READ_PIN(UP_BUTTON_PORT,UP_BUTTON_PIN)==Button_Pressed) ||(READ_PIN(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN)==Button_Pressed))) //Check The Up Button Pressed OR Down Button Pressed And Mode Was Normal Mode)
    {
    	if(Mode.Select_Mode==Normal_Mode)
        {
         Mode.Select_Mode=Setting_Mode;
        }
        else if(Mode.Select_Mode==Setting_Mode)
        {
            if(READ_PIN(UP_BUTTON_PORT,UP_BUTTON_PIN)==Button_Pressed)
            {
                Buttons.UpFlag=Set_UpButton_Flag;
                Reset_DownButton_Flag;
                Enable_SSD=Enable_SSD_On;          //Enable SSD once SET_TEMP changed
                ResetSSDCounter;                   // Reset SSD counter
            }
            else if(READ_PIN(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN)==Button_Pressed)
            {
               Buttons.DownFlag=Set_DownButton_Flag;
               Reset_UpButton_Flag;
               Enable_SSD=Enable_SSD_On;          //Enable SSD once SET_TEMP changed
               ResetSSDCounter;                   // Reset SSD counter
            }    
        }                
    }
}
