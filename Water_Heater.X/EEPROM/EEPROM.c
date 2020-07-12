/* ########################################################################

   PICsim - PIC simulator http://sourceforge.net/projects/picsim/

   ########################################################################

   Copyright (c) : 2015  Luis Claudio Gambôa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

#include "../I2C/I2C.h"
#include"EEPROM.h"
#include"../WaterHeater_Mode/WaterHeater_Mode_Cfg.h"
#include"../Temperature/Temperature.h"

uint8_t EEPROM_Data=0;

void Get_EEPROM_Data(void)
{
    
 Start_EEPROM_Connection;   
 EEPROM_Data=e2pext_r(EEPROM_DATA_ADDR);
 uint8_t Flag=(EEPROM_Data>>7)&1;
 uint8_t Temp=(EEPROM_Data)&~(1<<7);

 if(IS_Flag_Was_Seted && ((Temp<=MAX_SET_TEMP)||(Temp>=MIN_SET_TEMP)))
 {
   Temperature.Set_Temp=Temp; 
 }
 else
 {
    Temperature.Set_Temp=DEFAULT_SET_TEMP;
 }    

}


void Set_EEPROM_Data(void)
{
static unsigned char ah;
static unsigned char al;
static unsigned char nt;
#ifdef EEPROM

if(IS_Store_Set_Temp_Ready)
{       
     EEPROM_Data=Temperature.Set_Temp|(1<<7);
   
     ah=(EEPROM_DATA_ADDR&0x0100)>>8;
     al=EEPROM_DATA_ADDR&0x00FF;
     nt=0;
   
     do
     {
       i2c_start();
       if(ah)
       { 
         i2c_wb(0xA2);
       }
       else
       {
         i2c_wb(0xA0);
       }
       i2c_wb(al);
       i2c_wb(EEPROM_Data);
       i2c_stop();
   
       nt++;
     }
     while((EEPROM_Data != e2pext_r(EEPROM_DATA_ADDR))&&(nt < 10));
}     
#endif
}

unsigned char e2pext_r(unsigned int addr)
{
  unsigned char ret;
  unsigned char ah;
  unsigned char al;

  ah=(addr&0x0100)>>8;
  al=addr&0x00FF;

  i2c_start();	
  if(ah)
  {
    i2c_wb(0xA2);
  }
  else
  {
    i2c_wb(0xA0);
  }
  i2c_wb(al);

  i2c_start();
  if(ah)
  {
    i2c_wb(0xA3);
  }
  else
  {
    i2c_wb(0xA1);
  }
  ret=i2c_rb(1);
  i2c_stop();

  return ret;	
}


void e2pext_w(unsigned int addr, unsigned char val)
{
  unsigned int tmp;
  unsigned char ah;
  unsigned char al;
  unsigned char nt;

  tmp=val;
  ah=(addr&0x0100)>>8;
  al=addr&0x00FF;
  nt=0;

  do
  {
    i2c_start();
    if(ah)
    { 
      i2c_wb(0xA2);
    }
    else
    {
      i2c_wb(0xA0);
    }
    i2c_wb(al);
    i2c_wb(tmp);
    i2c_stop();

    nt++;
  }
  while((tmp != e2pext_r(addr))&&(nt < 10));
}
