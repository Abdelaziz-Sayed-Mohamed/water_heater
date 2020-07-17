/*
 * Elements.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef ELEMENTS_H_
#define ELEMENTS_H_

#include"Elements_Cfg.h"

#define ResetLedCounter           Counter=1
#define IS_Average_Value_Ready    Temperature.Average_Value_Ready_Flag==1

#define HEATER_ON   SET_PIN(HEATER_PORT,HEATER_PIN);    //Turn On Heater
#define HEATER_OFF  RESET_PIN(HEATER_PORT,HEATER_PIN);  //Turn Off Heater
#define COOLER_ON   SET_PIN(COOLER_PORT,COOLER_PIN);    //Turn On Cooler
#define COOLER_OFF  RESET_PIN(COOLER_PORT,COOLER_PIN);  //Turn Off Cooler
#define LED_ON      SET_PIN(LED_PORT,LED_PIN);          //Turn On LED
#define LED_OFF     RESET_PIN(LED_PORT,LED_PIN);        //Turn Off LED
#define LED_BLINK   TOGGLE_PIN(LED_PORT,LED_PIN);       //Turn Off LED


typedef enum _LED_STATUS_t
{
	 _LED_OFF=0,
	 _LED_ON=1,
	 _LED_BLINK=2
}LED_STATUS_t ;

LED_STATUS_t LED_Status;

void LED_Control(void);
void LED_BLINKING(uint16_t Time_Ms);
void Elements_Init(void);
void Elements_MainFunction(void);
#endif /* ELEMENTS_H_ */



