#include "Std_Types.h"

#include "STK.h"
#include "Sched.h"
#include "Sched_Cfg.h"

/************DEFINES ***********/



/*************USER Def Types*********************/
typedef struct 
{
    /* data */
    TaskInfo_t  *TasksInfo_str;
    u32         RemainTimeMs;

}Task_t;



/**************Global variables***************************/
Task_t  Tasks[NUMBER_OF_TASKS];

volatile    u8 SchedFlag = 0 ;


/**********Functions*************/

static  void    TickCbf(void){

    if (SchedFlag == 0)
    {
        /* code */
        SchedFlag = 1;
    }
    else{
        // CPU Load = 100%
    }
    


}



void    Sched_Init(){

    u8 TaskIdx;

    for ( TaskIdx = 0; TaskIdx < NUMBER_OF_TASKS ; TaskIdx++)
    {      
        /* code */
        Tasks[TaskIdx].TasksInfo_str = &TasksInfo[TaskIdx];
        Tasks[TaskIdx].RemainTimeMs = TasksInfo[TaskIdx].startDelayMs;  

    }

    STK_vidInit();
    STK_setTickTimeMs(TICK_TIME_MS);
    STK_setCallback(TickCbf);

    
}

void    Scheduler(){
    u8 TaskIdx;

    for (TaskIdx = 0; TaskIdx < NUMBER_OF_TASKS; TaskIdx++)
    {
        if (Tasks[TaskIdx].TasksInfo_str)
        {
            if (Tasks[TaskIdx].RemainTimeMs == 0)
            {
                Tasks[TaskIdx].TasksInfo_str->Task();
                Tasks[TaskIdx].RemainTimeMs = Tasks[TaskIdx].TasksInfo_str->periodMs; 
                /* code */
            }
            else
            {
                Tasks[TaskIdx].RemainTimeMs -= TICK_TIME_MS;
                
            }


            /* code */
        }
        else{

            // Null Pointer error

        }
        
        /* code */
    }
    

}



void    Sched_Start(){

    STK_StartTimer();

    while (1)
    {
        if(SchedFlag){
            Scheduler();
            SchedFlag = 0;
        }
        /* code */
    }
    

}