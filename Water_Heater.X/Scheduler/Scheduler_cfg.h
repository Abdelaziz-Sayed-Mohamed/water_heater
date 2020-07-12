#ifndef _SCHEDULER_cfg
#define _SCHEDULER_cfg

/* Includes ------------------------------------------------------------------*/

#include "Tasks.h"
#include "string.h"
#include "stdint.h"
#include"../Config.h"

#define NumberOfTasks		        ( 3u )
#define SystemTickPeriodms			(1UL)		/*in Hz*/

typedef struct{
  void (* fuction_ptr   )(void)  ;
  uint32_t Peroid ;
}Scheduler_Intity_t ;


extern uint8_t Scheduler_ActivationFlags[NumberOfTasks] ;
extern const Scheduler_Intity_t Scheduler_Intitys[NumberOfTasks];

#endif /*_SCHEDULER_*/
