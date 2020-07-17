/* 
 * File:   Elements_Cfg.h
 * Author: Abdalaziz Sayed
 *
 * Created on July 17, 2020, 8:26 PM
 */

#ifndef ELEMENTS_CFG_H
#define	ELEMENTS_CFG_H

#include"../gpio/gpio.h"

#define HEATER_PORT    _HEATER_PORT_
#define HEATER_PIN     _HEATER_PIN_
#define COOLER_PORT    _COOLER_PORT_
#define COOLER_PIN     _COOLER_PIN_
#define LED_PORT       _LED_PORT_
#define LED_PIN        _LED_PIN_

#define MARGIN                   (5U)
#define LED_BLINK_TIME            1000
#define LED_BLINK_TaskPeroid      100

#endif	/* ELEMENTS_CFG_H */

