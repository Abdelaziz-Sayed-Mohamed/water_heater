/*
 * File:   main.c
 * Author: Abdelaziz Sayed
 *
 * Created on July 6, 2020, 8:17 PM
 */
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 8000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include "Config.h"
#include "gpio/gpio.h"
#include "ADC/ADC.h"
#include"Scheduler/Scheduler.h"
#include "Timer/Timer.h"
#include"Display/Display.h"
#include"Elements/Elements.h"
#include"Buttons/Buttons.h"
#include"Temperature/Temperature.h"
#include"WaterHeater_Mode/WaterHeater_Mode.h"
#include"Average/Average.h"
#include"Interrupt/Interrupt.h"
#include"EEPROM/EEPROM.h"



void main(void) {
  
  GPIO_Init();
  ADC_Init();
  On_Off_Init();
  Display_Init();
  Elements_Init();
  Mode_Init();
  Get_EEPROM_Data();
  ADC_Start_Conv();
  Scheduler_Init();
  Timer0_Init(); 
  Scheduler_Start();    
 
}
