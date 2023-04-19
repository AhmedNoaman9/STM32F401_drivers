#ifndef SCHED_H_
#define SCHED_H_





typedef void(*SchedCbf)(void);



typedef struct 
{
    u32          periodMs;
    u32          startDelayMs;
   // u8          Priority;
    SchedCbf    Task;

    
}TaskInfo_t;



void    Sched_Init(void);


void    Sched_Start(void);


void    Scheduler(void);





#endif // !SCHED_H_
