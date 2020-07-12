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

#define _SET_  1
#define _RESET_ 0

//#define PORTB_PIN_DIRECTION(PIN,DIRECTION)   TRISBbits.TRISBPIN=DIRECTION
//#define PIN_DIRECTION(PORT,PIN,DIRECTION)      TRIS##PORT##bits.TRIS##PORT##PIN=DIRECTION;

#define SET_PIN(PORT,PIN)    (PORT|= (1<<PIN))      //Set 1   in specific PORT
#define RESET_PIN(PORT,PIN)    (PORT &= ~(1<<PIN))  //Set 0  in specific PORT
#define READ_PIN(PORT,PIN)   (PORT & (1<<PIN))      //Check INPUT PIN 1 OR 0
#define TOGGLE_PIN(PORT,PIN) (PORT^= (1<<PIN))

void GPIO_Init(void);


#endif /* GPIO_H_ */
