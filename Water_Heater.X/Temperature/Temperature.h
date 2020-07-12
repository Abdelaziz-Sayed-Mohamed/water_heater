/*
 * Temperature.h
 *
 *  Created on: Jul 7, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_
#include "stdint.h"
typedef struct _TEMP_t
{
	uint8_t Temp_Value;
	uint8_t Average_Value;
	uint8_t Set_Temp;
	uint8_t Average_Value_Ready_Flag  :1;
	uint8_t Average_NValues;
}TEMP_t;

TEMP_t Temperature;

void Temperature_Calc(uint8_t ADC_VALUE);

#endif /* TEMPERATURE_H_ */
