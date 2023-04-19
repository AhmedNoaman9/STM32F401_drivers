/*
 * RCC_Prv.h
 *
 *  Created on: Feb 1, 2023
 *      Author: NO3M4N
 */

#ifndef RCC_PRV_H_
#define RCC_PRV_H_


#define RCC_BASE_ADDR	*((volatile u32*) 0x40023800 )


typedef struct{

	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 RESERVED1;
	volatile u32 RESERVED2;
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 RESERVED3;
	volatile u32 RESERVED4;
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 RESERVED5;
	volatile u32 RESERVED6;
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 RESERVED7;
	volatile u32 RESERVED8;
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 RESERVED9;
	volatile u32 RESERVED10;
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 RESERVED11;
	volatile u32 RESERVED12;
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 RESERVED13;
	volatile u32 RESERVED14;
	volatile u32 SSCGR;
	volatile u32 I2SCFGR;
	volatile u32 RESERVED15;
	volatile u32 RESERVED16;
	volatile u32 DKCFGR;


}RCC_t;


typedef struct {

	u8 BusId;
	u8 PerphId;

}PerphID_t;


#define RCC ((volatile RCC_t* const)(0x40023800))



/***************************************************************
 * 	RCC USED BITS
 *
 **************************************************/

#define HSION	0
#define HSIRDY	1



#define HSEON	16
#define HSERDY	17


#define SW0	0
#define SW1	1

#define SWS1	 3

#define SWS	0b11

#define PLLON 	24
#define PLLRDY	25


#define PLLM0	0
#define PLLM1	1
#define PLLM2	2
#define PLLM3	3
#define PLLM4	4
#define PLLM5	5



#define PLLN14	14


#define PLLQ3	27


#define PLLP1	17


/*************************************************************/

#endif /* RCC_PRV_H_ */
