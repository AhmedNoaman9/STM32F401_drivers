/*
 * RCC.h
 *
 *  Created on: Feb 1, 2023
 *      Author: NO3M4N
 */

#ifndef RCC_H_
#define RCC_H_


/***SECTION_1***************CLOCKTYPES**********************/

#define CLOCKTYPE_HSI		0x00000001
#define CLOCKEN_HSI_READY	0x00000002



#define CLOCKTYPE_HSE		0x00010000
#define CLOCKEN_HSE_READY	0x00020000

#define CLOCKTYPE_PLL		0x01000000
#define CLOCKEN_PLL_READY	0x02000000

#define CLOCKTYPE_PLLI2s		0x04000000
#define CLOCKEN_PLLI2S_READY	0x08000000

/***SECTION 2****************SYSCLK Select*****************************/


#define SYSCLK_SRC_HSI				0x00000000
#define SYSCLK_SRC_HSE				0x00000001
#define SYSCLK_SRC_PLL				0x00000002
#define SYSCLK_SRC_CLR				0x00000003

#define SYSCLK_CONF_ERR				0x00000003


#define ACTIVE_SYSCLK_HSI				0x00000000
#define ACTIVE_SYSCLK_HSE				0x00000004
#define ACTIVE_SYSCLK_PLL				0x00000008
#define CLK_SRC_ERR						0x0000000C


/***SECTION 3******************AHB PRESCALER*********************************/


#define AHB_PRESCALER_DIV_1			0x00000000
#define AHB_PRESCALER_DIV_2			0x00000080
#define AHB_PRESCALER_DIV_4			0x00000090
#define AHB_PRESCALER_DIV_8			0x000000A0
#define AHB_PRESCALER_DIV_16			0x000000B0
#define AHB_PRESCALER_DIV_64			0x000000C0
#define AHB_PRESCALER_DIV_128		0x000000D0
#define AHB_PRESCALER_DIV_256		0x000000E0
#define AHB_PRESCALER_DIV_512		0x000000F0


/********************************************/

#define APB1_PRESCALER_AHB_DIV1		0x00000000
#define APB1_PRESCALER_AHB_DIV2		0x00001000
#define APB1_PRESCALER_AHB_DIV4		0x00001400
#define APB1_PRESCALER_AHB_DIV8		0x00001800
#define APB1_PRESCALER_AHB_DIV16		0x00001C00
#define APB1_PRESCALER_AHB_CLR		0xFFFFE3FF

#define APB2_PRESCALER_AHB_DIV1		0x00000000
#define APB2_PRESCALER_AHB_DIV2		0x00008000
#define APB2_PRESCALER_AHB_DIV4		0x0000A000
#define APB2_PRESCALER_AHB_DIV8		0x0000C000
#define APB2_PRESCALER_AHB_DIV16		0x0000D000
#define APB2_PRESCALER_AHB_CLR		0xFFFF1FFF



/********************************************/
/*				RCC Peripherals				*/
/*				Clock EN/DIS				*/
/********************************************/

/*Buses definitions for Peripheral CLK Selection Enable*/
#define RCC_AHB1			1
#define RCC_AHB2			2
//#define RCC_AHB3			3
#define RCC_APB1			4
#define RCC_APB2 		5

/*	Section SS
 *
 * 	RCC Registers Bits / Peripherals IDs				*/

/*************************************************************************************************************************
 * Peripherals Enable Configurations
 ************************************************************************************************************************/

/* 			AHB1			*/
#define PERPHID_AHB1_GPIOA		0
#define PERPHID_AHB1_GPIOB		1
#define PERPHID_AHB1_GPIOC		2
#define PERPHID_AHB1_GPIOD		3
#define PERPHID_AHB1_GPIOE		4
//#definPERPHIDCC_AHB1_GPIOF		5
//#definPERPHIDCC_AHB1_GPIOG		6
#define PERPHID_AHB1_GPIOH		7
#define PERPHID_AHB1_CRC		12
//#definPERPHIDCC_AHB1_BKP		18
#define PERPHID_AHB1_DMA1		21
#define PERPHID_AHB1_DMA2		22
//#defin RCC_AHB1_OTGHS		29
//#defin RCC_AHB1_OTGHSULPI	30


/* 			AHB2			*/

//#definCC_AHB2_DCMI		0
#define PERPHID_AHB2_OTGHFS		7



/* 			APB1			*/

