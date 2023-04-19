/*
 * NVIC_Prv.h
 *
 *  Created on: Mar 2, 2023
 *      Author: NO3M4N
 */

#ifndef NVIC_PRV_H_
#define NVIC_PRV_H_




/**************************************
*   NVIC REGISTRES
***************************************/
#define NVIC_BASE_ADDRESS                     	 		 0xE000E100
#define	NVIC_PRIORTY_BASE					             0xE000E400

/**************************************
*   SYSTEM CONTROL REGISTRES
***************************************/
#define SCB_BASE_ADDRESS                     	 0xE000ED00

#define AIRCR                                  *((volatile u32*)(SCB_BASE_ADDRESS+0x0C))

#define STIR                                 *((volatile u32*)(NVIC_BASE_ADDRESS+0xE00))




typedef	struct {
	volatile	u32	ISER[8];
	volatile	u32	ICER[8];
	volatile	u32	ISPR[8];
	volatile	u32	ICPR[8];
	volatile	u32	IAPR[8];
	volatile	u8 IPR[239];

}NVIC_t;



#define NVIC	((volatile NVIC_t * const) NVIC_BASE_ADDRESS)




#endif /* NVIC_PRV_H_ */
