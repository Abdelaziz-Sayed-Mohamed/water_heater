/*
 * Temperature.c
 *
 *  Created on: Jul 7, 2020
 *      Author: Abdelaziz Sayed
 */

#include "Temperature.h"
#include"../Average/Average.h"
#include"../ADC/ADC.h"



void Temperature_Calc(uint8_t ADC_VALUE)
{
	Temperature.Temp_Value=ADC_VALUE * ADC_RESOLUTION;                    //Convert ADC value to Temperature Value
	Average_Value(Temperature.Temp_Value, &Temperature.Average_Value);    //Get  Average_Value Of Temperature Values
	Temperature.Average_NValues=(Temperature.Average_NValues+1)%AVERAGE_BUFFER_SIZE;

	if(Temperature.Average_NValues==NValues) //At least 10 Values to start Display Temperature
	{
       Set_Average_Value_Ready_Flag;
	}

}
