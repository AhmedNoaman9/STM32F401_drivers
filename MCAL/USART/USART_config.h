/*****************************************************************************/
/*
*Version: 1
*/
/****************************************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define   ACTIVE_USART_CHANNELS   3



/*
 * current baud rate settings are 9600
 * for 72 Mhz on UART1   //0x1D4C
 * for 36 Mhz on UART2   //0xEA6
 * */

#define PCLKx				25000000	/* The USART peripheral clock : different for APB1 and APB2 */
#define OVR8					0       /* 1 : for sampling by 16, 0 for sampling by 8 */

/*  Synchronous_SetUp Options:-
 * 	Sample_At_Leading_Rising_Edge ,
 *	Sample_At_Trailing_Falling_Edge ,
 *	Sample_At_Leading_Falling_Edge ,
 *	Sample_At_Trailing_Rising_Edge
*/

#define Synchronous_SetUp					Sample_At_Leading_Rising_Edge
#endif
