
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
#define IS_EEPROM_ERASED         EEPROM_Data==0xff
#define IS_Value_Vaild          ((EEPROM_Data%5)==0)
#define IS_Store_Set_Temp_Ready   Temperature.Store_Set_Temp_Flag==1
#define Start_EEPROM_Connection   while( e2pext_r(0))
void Get_EEPROM_Data(void);
void Set_EEPROM_Data(void);
unsigned char e2pext_r(unsigned int addr);

#endif /* EEPROM_H_ */
