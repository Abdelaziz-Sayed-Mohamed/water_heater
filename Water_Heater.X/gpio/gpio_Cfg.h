/*
 * gpio_Cfg.h
 *
 *  Created on: Jul 8, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef GPIO_CFG_H_
#define GPIO_CFG_H_

#include"../Config.h"

#define DOWN_BUTTON_PORT           PORTB
#define DOWN_BUTTON_DIRECTION      TRISB
#define DOWN_BUTTON_PIN             1

#define UP_BUTTON_PORT             PORTB
#define UP_BUTTON_DIRECTION        TRISB
#define UP_BUTTON_PIN                2

#define ON_OFF_BUTTON_PORT         PORTB
#define ON_OFF_BUTTON_DIRECTION    TRISB
#define ON_OFF_BUTTON_PIN            0


#define LED_PORT                   PORTB
#define LED_DIRECTION              TRISB
#define LED_PIN                     4


#define HEATER_PORT                PORTC
#define HEATER_DIRECTION           TRISC
#define HEATER_PIN                   5

#define COOLER_PORT                PORTC
#define COOLER_DIRECTION           TRISC
#define COOLER_PIN                  2

#define DIGIT1_PORT                PORTA
#define DIGIT1_DIRECTION           TRISA
#define DIGIT1_PIN                   5

#define DIGIT2_PORT                PORTA
#define DIGIT2_DIRECTION           TRISA
#define DIGIT2_PIN                   4

#define TEMPERATURE_SENSOR_PORT        PORTA
#define TEMPERATURE_SENSOR_DIRECTION   TRISA
#define TEMPERATURE_SENSOR_PIN           2

#define EEPROM_SCK_PORT            PORTC
#define EEPROM_SCK_DIRECTION       TRISC
#define EEPROM_SCK_PIN               3

#define EEPROM_SDA_PORT            PORTC
#define EEPROM_SDA_DIRECTION       TRISC
#define EEPROM_SDA_PIN               4

#define _7SEGMENT_PORT             PORTD
#define _7SEGMENT_DIRECTION        TRISD

#endif /* GPIO_CFG_H_ */
