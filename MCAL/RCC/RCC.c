/*
 * RCC.c
 *
 *  Created on: Feb 1, 2023
 *      Author: NO3M4N
 */
#include "Bit_Math.h"
#include "Std_Types.h"

#include "RCC.h"
#include "RCC_Cfg.h"
#include "RCC_Prv.h"



static u32 CLK_IsReady(u32 ClockType){

	return (RCC->CR & (ClockType<<1) );
}




/*************************************************
 * RCC INITIALIZATION function
 *
 * INPUT: Void
 *
 * OUTPUT: RCC_enuErrorStatus_t (typedef enum)
 *
 ****************************************************/
RCC_enuErrorStatus_t		RCC_enuInit(void)
{
//	u32 Loc_TempRCC_CR = RCC->CR;
//	u32 Loc_TempRCC_CFGR = RCC->CFGR;
//	u32 Loc_TempRCC_PLLCFGR = RCC->PLLCFGR;
///*
//
//
//	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_OK;
//
//#if (SYS_CLK_SRC	== HSE)
//
//	SET_BIT(RCC->CR,HSEON);  /*  Enable HSE using corresponding. bit  */
//	while( !GET_BIT(RCC->CR,HSERDY) );	/** wait until HSE is ready using Its flag **/
//	CLR_FIELD(RCC->CFGR,SW1,TWO_BIT_CLR);  /*  CLear SW Bits using corresponding. bit  */
//	SET_FIELD(RCC->CFGR,SW1,HSE);  /*  Set SW corr. bits  */
//	while( GET_FIELD(RCC->CFGR,SWS1,TWO_BIT_CLR) != HSE  );	/** wait until HSE is ready using Its flag **/
//
//#elif SYS_CLK_SRC == HSI
//	SET_BIT(RCC->CR,HSION);  /*  Enable HSE usin corr. bit  */
//	while( GET_BIT(RCC->CR,HSIRDY) != 1  );	/** wait until HSE is ready using Its flag **/
//	CLR_FIELD(RCC->CFGR,SW1,TWO_BIT_CLR);  /*  Enable HSE usin corr. bit  */
//	SET_FIELD(RCC->CFGR,SW1,HSI);  /*  Enable HSE usin corr. bit  */
//	while( GET_FIELD(RCC->CFGR,SWS1,TWO_BIT_CLR) != HSI );	/** wait until HSE is ready using Its flag **/
//
//
//#elif	SYS_CLK_SRC == PLL
//
////	SET_BIT(RCC->CR,HSEON);  /*  Enable HSE usin corr. bit  */
////	while( GET_BIT(RCC->CR,HSERDY) != 1  );	/** wait until HSE is ready using Its flag **/
////	CLR_FIELD(RCC->CR,SW1,TWO_BIT_CLR);  /*  Enable HSE usin corr. bit  */
////	SET_FIELD(RCC->CR,SW1,HSE);  /*  Enable HSE usin corr. bit  */
////	while( GET_FIELD(RCC->CR,SWS,TWO_BIT_CLR) != HSE  );	/** wait until HSE is ready using Its flag **/
//	CLR_BIT(RCC->CR,PLLON);
//	while( GET_BIT(RCC->CR,PLLRDY) == 1  );	/** wait until PLL is Off **/
//	CLR_FIELD(RCC->PLLCFGR,PLLP1,TWO_BIT_CLR); // Clear Field from REG
//	SET_FIELD(RCC->PLLCFGR,PLLP1,PLLP);		// Set Cleared Field
//	CLR_FIELD(RCC->PLLCFGR,PLLM5,SIX_BIT_CLR);
//	SET_FIELD(RCC->PLLCFGR,PLLM5,PLLM);
//	CLR_FIELD(RCC->PLLCFGR,PLLN14,NINE_BIT_CLR);
//	SET_FIELD(RCC->PLLCFGR,PLLN14,PLLN);
//	CLR_FIELD(RCC->PLLCFGR,PLLQ3,FOUR_BIT_CLR);
//	SET_FIELD(RCC->PLLCFGR,PLLQ3,PLLQ);
//
//	if(PLL_CLK_SRC == HSE){
//		if(GET_BIT(RCC->CR,HSERDY) != 1 ){
//			SET_BIT(RCC->CR,HSEON);  /*  Enable HSE usin corr. bit  */
//			while( GET_BIT(RCC->CR,HSERDY) != 1  );	/** wait until HSE is ready using Its flag **/
//		}
//	}
//	else if(PLL_CLK_SRC == HSI){
//		if(GET_BIT(RCC->CR,HSIRDY) != 1 ){
//			SET_BIT(RCC->CR,HSION);  /*  Enable HSE usin corr. bit  */
//			while( GET_BIT(RCC->CR,HSIRDY) != 1  );	/** wait until HSE is ready using Its flag **/
//		}
//	}
//
//	else
//	{
//		Loc_enuErrorStatus = RCC_NOK;
//	}
//
//	CLR_FIELD(RCC->CFGR,SW1,TWO_BIT_CLR);  /*  CLear SW Bits using corr. bit  */
//	SET_FIELD(RCC->CFGR,SW1,PLL);  /*  Set SW corr. bits  */
//	while( GET_FIELD(RCC->CFGR,SWS1,TWO_BIT_CLR) != PLL  );	/** wait until HSE is ready using Its flag **/
//#else
//	Loc_enuErrorStatus = RCC_NOK;
//
//#endif
//
//	return	Loc_enuErrorStatus;

	return RCC_OK;

}


