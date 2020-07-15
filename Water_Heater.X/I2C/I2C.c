#include "I2C.h"
#include"../gpio/gpio.h"

void delay(void)
{
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
  asm("NOP");
   
}


void I2c_Start(void)
{
       
  SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
  RESET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
}

void I2c_Stop(void)
{
  SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  RESET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
  SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
}

void I2c_Write(unsigned char val)
{
  unsigned char i;
  RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  for(i=0;i<8;i++)
  {
    PORTCbits.RC4=((val>>(7-i))& 0x01);
    SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
    delay();
    RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  }	
  SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
  SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  delay();
  RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
}

unsigned char I2c_Read(unsigned char ack)
{
  char i;
  unsigned char ret=0;

  RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  SET_PIN_DIRECTION(EEPROM_SDA_DIRECTION,EEPROM_SDA_PIN,INPUT);
  SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  for(i=0;i<8;i++)
  {
    SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
    delay();
    ret|=(PORTCbits.RC4<<(7-i));
    RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  }
  SET_PIN_DIRECTION(EEPROM_SDA_DIRECTION,EEPROM_SDA_PIN,OUTPUT) ; 
  if(ack)
    RESET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  else
	SET_PIN(EEPROM_SDA_PORT,EEPROM_SDA_PIN);
  delay();
  SET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);
  delay();
  RESET_PIN(EEPROM_SCK_PORT,EEPROM_SCK_PIN);

  return ret;
}




