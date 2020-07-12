/* Includes ------------------------------------------------------------------*/
#include "Tasks.h"
#include"../Elements/Elements.h"
#include"../ADC/ADC.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"
#include"../Display/Display.h"
#include"../Temperature/Temperature.h"

/* Start Task1 function */
void Scheduler_Task1(void) /*20ms*/
{
	Display_MainFunction();
}

/* Start Task2 function */
void Scheduler_Task2(void)	/*100ms*/
{
	ADC_Conv_MainFunction();
	LED_MainFunction();
    
}
/* Start Task3 function */
void Scheduler_Task3(void) /*200ms*/
{
    Mode_MainFunction();
	Elements_MainFunction();

}
