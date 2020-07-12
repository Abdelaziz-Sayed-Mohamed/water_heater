/*
 * WaterHeater_Mode.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef WATERHEATER_MODE_H_
#define WATERHEATER_MODE_H_
#include "stdint.h"
#include"../gpio/gpio.h"
typedef enum _Select_Mode_t
{
   Off_Mode=0,
   Normal_Mode=1,
   Setting_Mode=2
}Select_Mode_t;


typedef struct _MODE_t
{
	Select_Mode_t Select_Mode;
	uint8_t Setting_Mode_Timer ;
}MODE_t;

MODE_t Mode;
void Mode_Init(void);
void Select_Mode(void);
void Start_Setting_Timer(uint16_t Timer_Ms ,uint16_t Peroid_Task);
void Reset_Setting_Timer(void);
void Mode_MainFunction(void);
#endif /* WATERHEATER_MODE_H_ */