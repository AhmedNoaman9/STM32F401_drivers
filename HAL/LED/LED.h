/*
 * LED.h
 *
 *  Created on: Feb 23, 2023
 *      Author: NO3M4N
 */


#ifndef LED_H_
#define LED_H_


#include "LED_Cfg.h"


#define ACTIVE_HIGH	0
#define ACTIVE_LOW	1


#define LED_ON	1
#define LED_OFF	0




/**************TYPEDEFS ********************/
typedef struct {

	gpioCfg_t gpio;

	u8 ActiveState;



}ledCfg_t;



/*************PROTOTYPES*************************/

void 	led_init(void);


void	led_setState(Leds_t	Led, u8 State);



#endif /* LED_H_ */