/*							Peripherals Clocks								*/
RCC_enuErrorStatus_t RCC_enuEnablePerphClk(u8 Copy_u8RCC_Bus, u8 PerphID){
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_OK;

	if(PerphID <= 31){
		switch(Copy_u8RCC_Bus){
			case RCC_AHB1:	SET_BIT(RCC->AHB1ENR,PerphID);	break;
			case RCC_AHB2:	SET_BIT(RCC->AHB2ENR,PerphID);	break;
			case RCC_APB1:	SET_BIT(RCC->APB1ENR,PerphID);	break;
			case RCC_APB2:	SET_BIT(RCC->APB2ENR,PerphID);	break;
		}
	}
	else{
		/*Return Error*/
		Loc_enuErrorStatus = RCC_NOK;
	}

	return Loc_enuErrorStatus;
}



RCC_enuErrorStatus_t RCC_enuDisablePerphClk(u8 Copy_u8RCC_Bus, u8 PerphID){
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_OK;

	if(PerphID <= 31){
		switch(Copy_u8RCC_Bus){
		case RCC_AHB1:	CLR_BIT(RCC->AHB1ENR,PerphID);	break;
		case RCC_AHB2:	CLR_BIT(RCC->AHB2ENR,PerphID);	break;
		case RCC_APB1:	CLR_BIT(RCC->APB1ENR,PerphID);	break;
		case RCC_APB2:	CLR_BIT(RCC->APB2ENR,PerphID);	break;
		}
	}
	else{
		/*Return Error*/
		Loc_enuErrorStatus = RCC_NOK;
	}

	return Loc_enuErrorStatus;
}

/*************************************************
 * RCC Clock Enable function to enable a certain clock
 *
 * INPUT: u8 ClockType	Check Macros section 1
 *
 * OUTPUT: RCC_enuErrorStatus_t (typedef enum)
 *
 * SYNCHRONOUS
 *
 ****************************************************/
RCC_enuErrorStatus_t RCC_EnableClk(u32 ClockType)
{
	RCC_enuErrorStatus_t	Loc_ErrorStatus = RCC_OK;
	u16	Loc_TimeOut =0;

	RCC->CR |= (u32)ClockType;

	while( !CLK_IsReady(ClockType) && Loc_TimeOut <=2000 ){
		Loc_TimeOut++;
	}
	if ( CLK_IsReady(ClockType) == 0 ){
		Loc_ErrorStatus =RCC_TIMEOUT;
	}
	return Loc_ErrorStatus;

}


/*************************************************
 * RCC Clock Disable function to disable a certain clock
 *
 * INPUT: u8 ClockType	Check Macros section 1
 *
 * OUTPUT: RCC_enuErrorStatus_t (typedef enum)
 *
 ****************************************************/
RCC_enuErrorStatus_t RCC_DisableClk(u32 ClockType)
{
	RCC_enuErrorStatus_t	Loc_ErrorStatus = RCC_OK;
	u16	Loc_TimeOut =0;

	RCC->CR &= ~ClockType;

	while( !CLK_IsReady(ClockType) && Loc_TimeOut <=2000 ){
		Loc_TimeOut++;
	}
	if ( CLK_IsReady(ClockType) == 0 ){
		Loc_ErrorStatus =RCC_TIMEOUT;
	}
	return Loc_ErrorStatus;

}



/*************************************************
 * RCC System Clock Select function
 *
 * INPUT: u8 SysClk	Check Macros section 2
 *
 * OUTPUT: RCC_enuErrorStatus_t (typedef enum)
 *
 ****************************************************/
RCC_enuErrorStatus_t RCC_SelectSysClk(u32 SysClk){

	RCC_enuErrorStatus_t	Loc_ErrorStatus = RCC_OK;
	u16	Loc_TimeOut =0;


	if(SysClk <= SYSCLK_SRC_PLL ){
		volatile u32 Loc_TempReg = RCC->CFGR;
		Loc_TempReg &= ~SYSCLK_SRC_CLR ; // Clear SW bits
		Loc_TempReg |= SysClk;

		RCC->CFGR = Loc_TempReg;
	}
	while( (RCC->CFGR & (CLK_SRC_ERR) ) == (SysClk<<2) && Loc_TimeOut<=2000){
		Loc_TimeOut++;
	}
	if( (RCC->CFGR & (CLK_SRC_ERR) ) != (SysClk>>2) ){
		Loc_ErrorStatus = RCC_TIMEOUT;
	}

	return Loc_ErrorStatus;


}


RCC_enuErrorStatus_t RCC_SelectPLLSource(u8 PLL_SRC )
{
	RCC_enuErrorStatus_t Loc_ErrorStatus =RCC_OK;
	RCC->PLLCFGR &= PLL_SRC;

	return Loc_ErrorStatus;
}



RCC_enuErrorStatus_t RCC_ConfigurePLL(u8 PLL_SRC, u8 PLLP_Macro , u16 PLLN, u8 PLLM, u8 PLLQ)
{
	u32 Loc_TempReg ;
	RCC_enuErrorStatus_t Loc_ErrorStatus;
	Loc_ErrorStatus =RCC_OK;

	if (PLLN < 433 && PLLM <64 && PLLP_Macro<9){

		Loc_ErrorStatus = RCC_WRONGCONF;
	}
	RCC->PLLCFGR &= PLL_SRC;


	Loc_TempReg = RCC->PLLCFGR;	    //Buffer Register To temp Variable
	Loc_TempReg &= PLL_CFGR_CLR;		//clear PLLN bits to mask directly

	Loc_TempReg |= (PLLN << 6 );	// Shift PLLN value and OR with the PLLN Bits
	Loc_TempReg |= (PLLM);
	Loc_TempReg |= ( PLLP_Macro<<16);
	Loc_TempReg |= (PLLQ<<24);

	RCC->PLLCFGR = Loc_TempReg;

	return Loc_ErrorStatus;


}






