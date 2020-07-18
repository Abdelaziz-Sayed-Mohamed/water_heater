/*
 * Buttons.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#include "Buttons.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"

 static uint8_t Debounce_Up[NSample];
 static uint8_t Debounce_Down[NSample];
 
/****************************************************************************************/
/*    Function Name           : Buttons_Init          			                        */
/*    Function Description    : Init Buttons and on-off button as EXTI                  */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void Buttons_Init(void)
{
   
    memset( Debounce_Up    , Button_NotPressed , sizeof( Debounce_Up ) );   //Init Up Buttons as not pressed 
    memset( Debounce_Down  , Button_NotPressed , sizeof( Debounce_Down ) ); //Init Down Buttons as not pressed 
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
	if((Mode.Select_Mode==Setting_Mode) || (Mode.Select_Mode==Normal_Mode)) //if mode was Normal_Mode or Setting_Mode
	{

		Mode.Select_Mode=Off_Mode;    //change mode to Off mode

	}
	else if (Mode.Select_Mode==Off_Mode)   //if mode was off mode              
	{

		Mode.Select_Mode=Normal_Mode;      //change mode to Normal mode

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
    static uint8_t Counter_Debounce=0;
    Debounce_Down[Counter_Debounce]=READ_PIN(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN); //Get Up button value
    Debounce_Up[Counter_Debounce]=READ_PIN(UP_BUTTON_PORT,UP_BUTTON_PIN);       //Get Down button value
    Counter_Debounce=(Counter_Debounce+1)%(NSample+1);                          //Increment Counter until NSample Then reset it
  
    if(Debounce_Up[0]==Button_Pressed && Debounce_Up[1]==Button_Pressed &&Debounce_Up[2]==Button_Pressed) //Check if Up button Pressed         
    {
        if(Mode.Select_Mode==Setting_Mode)      //Check if i was in Setting Mode
        {
         Buttons.UpFlag=Set_UpButton_Flag;       //Set UpBotton Flag if i was in Setting Mode
        }
        else if (Mode.Select_Mode==Normal_Mode)  //Check if i was in Normal Mode
        {
         Mode.Select_Mode=Setting_Mode;          //Change mode to setting mode   
        }    
        Reset_Debounce_Up                        //Reset DebounceUp array
    }
    
    if(Debounce_Down[0]==Button_Pressed && Debounce_Down[1]==Button_Pressed &&Debounce_Down[2]==Button_Pressed)//Check if Down button Pressed 
    {        
     
        if(Mode.Select_Mode==Setting_Mode)      // Check if i was in Setting Mode
        {
         Buttons.DownFlag=Set_DownButton_Flag;  //Set Down Button Flag 
       
        }
        else if (Mode.Select_Mode==Normal_Mode)  // Check if i was in Normal Mode
        {
          Mode.Select_Mode=Setting_Mode;         //Change mode to setting mode
        }    
        Reset_Debounce_Down                       //Reset DebounceDown array
    }
    
}

   
