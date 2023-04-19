/*
 * GPIO.c
 *
 *  Created on: Feb 14, 2023
 *      Author: NO3M4N
 */

#include "Bit_Math.h"
#include "Std_Types.h"

#include "GPIO.h"


/*********************#DEFINES**********************************/


#define GPIOA_BASE_ADDR ( (GPIO_t*) 0x40020000 )
#define GPIOB_BASE_ADDR ( (GPIO_t*) 0x40020400 )
#define GPIOC_BASE_ADDR ( (GPIO_t*) 0x40020800 )
#define GPIOE_BASE_ADDR ( (GPIO_t*) 0x40020C00 )
#define GPIOD_BASE_ADDR ( (GPIO_t*) 0x40021000 )
#define GPIOH_BASE_ADDR ( (GPIO_t*) 0x40021C00 )









GPIO_t* GPIO[MAX_GPIO_NUM]={

		GPIOA_BASE_ADDR,
		GPIOB_BASE_ADDR,
		GPIOC_BASE_ADDR,
		GPIOD_BASE_ADDR,
		GPIOE_BASE_ADDR,
		GPIOH_BASE_ADDR
};







/****
 *	GPIO Pin Init to initialize invidiual pins using CFG Struct
 *
 *	Input : & gpioCfg_t
 *
 *	Output : TBD
 *
 */

void	gpio_initPin(gpioCfg_t * CfgStr){

		/* Options are 7-bit numbers defined in the GPIO.h
		 * bits [5,6]: for pin mode (either I/P or O/P or AF)
		 * bit   [4] : for output type (either PP or OD)
		 * bits [2,3]: for pin output speed
		 * bits [0,1]: for pull up and pull down
		 */

	u8 Loc_u8Mode 	= 	(CfgStr->Mode >> 5);
	u8 Loc_u8Type 	= 	( (CfgStr->Mode >> 4) & 1);
	u8 Loc_u8Speed	=	(CfgStr->Speed);
	u8 Loc_u8Port	= 	CfgStr->Port;
	u8 Loc_u8Pin	= 	CfgStr->Pin;
	u8 Loc_u8Pull	= 	CfgStr->Mode & 0b11;


	/** OMODER for setting pin MODE **/
	if(	Loc_u8Mode <= 3 ){
		u32	Loc_Register ;
		Loc_Register = GPIO[Loc_u8Port]->MODER;

		Loc_Register &= ~(TWO_BIT_CLR << (Loc_u8Pin*2) );
		Loc_Register |= (Loc_u8Mode << (Loc_u8Pin*2) );

		GPIO[Loc_u8Port]->MODER = Loc_Register;

	}
	else{
		// Error Wrong Conf
	}

	if(Loc_u8Mode == 1 ) // if mode is OUTPUT
	{
		/**	OTYPER for choosing Output Type	**/
		if(Loc_u8Type <= 1){
			u32 Loc_Register =	GPIO[Loc_u8Port]->OTYPER;

			Loc_Register &= (Loc_u8Type << Loc_u8Pin);

			GPIO[Loc_u8Port]->OTYPER = Loc_Register;
		}
		else{
			// Error
		}
		/*	OSPEED to Choose Output Speed	*/
		if(Loc_u8Speed <= GPIO_SPEED_VERYHIGH){
			u32 Loc_Register =	GPIO[Loc_u8Port]->OSPEEDR;

			Loc_Register &= ~(TWO_BIT_CLR << (Loc_u8Pin*2));
			Loc_Register |=  (Loc_u8Speed << (Loc_u8Pin*2));

			GPIO[Loc_u8Port]->OSPEEDR= Loc_Register;
		}
		else{
			// Error
		}
	}//////////////////////OUTPUT CONFIGURATIONS


	/**	PUPDR to Choose Pull Resistance mode	**/

	if(	Loc_u8Pull <= 2 ){
			u32	Loc_Register ;
			Loc_Register = GPIO[Loc_u8Port]->PUPDR;

			Loc_Register &= ~(TWO_BIT_CLR << (Loc_u8Pin*2) );
			Loc_Register |= (Loc_u8Pull << (Loc_u8Pin*2) );

			GPIO[Loc_u8Port]->PUPDR = Loc_Register;

		}
		else{
			// Error Wrong Conf
		}



}


void	gpio_writePinValue( u8 GPIO_PORT, u8 GPIO_PIN, u8 GPIO_STATE ){


	if(GPIO_PORT <= GPIO_PORTH && GPIO_PIN <= GPIO_PIN15 ){

		if(GPIO_STATE == GPIO_LOW ){

			GPIO[GPIO_PORT]->BSRR &=~ (1 << GPIO_PIN);
			GPIO_PIN += 16;

		}
		GPIO[GPIO_PORT]->BSRR |= (1 << GPIO_PIN);

	}
	else {
		//error Wrong Argument
	}
}



void	gpio_setAFIO( u8 GPIO_PORT, u8 GPIO_PIN, u8 AFIO_NUMBER ){
	u32 Loc_u32Register;

	if (GPIO_PIN <= LOW_REGISTER_MAX){

		Loc_u32Register = GPIO[GPIO_PORT]->AFRL;

		Loc_u32Register &= ~(FOUR_BIT_CLR << (GPIO_PIN * 4) );
		Loc_u32Register |= 	(AFIO_NUMBER << (GPIO_PIN * 4) );

		GPIO[GPIO_PORT]->AFRL = Loc_u32Register;

	}
	else if ( GPIO_PIN <= MAX_GPIO_NUM) {


		Loc_u32Register = GPIO[GPIO_PORT]->AFRH;

		Loc_u32Register &= ~(FOUR_BIT_CLR << ( (GPIO_PIN - 8)* 4) );
		Loc_u32Register |= 	(AFIO_NUMBER << ( (GPIO_PIN - 8) * 4) );

		GPIO[GPIO_PORT]->AFRH = Loc_u32Register;


	}
	else{
		// Error Wrong Pin
	}




}





