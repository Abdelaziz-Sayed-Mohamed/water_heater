/*
 * File:   main.c
 * Author: Abdelaziz Sayed
 *
 * Created on July 6, 2020, 8:17 PM
 */
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include "Config.h"
#include "gpio/gpio.h"
#include "ADC/ADC.h"
#include"Scheduler/Scheduler.h"
#include "Timer/Timer.h"
#include"SSD/SSD.h"
#include"Elements/Elements.h"
#include"Buttons/Buttons.h"
#include"Temperature/Temperature.h"
#include"WaterHeater_Mode/WaterHeater_Mode.h"
#include"Average/Average.h"
#include"Interrupt/Interrupt.h"
#include"EEPROM/EEPROM.h"

void main(void) {
  
  GPIO_Init();
  I2c_Init();
  ADC_Init();
  On_Off_Init();
  SSD_Init();
  Elements_Init();
  Mode_Init();
  Get_EEPROM_Data();
  ADC_Start_Conv();
  Scheduler_Init();
  Timer0_Init(); 
  Scheduler_Start();    
 
}
