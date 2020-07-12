/*
 * Buttons.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#include "Buttons.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"
#include"../gpio/gpio.h"
#include"stdbool.h"
void On_Off_Init(void)
{

    TRISBbits.TRISB0=1;          //Configure PB0 As Input Pin
    INTCONbits.INTE=1;           //Enable External Interrupt
    _RESET_EXTI_ON_OFF_FLAG;     //Clear External Interrupt Flag
    INTEDG=1;                    //Configure Interrupt In Rising Edge

}


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

void Read_UP_DOWN_BUTTONS(void)
{
    if(((READ_PIN(UP_BUTTON_PORT,UP_BUTTON_PIN)==true) ||(READ_PIN(DOWN_BUTTON_PORT,DOWN_BUTTON_PIN)==true)) && Mode.Select_Mode==Normal_Mode) //Check The Up Button Pressed OR Down Button Pressed And Mode Was Normal Mode)
    {
    	 Mode.Select_Mode=Setting_Mode;
    }
}
