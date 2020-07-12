/*
 * gpio.h
 *
 *  Created on: Jul 8, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef GPIO_H_
#define GPIO_H_

#include"gpio_Cfg.h"
#define INPUT  1
#define OUTPUT 0


      
#define SET_PIN(PORT,PIN)    (PORT|= (1<<PIN))     //Set 1   in specific PORT
#define RESET_PIN(PORT,PIN)  (PORT &= ~(1<<PIN))   //Set 0  in specific PORT
#define READ_PIN(PORT,PIN)   ((PORT>>PIN)&1)       //Check INPUT PIN 1 OR 0
#define TOGGLE_PIN(PORT,PIN) (PORT^= (1<<PIN))

#define SET_PIN_DIRECTION(DIRECTION_PORT,PIN,DIRECTION)    (DIRECTION==OUTPUT)? (RESET_PIN(DIRECTION_PORT,PIN)):(SET_PIN(DIRECTION_PORT,PIN))  
#define SET_PORT_DIRECTION(DIRECTION_PORT,DIRECTION)       (DIRECTION==OUTPUT)? (DIRECTION_PORT=OUTPUT):(DIRECTION_PORT=INPUT)  
void GPIO_Init(void);


#endif /* GPIO_H_ */
