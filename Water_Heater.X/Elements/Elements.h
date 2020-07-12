/*
 * Elements.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef ELEMENTS_H_
#define ELEMENTS_H_


#include"../gpio/gpio.h"
#define MARGIN       (5U)
#define _HEATER_ON   SET_PIN(HEATER_PORT,HEATER_PIN);    //Turn On Heater
#define _HEATER_OFF  RESET_PIN(HEATER_PORT,HEATER_PIN);  //Turn Off Heater
#define _COOLER_ON   SET_PIN(COOLER_PORT,COOLER_PIN);    //Turn On Cooler
#define _COOLER_OFF  RESET_PIN(COOLER_PORT,COOLER_PIN);  //Turn Off Cooler
#define _LED_ON      SET_PIN(LED_PORT,LED_PIN);          //Turn On LED
#define _LED_OFF     RESET_PIN(LED_PORT,LED_PIN);        //Turn Off LED
#define _LED_BLINK   TOGGLE_PIN(LED_PORT,LED_PIN);       //Turn Off LED


#define LED_BLINK_TIME 1000
#define LED_BLINK_TaskPeroid 100
#define ResetLedCounter     Counter=1


typedef enum _LED_STATUS_t
{
	 LED_OFF=0,
	 LED_ON=1,
	 LED_BLINK=2
}LED_STATUS_t ;

LED_STATUS_t LED_Status;


void LED_BLINKING(uint16_t Time_Ms,uint16_t Task_Peroid);
void Elements_Init(void);
void LED_MainFunction(void);
void Elements_MainFunction(void);
#endif /* ELEMENTS_H_ */



