/*
 * LED.c
 *
 *  Created on: Feb 23, 2023
 *      Author: NO3M4N
 */



#include "Std_Types.h"

#include "GPIO.h"

#include "LED.h"


extern const ledCfg_t	led_Cfgstr[LedCount];


void	led_init(){

		gpioCfg_t	gpioCfg;
		u8	Loc_u8Index;


		for(Loc_u8Index = 0 ; Loc_u8Index < LedCount; Loc_u8Index++){

			gpioCfg.Mode 	= GPIO_MODE_GP_OUTPUT_PP;
			gpioCfg.Pin 	= led_Cfgstr[Loc_u8Index].gpio.Pin;
			gpioCfg.Port 	= led_Cfgstr[Loc_u8Index].gpio.Port;
			gpioCfg.Speed 	= led_Cfgstr[Loc_u8Index].gpio.Speed;

			gpio_initPin(&gpioCfg);

		}

}

void	led_setState(Leds_t	Led, u8 State){


	gpio_writePinValue(led_Cfgstr[Led].gpio.Port, led_Cfgstr[Led].gpio.Pin, (led_Cfgstr[Led].ActiveState^State ) );


}


