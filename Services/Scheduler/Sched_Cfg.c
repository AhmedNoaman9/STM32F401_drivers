#include "Std_Types.h"

#include "Sched.h"
#include "Sched_Cfg.h"

#include "GPIO.h"

u8 state1 = 0;
u8 state2 = 0;
u8 state3 = 0;



void	task1(void){
	
 
	gpio_writePinValue(GPIO_PORTC,GPIO_PIN13, state1^=1);
	//led_setState(ledTest, state^1);


}

void	task2(void){
	
 
	gpio_writePinValue(GPIO_PORTC,GPIO_PIN14, state2 ^=1 );
	//led_setState(ledTest, state^1);


}


void	task3(void){
	
    
	gpio_writePinValue(GPIO_PORTC,GPIO_PIN15, state3 ^=1 );
	//led_setState(ledTest, state^1);


}




const TaskInfo_t TasksInfo[NUMBER_OF_TASKS] = {
	
	[0] = {

        .periodMs           = 50,
        .startDelayMs       = 5,
        .Task               = task1

	},
	[1] = {
        
        .periodMs           = 100,
        .startDelayMs       = 5,
        .Task               = task2

	},
    [2] = {
        
        .periodMs           = 500,
        .startDelayMs       = 5,
        .Task               = task3

	},

    
	
	
};