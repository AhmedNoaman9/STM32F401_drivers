/*
 * RCC_Cfg.h
 *
 *  Created on: Feb 1, 2023
 *      Author: NO3M4N
 */

#ifndef RCC_CFG_H_
#define RCC_CFG_H_





#define SYS_CLK_SRC	HSI



/*	PLL CONFIGURATION
 *
 * 	f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
 	 f(PLL general clock output) = f(VCO clock) / PLLP
 	 f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ
 *
 *
 * */
#define PLL_CLK_SRC	HSE


/*	Must Be Between 192 -> 432 ONLY	*/
#define PLLN_CONF		200U
/*	Must Be Between 2 --> 63 ONLY	*/
#define PLLM_CONF		50U

/* PLLN/PLLM Defaulted at 4 Use PLLP for simple Calibration  */

/*	Must Be Between 2 --> 15 ONLY	*/
#define PLLQ_CONF		50U

/*	Must Be 2 , 4 , 6 , 8  ONLY	*/
#define PLLP_CONF		2U









#endif /* RCC_CFG_H_ */
