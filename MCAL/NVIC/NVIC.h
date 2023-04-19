/*
 * NVIC.h
 *
 *  Created on: Mar 2, 2023
 *      Author: NO3M4N
 */

#ifndef NVIC_H_
#define NVIC_H_


#define NVIC_PRIORITY_GROUPING_CLR 				   	   0xFFFFF8FF
#define NVIC_PRIORITY_GROUPING_XXXX 				   0x05FA0000
#define NVIC_PRIORITY_GROUPING_XXXY 				   0x05FA0400
#define	NVIC_PRIORITY_GROUPING_XXYY 				   0x05FA0500
#define	NVIC_PRIORITY_GROUPING_XYYY 				   0x05FA0600
#define	NVIC_PRIORITY_GROUPING_YYYY 				   0x05FA0700


typedef	enum{
	// External Interrupts
	    WWDG ,                   // Window WatchDog
	    PVD ,                    // PVD through EXTI Line detection
	    TAMP_STAMP ,             // Tamper and TimeStamps through the EXTI line
	    RTC_WKUP ,               // RTC Wakeup through the EXTI line
	    FLASH ,                  // FLASH
	    RCC ,                    // RCC
	    EXTI0 ,                  // EXTI Line0
	    EXTI1 ,                  // EXTI Line1
	    EXTI2 ,                  // EXTI Line2
	    EXTI3 ,                  // EXTI Line3
	    EXTI4 ,                  // EXTI Line4
	    DMA1_Stream0 ,           // DMA1 Stream 0
	    DMA1_Stream1 ,           // DMA1 Stream 1
	    DMA1_Stream2 ,           // DMA1 Stream 2
	    DMA1_Stream3 ,           // DMA1 Stream 3
	    DMA1_Stream4 ,           // DMA1 Stream 4
	    DMA1_Stream5 ,           // DMA1 Stream 5
	    DMA1_Stream6 ,           // DMA1 Stream 6
	    ADC ,                    // ADC1, ADC2 and ADC3s

	        /*
	         * Reserved
	         *
	         * */

	    EXTI9_5  = 24,                // External Line[9:5]s
	    TIM1_BRK_TIM9 ,          // TIM1 Break and TIM9
	    TIM1_UP_TIM10 ,          // TIM1 Update and TIM10
	    TIM1_TRG_COM_TIM11 ,     // TIM1 Trigger and Commutation and TIM11
	    TIM1_CC ,                // TIM1 Capture Compare
	    TIM2 ,                   // TIM2
	    TIM3 ,                   // TIM3
	    TIM4 ,                   // TIM4
	    I2C1_EV ,                // I2C1 Event
	    I2C1_ER ,                // I2C1 Error
	    I2C2_EV ,                // I2C2 Event
	    I2C2_ER ,                // I2C2 Error
	    SPI1 ,                   // SPI1
	    SPI2 ,                   // SPI2
	    USART1 ,                 // USART1
	    USART2 ,                 // USART2
		// Reserved
	    EXTI15_10  = 41,              // External Line[15:10]s
	    RTC_Alarm ,              // RTC Alarm (A and B) through EXTI Line
	    OTG_FS_WKUP ,            // USB OTG FS Wakeup through EXTI line
	                                 // Reserved
	    DMA1_Stream7  = 48,           // DMA1 Stream7
		// Reserved
	    SDIO  = 50,                   // SDIO
	    TIM5 ,                   // TIM5
	    SPI3 ,                   // SPI3
	                               // Reserved
	    DMA2_Stream0  = 57,           // DMA2 Stream 0
	    DMA2_Stream1 ,           // DMA2 Stream 1
	    DMA2_Stream2 ,           // DMA2 Stream 2
	    DMA2_Stream3 ,           // DMA2 Stream 3
	    DMA2_Stream4 ,           // DMA2 Stream 4
	 // Reserved
	    OTG_FS  = 68,                 // USB OTG FS
	    DMA2_Stream5 ,           // DMA2 Stream 5
	    DMA2_Stream6 ,           // DMA2 Stream 6
	    DMA2_Stream7 ,           // DMA2 Stream 7
	    USART6 ,                 // USART6
	    I2C3_EV ,                // I2C3 event
	    I2C3_ER ,                // I2C3 error
	                                 // Reserved
	    FPU  =	82,                    // FPU
                           // Reserved
	    SPI4  =85,                   // SPI4
		NumberOfIRQs
	}IRQn_t;

//
//	typedef struct{
//		IRQn_t	Interupt_Number;
//		u8				Group_Priority;
//		u8				SubGroup_Priority;
//	}NVIC_Cfg_t;
//


//extern const NVIC_Cfg_t NVIC_Cfg[NVIC_ACTIVATED_INT_SIZE];

	/****************************************************************************
	* \Syntax : void IntCtrl_Init(void)
	* \Description: Initilze NVIC/SCB Module
	*
	* \Sync\Async: Sync
	* \Reentrancy: none
	* \Parameters (in): none
	* \Parameters (out): none
	* \Return Value:    none
	*
	******************************************************************************/
	void NVIC_Init(void);





/**
 *
 * Enables / Disables an interrupt or exception.
 *
 *
 */

void	NVIC_EnableIRQ(IRQn_t	IRQn);

void	NVIC_DisableIRQ(IRQn_t	IRQn);



void NVIC_SetPendingIRQ(IRQn_t IRQn);


void NVIC_ClearPendingIRQ(IRQn_t IRQn);



u32 NVIC_GetPendingIRQ(IRQn_t IRQn);

void NVIC_SetPriority(IRQn_t IRQn, u32 priority);

u32 NVIC_GetPriority(IRQn_t IRQn);


u32 NVIC_GetActive (IRQn_t IRQn);

void NVIC_SetPriorityGrouping(u32 priority_grouping);


void NVIC_triggerSWInterrupt(IRQn_t IRQn);


#endif /* NVIC_H_ */
