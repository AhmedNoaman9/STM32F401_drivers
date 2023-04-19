/*
 * NVIC_Cfg.h
 *
 *  Created on: Mar 2, 2023
 *      Author: NO3M4N
 */

#ifndef NVIC_CFG_H_
#define NVIC_CFG_H_



/*
*	please choose form the followings
*	NVIC_GROUPING_SYSTEM_XXXX : [0-7] Groups, [0]subgroups
*	NVIC_GROUPING_SYSTEM_XXXY : [0-3] Groups, [0-1]subgroups
*	NVIC_GROUPING_SYSTEM_XYYY : [0-1] Groups, [0-3]subgroups
*	NVIC_GROUPING_SYSTEM_YYYY : [0] Groups,	 [0-7]subgroups Non-Preemtion system
*/
#define NVIC_GROUPING_SYSTEM   NVIC_PRIORITY_GROUPING_XXXX

/*Enable/Disable All Interrupt Choose between (CPU_DISABLE_ALL_Interupts()/CPU_Enable_ALL_Interupts())*/
#define   Enable_Disable_All_Interrupt CPU_Enable_ALL_Interupts()

#define NVIC_ACTIVATED_INT_SIZE  2





#endif /* NVIC_CFG_H_ */
