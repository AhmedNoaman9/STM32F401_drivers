/*
 * LED_Cfg.c
 *
 *  Created on: Feb 23, 2023
 *      Author: NO3M4N
 */



#include "Std_Types.h"

#include "GPIO.h"

#include "LED.h"






const ledCfg_t	led_Cfgstr[LedCount] = {

		[ledTest]={

				.gpio.Mode = GPIO_MODE_GP_OUTPUT_PP,
				.gpio.Port	= GPIO_PORTB,
				.gpio.Pin	= GPIO_PIN2,
				.gpio.Speed = GPIO_SPEED_MEDIUM,

				.ActiveState = ACTIVE_HIGH

		}



};
