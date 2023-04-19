/*
 * NVIC.c
 *
 *  Created on: Mar 2, 2023
 *      Author: NO3M4N
 */


#include "Bit_Math.h"
#include "Std_Types.h"

#include "NVIC.h"
#include "NVIC_Cfg.h"

#include "NVIC_Prv.h"

/***************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*****************************************************************************/

#define AIRCR_VECTKEY 							0xFA05

/****************************************************************************
*  LOCAL (GLOBAL) DATA
*****************************************************************************/

u8 Loc_IRQreg;
u8 Loc_IRQbit;




/****************************************************************************
*  FUNCTIONS
*****************************************************************************/


void NVIC_SetPriorityGrouping(u32 priority_grouping){

	u32 Loc_TempReg = AIRCR;
	/* Configure Grouping/SubGroubing System AIRCR register in SCB*/
	Loc_TempReg &= NVIC_PRIORITY_GROUPING_CLR;
	Loc_TempReg |= priority_grouping;

	AIRCR = Loc_TempReg;

}



void	NVIC_EnableIRQ(IRQn_t	IRQn){

	if(IRQn <= 239){

		Loc_IRQbit = IRQn % WORD_LENGTH_BITS;
		Loc_IRQreg = IRQn / WORD_LENGTH_BITS;

		SET_BIT(NVIC->ISER[Loc_IRQreg], Loc_IRQbit);

	}

}

void	NVIC_DisableIRQ(IRQn_t	IRQn){


	if(IRQn <= 239){

			Loc_IRQbit = IRQn % WORD_LENGTH_BITS;
			Loc_IRQreg = IRQn / WORD_LENGTH_BITS;


			SET_BIT(NVIC->ICER[Loc_IRQreg], Loc_IRQbit);

		}
}



void NVIC_SetPendingIRQ(IRQn_t IRQn){

	u8 Loc_IRQreg;
	u8 Loc_IRQbit;

	if(IRQn <= 239){

		Loc_IRQbit = IRQn % WORD_LENGTH_BITS;
		Loc_IRQreg = IRQn / WORD_LENGTH_BITS;


		SET_BIT(NVIC->ISPR[Loc_IRQreg], Loc_IRQbit);

	}
	else{
		//Error
	}

}


void NVIC_ClearPendingIRQ(IRQn_t IRQn){

	if(IRQn <= 239){

			Loc_IRQbit = IRQn % WORD_LENGTH_BITS;
			Loc_IRQreg = IRQn / WORD_LENGTH_BITS;


			SET_BIT(NVIC->ICPR[Loc_IRQreg], Loc_IRQbit);

		}
}



u32 NVIC_GetPendingIRQ(IRQn_t IRQn){


	if (IRQn <= 239)
	{
	Loc_IRQbit = IRQn % WORD_LENGTH_BITS;
	Loc_IRQreg = IRQn / WORD_LENGTH_BITS;

	}
	else{
		//error
	}
	return GET_BIT(NVIC->ISPR[Loc_IRQreg], Loc_IRQbit);

}

void NVIC_SetPriority(IRQn_t IRQn, u32 priority){




}

u32 NVIC_GetPriority(IRQn_t IRQn){

}


u32 NVIC_GetActive (IRQn_t IRQn){

}



void NVIC_triggerSWInterrupt(IRQn_t IRQn){


	if ( IRQn<NumberOfIRQs)
		STIR = IRQn;


}