#define PERPHID_APB1_TIM2		0
#define PERPHID_APB1_TIM3		1
#define PERPHID_APB1_TIM4		2
#define PERPHID_APB1_TIM5		3
////////PERPHID////////////////////
#define PERPHID_APB1_WWDG		11
#define PERPHID_APB1_SPI2		14
#define PERPHID_APB1_SPI3		15
#define PERPHID_APB1_SPDIFRX	16
#define PERPHID_APB1_USART2		17
#define PERPHID_APB1_I2C1		21
#define PERPHID_APB1_I2C2		22
#define PERPHID_APB1_I2C3		23
#define PERPHID_APB1_PWR		28


/* 			APB2 			*/

#define PERPHID_APB2_TIM1		0

#define PERPHID_APB2_USART1		4
#define PERPHID_APB2_USART6		5
#define PERPHID_APB2_ADC1		8

#define PERPHID_APB2_SDIO		11
#define PERPHID_APB2_SPI1		12
#define PERPHID_APB2_SPI4		13
#define PERPHID_APB2_SYSCFG		14
#define PERPHID_APB2_TIM9		16
#define PERPHID_APB2_TIM10		17
#define PERPHID_APB2_TIM11		18



#define PLL_SRC_HSE	0xFF4FFFFF
#define PLL_SRC_HSI	0xFFBFFFFF



#define PLLN_MAX		0x00007FC0
#define PLLP_2			0
#define PLLP_4			0
#define PLLP_6			0
#define PLLP_8			0
#define PLL_CFGR_CLR	0xF0FC7FFF



/*
#define HSE	0
#define HSI	1
#define PLL	2
#define	PLL_I2S	5
#define LSI	3
#define LSE	4

*/

typedef enum {
	RCC_OK,
	RCC_NOK,
	RCC_TIMEOUT,
	RCC_WRONGCONF



}RCC_enuErrorStatus_t;






/*************************************************
 * RCC INITIALIZATION function
 *
 * INPUT: Void
 *
 * OUTPUT: RCC_enuErrorStatus_t (typedef enum)
 *
 ****************************************************/
RCC_enuErrorStatus_t RCC_enuInit(void);



/*************************************************
 * RCC Clock Enable function to enable a certain clock
 *
 * INPUT: u8 ClockType	Check Macros section 1
 *
 * OUTPUT: RCC_enuErrorStatus_t (typedef enum)
 *
 ****************************************************/
RCC_enuErrorStatus_t RCC_EnableClk(u32 ClockType);



/*************************************************
 * RCC Clock Disable function to disable a certain clock
 *
 * INPUT: u8 ClockType	Check Macros section 1
 *
 * OUTPUT: RCC_enuErrorStatus_t (typedef enum)
 *
 ****************************************************/
RCC_enuErrorStatus_t RCC_DisableClk(u32 ClockType);




/*************************************************
 * RCC System Clock Select function
 *
 * INPUT: u8 SysClk	Check Macros section 2
 *
 * OUTPUT: RCC_enuErrorStatus_t (typedef enum)
 *
 ****************************************************/
RCC_enuErrorStatus_t RCC_SelectSysClk(u32 SysClk);






RCC_enuErrorStatus_t RCC_SetAHBPrescaler(u32 AHB_Prescaler);


RCC_enuErrorStatus_t RCC_SetAPB1Prescaler(u32 APB1_Prescaler);

RCC_enuErrorStatus_t RCC_SetAPB2Prescaler(u32 APB2_Prescaler);


/**********************************************************/


RCC_enuErrorStatus_t RCC_SelectPLLSource(u8 PLL_SRC );

RCC_enuErrorStatus_t RCC_ConfigurePLL(u8 PLL_SRC, u8 PLLP_Macro , u16 PLLN, u8 PLLM, u8 PLLQ );









/*************************************************
 * RCC Peripheral Clock Enable/Disable functions
 *
 * INPUT: u8 BusID , u8 Peripheral ID(See Section SS)
 *
 * OUTPUT: RCC_enuErrorStatus_t (typedef enum)
 *
 ****************************************************/

RCC_enuErrorStatus_t RCC_enuEnablePerphClk(u8 Copy_u8RCC_Bus, u8 Copy_u8PerID);

RCC_enuErrorStatus_t RCC_enuDisablePerphClk(u8 Copy_u8RCC_Bus, u8 Copy_u8PerID);











#endif /* RCC_H_ */
