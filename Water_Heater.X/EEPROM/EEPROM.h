
/*
 * WaterHeater_Mode_Cfg.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include"../Config.h"

#define EEPROM                     STD_ON

#define ERASED                       0xff
#define EEPROM_DATA_ADDR             0xa
#define EEPROM_24c04_ADDR            0xa0

#define IS_Value_Vaild          ((EEPROM_Data%5)==0)
#define IS_Store_Set_Temp_Ready   Temperature.Store_Set_Temp_Flag==1
#define Reset_Store_Set_Temp_Flag Temperature.Store_Set_Temp_Flag=0
#define Start_EEPROM_Connection   while( EEPROM_Read(0))


void Get_EEPROM_Data(void);
void Set_EEPROM_Data(void);
void EEPROM_Write(uint8_t Data);
uint8_t EEPROM_Read(uint8_t addr);

#endif /* EEPROM_H_ */
