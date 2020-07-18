/*
 * Tasks.c
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#include "Tasks.h"
#include"../Elements/Elements.h"
#include"../ADC/ADC.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"
#include"../SSD/SSD.h"
#include"../Temperature/Temperature.h"
#include"../EEPROM/EEPROM.h"
#include"../Buttons/Buttons.h"


/* Start Task1 function */
void Scheduler_Task1(void) /*20ms*/
{   
   
	SSD_MainFunction();
    Buttons_MainFunction();
    
}

/* Start Task2 function */
void Scheduler_Task2(void)	/*100ms*/
{    
	Temperature_MainFunction();
	Elements_MainFunction();     
}
/* Start Task3 function */
void Scheduler_Task3(void) /*500ms*/
{
    ModeManager_MainFunction();	
    Set_EEPROM_Data();
}
