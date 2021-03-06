/*
 * gpio.c
 *
 *  Created on: Jul 8, 2020
 *      Author: Abdelaziz Sayed
 */


#include "gpio.h"



/****************************************************************************************/
/*    Function Name           : GPIO_Init          			                            */
/*    Function Description    : set all GPIO pins direction                             */                                          
/*    Parameter In            : None                                                    */
/*    Parameter InOut         : None                                                    */
/*    Parameter Out           : None                                                    */
/*    Return Value            : None                                                    */
/*	  Requirement             :                   				                        */
/*    Notes                   :								                            */
/****************************************************************************************/
void GPIO_Init(void)
{
 
   SET_PIN_DIRECTION(_HEATER_DIRECTION_,_HEATER_PIN_,OUTPUT);
   SET_PIN_DIRECTION(_COOLER_DIRECTION_,_COOLER_PIN_,OUTPUT);
   SET_PIN_DIRECTION(_LED_DIRECTION_,_LED_PIN_,OUTPUT);
   SET_PIN_DIRECTION(_DIGIT1_DIRECTION_,_DIGIT1_PIN_,OUTPUT);
   SET_PIN_DIRECTION(_DIGIT2_DIRECTION_,_DIGIT2_PIN_,OUTPUT);
   SET_PIN_DIRECTION(_DOWN_BUTTON_DIRECTION_,_DOWN_BUTTON_PIN_,INPUT);
   SET_PIN_DIRECTION(_UP_BUTTON_DIRECTION_,_UP_BUTTON_PIN_,INPUT);
   SET_PIN_DIRECTION(_ON_OFF_BUTTON_DIRECTION_,_ON_OFF_BUTTON_PIN_,INPUT);
   SET_PIN_DIRECTION(_TEMPERATURE_SENSOR_DIRECTION_,_TEMPERATURE_SENSOR_PIN_,INPUT);
   SET_PIN_DIRECTION(_EEPROM_SCK_DIRECTION_,_EEPROM_SCK_PIN_,INPUT);
   SET_PIN_DIRECTION(_EEPROM_SDA_DIRECTION_,_EEPROM_SDA_PIN_,INPUT);
   SET_PORT_DIRECTION(_7SEGMENT_DIRECTION_,OUTPUT);
  
}



