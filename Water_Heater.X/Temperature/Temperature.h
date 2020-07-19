/*
 * Temperature.h
 *
 *  Created on: Jul 7, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_
#include "stdint.h"
#include"../ADC/ADC.h"
#include"../WaterHeater_Mode/WaterHeater_Mode.h"

#define NValues 9
#define Set_Average_Value_Ready_Flag   Temperature.Average_Value_Ready_Flag=1

typedef struct _TEMP_t
{
	uint16_t Temp_Value;
	uint16_t Average_Value;
    uint16_t ADC_Value;
	uint8_t Set_Temp;
	uint8_t Average_Value_Ready_Flag  :1;
    uint8_t Store_Set_Temp_Flag  :1;
	uint8_t Average_NValues;
}TEMP_t;

TEMP_t Temperature;



void Temperature_MainFunction(void);
void Temperature_Calc(void);

#endif /* TEMPERATURE_H_ */
