/*
 * Scheduler_cfg.h
 *
 *  Created on: Jul 8, 2020
 *      Author: Abdelaziz Sayed
 */

#ifndef _SCHEDULER_cfg
#define _SCHEDULER_cfg

/* Includes ------------------------------------------------------------------*/

#include "Tasks.h"
#include "string.h"
#include "stdint.h"
#include"../Config.h"

#define NumberOfTasks		        ( 3U )
#define SystemTickPeriodms			(20UL)		/*in Ms*/

typedef struct{
  void (* fuction_ptr   )(void)  ;
  uint32_t Peroid ;
}Scheduler_Intity_t ;


extern uint8_t Scheduler_ActivationFlags[NumberOfTasks] ;
extern const Scheduler_Intity_t Scheduler_Intitys[NumberOfTasks];

#endif /*_SCHEDULER_*/
