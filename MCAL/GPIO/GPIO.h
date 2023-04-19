/*
 * GPIO.h
 *
 *  Created on: Feb 14, 2023
 *      Author: NO3M4N
 */

#ifndef GPIO_H_
#define GPIO_H_

/*********************#DEFINES************************************/

#define GPIO_PORTA	0
#define GPIO_PORTB	1
#define GPIO_PORTC	2
#define GPIO_PORTD	3
#define GPIO_PORTE	4
#define GPIO_PORTH	5



#define GPIO_PIN0	    0
#define GPIO_PIN1	    1
#define GPIO_PIN2	    2
#define GPIO_PIN3	    3
#define GPIO_PIN4	    4
#define GPIO_PIN5	    5
#define GPIO_PIN6	    6
#define GPIO_PIN7	    7
#define GPIO_PIN8	    8
#define GPIO_PIN9	    9
#define GPIO_PIN10	    10
#define GPIO_PIN11	    11
#define GPIO_PIN12	    12
#define GPIO_PIN13	    13
#define GPIO_PIN14	    14
#define GPIO_PIN15	    15


#define MAX_GPIO_NUM		15
#define LOW_REGISTER_MAX	7



#define GPIO_MODE_GP_OUTPUT_PP		0b0100000
#define GPIO_MODE_GP_OUTPUT_PP_PU	0b0100001
#define GPIO_MODE_GP_OUTPUT_PP_PD	0b0100010

#define GPIO_MODE_GP_OUTPUT_OD		0b0110000
#define GPIO_MODE_GP_OUTPUT_OD_PU	0b0110001
#define GPIO_MODE_GP_OUTPUT_OD_PD	0b0110010


#define GPIO_MODE_INPUT_FLOATING	0b0000000
#define GPIO_MODE_INPUT_PULLUP		0b0000001
#define GPIO_MODE_INPUT_PULLDOWN	0b0000010
#define GPIO_MODE_ANALOG			0b1100000


#define GPIO_MODE_AFIO_PP		    0b1000000
#define GPIO_MODE_AFIO_PP_PU	    0b1000001
#define GPIO_MODE_AFIO_PP_PD	    0b1000010
#define GPIO_MODE_AFIO_OD		    0b1010000
#define GPIO_MODE_AFIO_OD_PU	    0b1010001
#define GPIO_MODE_AFIO_OD_PD	    0b1010010





#define GPIO_SPEED_LOW				0b00
#define GPIO_SPEED_MEDIUM			0b01
#define GPIO_SPEED_HIGH				0b10
#define GPIO_SPEED_VERYHIGH			0b11


#define  GPIO_HIGH			1
#define  GPIO_LOW			0




typedef struct {

	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;

}GPIO_t;


typedef struct	{

	u8	Port;
	u8	Pin;
	u8	Speed;
	u8 	Mode;


}gpioCfg_t;




/*************************PROTOTYPES************************************/



/****
 *	GPIO Pin Init to initialize invidiual pins using CFG Struct
 *
 *	Input : & gpioCfg_t
 *
 *	Output : TBD
 *
 */

void	gpio_initPin(gpioCfg_t * CfgStr);


/****
 *	GPIO Write pin value to set/clear pins
 *
 *	Input : u32 Port u32 pin u32 State
 *
 *	Output : TBD
 *
 */

void	gpio_writePinValue( u8 GPIO_PORT, u8 GPIO_PIN, u8 GPIO_STATE );


/****
 *	GPIO Write pin value to set/clear pins
 *SS
 *	Input : u32 Port u32 pin u32 State
 *
 *	Output : TBD
 *
 */

void	gpio_setAFIO( u8 GPIO_PORT, u8 GPIO_PIN, u8 AFIO_NUMBER );








#endif /* GPIO_H_ */
