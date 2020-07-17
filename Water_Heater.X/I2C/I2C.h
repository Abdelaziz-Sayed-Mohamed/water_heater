/* 
 * File:   I2C.h
 * Author: Abdalaziz Sayed
 *
 * Created on July 17, 2020, 3:20 AM
 */
#ifndef I2C_H
#define	I2C_H
#include"../Config.h"

#define I2c_Clock   100000 //100khz

void I2c_Init(void);
void I2c_Start(void);
void I2c_Stop(void);
void I2c_WaitAck(void);
void I2c_Write(uint8_t data);
uint8_t I2c_Read(void);
void I2c_Send_NAck(void);

#endif	/* I2C_H */

