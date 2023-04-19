/*
 * STK_interface.h
 *
 *  Created on: Oct 25, 2021
 *      Author: Omar el Masry
 */

#ifndef STK_H_
#define STK_H_


#define   CLOCK_FREQUENCY 25000000


typedef void (*systickCbf_t)(void);




void STK_vidInit(void);

void STK_StartTimer();
void STK_StopTimer();

void STK_EnableInterrupt();
void STK_DisableInterrupt();

void STK_SetInterval_Single(u32 ticks,void(*fptr)());
void STK_SetInterval_Periodic(u32 ticks);
void STK_SetBusyWait(u32 ticks);

u32 STK_GetRamainingTime(void);
u32 STK_GetElapsedTime(void);


void  STK_setTickTimeMs(u32 TickMs);

void  STK_setCallback(systickCbf_t  Cbf);

extern void
  SysTick_Handler (void);





#endif /* STK_INTERFACE_H_ */
