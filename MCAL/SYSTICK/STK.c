/*
 * STK_program.c
 *
 *  Created on: Oct 25, 2021
 *      Author: Omar el Masry
 */
#include "BIT_Math.h"
#include "Std_Types.h"

#include "STK.h"
#include "STK_private.h"
#include "STK_config.h"

#define MAX_TICKS	0x00FFFFFF


static void (*Global_STK_Callback)(void);

volatile u8 single_flag=0;

void STK_vidInit(void)
{

#if 	STK_CLK_SOURCE	==	AHB_DIV_8
			CLR_BIT((STK->CTRL),CLKSOURCE);

#elif	STK_CLK_SOURCE	==	AHB
			SET_BIT((STK->CTRL),CLKSOURCE);
#endif


#if 	ENABLE_Interrupt	==	ENABLE
			SET_BIT((STK->CTRL),TICKINT);

#elif	ENABLE_Interrupt	==	DISABLE
			CLR_BIT((STK->CTRL),TICKINT);
#endif

}

void STK_StartTimer()
{
	SET_BIT((STK->CTRL),ENABLEB);

}
void STK_StopTimer()
{
	STK->VAL	&=0;
	STK->LOAD	&=0;
	CLR_BIT((STK->CTRL),ENABLEB);
}

void STK_EnableInterrupt()
{
	SET_BIT((STK->CTRL),TICKINT);
}
void STK_DisableInterrupt()
{
	CLR_BIT((STK->CTRL),TICKINT);
}


void STK_SetInterval_Single(u32 ticks,void(*fptr)())
{
	if(ticks	< MAX_TICKS )
	{
		single_flag=1;
		// 1- load ticks
		STK->LOAD=ticks;
		//2-set callback
		Global_STK_Callback=fptr;
		//3-start timer
		STK_StartTimer();
	}

}
void STK_SetInterval_Periodic(u32 ticks)
{
	if(ticks	< MAX_TICKS )
	{
		// 1- load ticks
		STK->LOAD=ticks;
		//2-set callback
		//Global_STK_Callback=fptr;
		//3-start timer
		STK_StartTimer();
	}
}

void STK_SetBusyWait(u32 ticks)
{
	volatile u32 data=0;
	STK->LOAD=ticks;
	STK_StartTimer();
	data=GET_BIT(STK->CTRL,COUNTFLAG);
	while(!data) {
		data=GET_BIT(STK->CTRL,COUNTFLAG);
	}
	STK_StopTimer();

}

u32 mSTK_GetRamainingTime(void)
{
	return (STK->VAL);
}

u32 STK_GetElapsedTime(void)
{
	return ((STK->LOAD)-(STK->VAL));
}

void	STK_setCallback(systickCbf_t	Cbf){

	if (Cbf)
	{
		Global_STK_Callback = Cbf;
		/* code */
	}
	else{
		// Error
	}
	
}

void  STK_setTickTimeMs(u32 TickMs ){

	

	TickMs = (CLOCK_FREQUENCY/STK_CLK_SOURCE) * TickMs;
	TickMs /= 1000;
	TickMs -= 1;
	/*check the value entered*/
	if (TickMs > MAX_TICKS)
	{
		//	Error
	}/*end of if --> checking value*/
	/*delete value in the register*/
	else {

		STK->LOAD &= 0;

		/*Store the value in the register*/
		STK->LOAD= TickMs;
	}

}



void SysTick_Handler(void)
{

	if(Global_STK_Callback){
		Global_STK_Callback();
		if(single_flag==1)
		{
			single_flag=0;
			STK_StopTimer();
		}
	}
}


