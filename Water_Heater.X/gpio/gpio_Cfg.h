/*
 * gpio_Cfg.h
 *
 *  Created on: Jul 8, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef GPIO_CFG_H_
#define GPIO_CFG_H_

#include"../Config.h"

#define _DOWN_BUTTON_PORT_               PORTB
#define _DOWN_BUTTON_DIRECTION_          TRISB
#define _DOWN_BUTTON_PIN_                1
    
#define _UP_BUTTON_PORT_                 PORTB
#define _UP_BUTTON_DIRECTION_            TRISB
#define _UP_BUTTON_PIN_                  2
    
#define _ON_OFF_BUTTON_PORT_             PORTB
#define _ON_OFF_BUTTON_DIRECTION_        TRISB
#define _ON_OFF_BUTTON_PIN_              0
    
    
#define _LED_PORT_                       PORTB
#define _LED_DIRECTION_                  TRISB
#define _LED_PIN_                        4
    
    
#define _HEATER_PORT_                    PORTC
#define _HEATER_DIRECTION_               TRISC
#define _HEATER_PIN_                     5
    
#define _COOLER_PORT_                    PORTC
#define _COOLER_DIRECTION_               TRISC
#define _COOLER_PIN_                     2
    
#define _DIGIT1_PORT_                    PORTA
#define _DIGIT1_DIRECTION_               TRISA
#define _DIGIT1_PIN_                     5
    
#define _DIGIT2_PORT_                    PORTA
#define _DIGIT2_DIRECTION_               TRISA
#define _DIGIT2_PIN_                     4

#define _TEMPERATURE_SENSOR_PORT_        PORTA
#define _TEMPERATURE_SENSOR_DIRECTION_   TRISA
#define _TEMPERATURE_SENSOR_PIN_         2

#define _EEPROM_SCK_PORT_                PORTC
#define _EEPROM_SCK_DIRECTION_           TRISC
#define _EEPROM_SCK_PIN_                 3
    
#define _EEPROM_SDA_PORT_                PORTC
#define _EEPROM_SDA_DIRECTION_           TRISC
#define _EEPROM_SDA_PIN_                 4
    
#define _7SEGMENT_PORT_                 PORTD
#define _7SEGMENT_DIRECTION_            TRISD

#endif /* GPIO_CFG_H_ */
