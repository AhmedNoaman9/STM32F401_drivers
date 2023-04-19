#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "USART.h"
#include "USART_private.h"
#include "USART_config.h"

static	u8 *TxBuffer[ACTIVE_USART_CHANNELS];
static u32	Tx_Size[ACTIVE_USART_CHANNELS];
static u32	Tx_Idx[ACTIVE_USART_CHANNELS];

static	USART_STATE_e	Tx_Status[ACTIVE_USART_CHANNELS] = {USART_IDLE, USART_IDLE, USART_IDLE};

static	u8 *RxBuffer[ACTIVE_USART_CHANNELS];
static u32	Rx_Size[ACTIVE_USART_CHANNELS];
static u32	Rx_Idx[ACTIVE_USART_CHANNELS];


static	USART_STATE_e	Rx_Status[ACTIVE_USART_CHANNELS] = {USART_IDLE, USART_IDLE, USART_IDLE};



volatile USART_Registers_Type* Uart_Channels[ACTIVE_USART_CHANNELS]=
{
		((volatile USART_Registers_Type *)  USART1_BaseAddress ),
		((volatile USART_Registers_Type *)  USART2_BaseAddress ),

	/*	((volatile USART_Registers_Type *)  USART3_BaseAddress ),
		((volatile USART_Registers_Type *)  USART4_BaseAddress ),
		((volatile USART_Registers_Type *)  USART5_BaseAddress ),		
	*/
		((volatile USART_Registers_Type *)  USART6_BaseAddress ),
};

void MUSART_voidInit(USART_Init_struct * Copy_structInitConfig)
{

	u32	Loc_u32TempReg;
		f32 Loc_f32TempValue;
		u16	Loc_u16TempMantissa = 0;
		u8	Loc_u16TempFraction = 0;
		f32 Loc_f32TempFraction;

		/**Calculatig Baud Rate***/
		Loc_f32TempValue  =  (u32)PCLKx  ;
		Loc_f32TempValue /= ((u16)Copy_structInitConfig->Baud_Rate * (8 * (2 - OVR8))) ;

		Loc_u16TempMantissa = Loc_f32TempValue;
		Loc_u16TempFraction = ( Loc_f32TempValue - Loc_u16TempMantissa ) * ( 8 * (2 - OVR8)) ;
		//Loc_f32TempFraction = (Loc_f32TempValue % 1000) * (8 * (2 - OVR8));
		//Loc_f32TempFraction = Loc_f32TempFraction / 1000;

		/*if(Loc_f32TempFraction > 0xF)
		{
			Loc_u16TempMantissa += (Loc_f32TempFraction & 0xF0);
		}
		Loc_u16TempMantissa = Loc_f32TempValue ;
	*/
	/*Store the Baudrate*/
	Uart_Channels[Copy_structInitConfig->UartNo]->USART_BRR
	= (Loc_u16TempMantissa << 4) | (Loc_u16TempFraction & 0x0F);

	Loc_u32TempReg = Uart_Channels[Copy_structInitConfig->UartNo]->USART_CR1 ;
	/** Parity  ***/

	if (Copy_structInitConfig->Parity == No_Parity)
	{
		SET_BIT(Loc_u32TempReg, USART_CR1_PCE);
	}
	else
	{
		if (Copy_structInitConfig->Parity == Odd_Parity)
		{
			/* code */
			SET_BIT(Loc_u32TempReg, USART_CR1_PS);
		}
		else
		{
			CLR_BIT(Loc_u32TempReg, USART_CR1_PS);
		}
	}
	if (Copy_structInitConfig->Word_Length == Data_9_Bits)
	{
		SET_BIT(Loc_u32TempReg, USART_CR1_M);
	}
	else/*8 Bit Data*/
	{
		CLR_BIT(Loc_u32TempReg, USART_CR1_M);
	}
	if (Copy_structInitConfig->TXen == USART_TX_ENABLE)
	{
		SET_BIT(Loc_u32TempReg, USART_CR1_TE);
	}
	else{
		CLR_BIT(Loc_u32TempReg, USART_CR1_TE);
	}
	if (Copy_structInitConfig->RXen == USART_RX_ENABLE)
	{
		SET_BIT(Loc_u32TempReg, USART_CR1_RE);
	}
	else{
		CLR_BIT(Loc_u32TempReg, USART_CR1_RE);
	}

	Loc_u32TempReg |= ( (u32)OVR8 << 15 );

	Uart_Channels[Copy_structInitConfig->UartNo]->USART_CR1 = Loc_u32TempReg;

	Loc_u32TempReg = Uart_Channels[Copy_structInitConfig->UartNo]->USART_CR2 ;

	if (Copy_structInitConfig->Stop_Bits == One_Stop_Bit)
	{
		SET_BIT(Loc_u32TempReg, USART_CR2_STOP);
	}
	else{
		CLR_BIT(Loc_u32TempReg, USART_CR2_STOP);
	}


	switch (Copy_structInitConfig->Mode)
	{
		case UART_DMA_Receiver:
			SET_BIT(Uart_Channels[Copy_structInitConfig->UartNo]->USART_CR3,USART_CR3_DMAR);
			break;
		case UART_DMA_Transmitter:
			SET_BIT(Uart_Channels[Copy_structInitConfig->UartNo]->USART_CR3, USART_CR3_DMAT);
			break;
		case Synchronous:
			Uart_Channels[Copy_structInitConfig->UartNo]->USART_CR2 |= (Synchronous_SetUp<<USART_CR2_CPHA);
			SET_BIT(Uart_Channels[Copy_structInitConfig->UartNo]->USART_CR2,USART_CR2_CLKEN);
			break;
		default: 		/*Asynchronous*/
			break;
	}


	/****ENABLE USART****/

	SET_BIT(Uart_Channels[Copy_structInitConfig->UartNo]->USART_CR1,USART_CR1_UE);

	Uart_Channels[Copy_structInitConfig->UartNo]->USART_SR = 0;

}

void MSUART_voidInterrupt(u8 Copy_USART_Channel, USART_enum Copy_eInt, USART_enum Copy_eState)
{
	if(Copy_eState == USART_Interrupt_Enable)
	{
		SET_BIT(Uart_Channels[Copy_USART_Channel]->USART_CR1,Copy_eInt);
	}
	else if(Copy_eState == USART_Interrupt_Disable)
	{
		CLR_BIT(Uart_Channels[Copy_USART_Channel]->USART_CR1,Copy_eInt);
	}
}

/****************************************************************************************************************************************/
/*Use these functions in Interrupt Call Back to know which flag fired the global USART interrupt in case of several interrupts */
u8 MSUART_u8GetFlagTC(u8 Copy_USART_Channel)
{
	return (GET_BIT( Uart_Channels[Copy_USART_Channel]->USART_SR, USART_SR_TC));
}
u8 MSUART_u8GetFlagRxNE(u8 Copy_USART_Channel)
{
	return (GET_BIT( Uart_Channels[Copy_USART_Channel]->USART_SR, USART_CR1_RXNEIE));
}
u8 MSUART_u8GetFlagTxE(u8 Copy_USART_Channel)
{
	return (GET_BIT( Uart_Channels[Copy_USART_Channel]->USART_SR, USART_CR1_TXEIE));
}
u8 MSUART_u8GetFlagIdle(u8 Copy_USART_Channel)
{
	return (GET_BIT( Uart_Channels[Copy_USART_Channel]->USART_SR, USART_CR1_IDLEIE));
}



void MUSART_VidClearFlags(u8 Copy_USART_Channel  ){

	/* Clear all flags */
	Uart_Channels[Copy_USART_Channel]->USART_SR=0;

}




/****************************************************************************************************************************************/
u8 MSUART_u8ReadDataRegister(u8 Copy_USART_Channel)
{
	return Uart_Channels[Copy_USART_Channel]->USART_DR;
}


void MSUART_voidLoadDataRegister(u8 Copy_USART_Channel, u8 Copy_u8Character)
{
	Uart_Channels[Copy_USART_Channel]->USART_DR = Copy_u8Character;
}
/****************************************************************************************************************************************/

u8 MSUART_u8ReceiveWait(u8 Copy_USART_Channel)
{
	while( MSUART_u8GetFlagRxNE(Copy_USART_Channel) == 0 );
	return MSUART_u8ReadDataRegister(Copy_USART_Channel);
}
void MSUART_voidTransmitCharWait(u8 Copy_USART_Channel, u8 Copy_u8Character)
{
	MSUART_voidLoadDataRegister(Copy_USART_Channel,Copy_u8Character);
	while( MSUART_u8GetFlagTC(Copy_USART_Channel) == 0);
}
void MSUART_voidTransmitStringArrayWait(u8 Copy_USART_Channel, u8 Copy_u8StringArray[])
{
	u8 Local_u8CharCounter =0;
	while(Copy_u8StringArray[Local_u8CharCounter] != '\0')
	{
		MSUART_voidLoadDataRegister( Copy_USART_Channel, Copy_u8StringArray[Local_u8CharCounter]);
		while( MSUART_u8GetFlagTC(Copy_USART_Channel) == 0);
		Local_u8CharCounter++;
	}
}


/************Asynchronous Send And Recieve***************************************************************************************************************************/

USART_STATE_e	MUSART_sendBufferAsync(u8	Copy_USART_Channel ,u8	*Buffer, u32 Size)
{

	USART_STATE_e Res = USART_BUSY;

	if(Tx_Status[Copy_USART_Channel] == USART_IDLE)
	{
		TxBuffer[Copy_USART_Channel] = Buffer;
		Tx_Size[Copy_USART_Channel] = Size;
		Tx_Idx[Copy_USART_Channel] = 0;
		Tx_Status[Copy_USART_Channel] = USART_BUSY;
		Uart_Channels[Copy_USART_Channel]->USART_DR = (u32) TxBuffer[Tx_Idx[Copy_USART_Channel]];
		Tx_Idx[Copy_USART_Channel]++;
		Res = USART_OK;
	}
	return	Res;

}

USART_STATE_e	MUSART_recieveBufferAsync(u8	Copy_USART_Channel ,u8	*Buffer, u32 Size)
{

	USART_STATE_e Res = USART_BUSY;

	if(Rx_Status[Copy_USART_Channel] == USART_IDLE)
	{
		RxBuffer[Copy_USART_Channel] = Buffer;
		Rx_Size[Copy_USART_Channel] = Size;
		Rx_Idx[Copy_USART_Channel] = 0;

		Uart_Channels[Copy_USART_Channel]->USART_SR &= ~(1 << USART_SR_RXNE);
		Uart_Channels[Copy_USART_Channel]->USART_CR1 |= (1 << USART_CR1_TXEIE);
		//Rx_Idx[Copy_USART_Channel]++;

		Rx_Status[Copy_USART_Channel] = USART_BUSY;
		Res = USART_OK;
	}
	return	Res;

}
















void MUSART1_voidSetCallBack( void (* ptr) (void) )
{
	USART1_CallBack = ptr;
}

void USART1_IRQHandler(void)
{
	if( MSUART_u8GetFlagTC(USARTChannel1) ){

		if(Tx_Idx[USARTChannel1] < Tx_Size[USARTChannel1])
		{
			Uart_Channels[USARTChannel1]->USART_DR = (u32) TxBuffer[USARTChannel1][Tx_Idx[USARTChannel1]];
			Tx_Idx[USARTChannel1]++;
		}
		else if(Tx_Idx[USARTChannel1] == Tx_Size[USARTChannel1]){
			Tx_Status[USARTChannel1]=USART_IDLE;
			if (USART1_CallBack){
				USART1_CallBack();
			}
		}
	}

	if(	MSUART_u8GetFlagRxNE(USARTChannel1) && Rx_Status[USARTChannel1]== USART_BUSY ){

		RxBuffer[USARTChannel1][Rx_Idx[USARTChannel1]]  = (u8) (0xFF & Uart_Channels[USARTChannel1]->USART_DR ) ;
		if(Rx_Idx[USARTChannel1] == Rx_Size[USARTChannel1]){
			Rx_Status[USARTChannel1] = USART_IDLE;
			/* Diable Rx Interrupt */
			Uart_Channels[USARTChannel1]->USART_CR1 &= ~ (1 << USART_CR1_RXNEIE);
		}
		Rx_Idx[USARTChannel1]++;
	}


}

void MUSART2_voidSetCallBack(void (* ptr) (void))
{
	USART2_CallBack = ptr;
}
void USART2_IRQHandler(void)
{
	if( MSUART_u8GetFlagTC(USARTChannel2) ){

			if(Tx_Idx[USARTChannel2] < Tx_Size[USARTChannel2])
			{
				Uart_Channels[USARTChannel2]->USART_DR = (u32) TxBuffer[USARTChannel2][Tx_Idx[USARTChannel2]];
				Tx_Idx[USARTChannel2]++;
			}
			else if(Tx_Idx[USARTChannel2] == Tx_Size[USARTChannel2]){
				Tx_Status[USARTChannel1]=USART_IDLE;
				if (USART1_CallBack){
					USART1_CallBack();
				}
			}
		}

		if(	MSUART_u8GetFlagRxNE(USARTChannel2) && Rx_Status[USARTChannel2]== USART_BUSY ){

			RxBuffer[USARTChannel2][Rx_Idx[USARTChannel2]]  = (u8) (0xFF & Uart_Channels[USARTChannel2]->USART_DR ) ;
			if(Rx_Idx[USARTChannel2] == Rx_Size[USARTChannel2]){
				Rx_Status[USARTChannel2] = USART_IDLE;
				/* Diable Rx Interrupt */
				Uart_Channels[USARTChannel2]->USART_CR1 &= ~ (1 << USART_CR1_RXNEIE);
			}
			Rx_Idx[USARTChannel2]++;
		}
}



void MUSART6_voidSetCallBack( void (* ptr) (void) )
{
	USART6_CallBack = ptr;
}

void USART6_IRQHandler(void)
{
	if( MSUART_u8GetFlagTC(USARTChannel6) ){

				if(Tx_Idx[USARTChannel6] < Tx_Size[USARTChannel6])
				{
					Uart_Channels[USARTChannel6]->USART_DR = (u32) TxBuffer[USARTChannel6];
					Tx_Idx[USARTChannel6]++;
				}
				else if(Tx_Idx[USARTChannel6] == Tx_Size[USARTChannel6]){
					if (USART1_CallBack){
						USART1_CallBack();
					}
				}
			}

			if(	MSUART_u8GetFlagRxNE(USARTChannel6) && Rx_Status[USARTChannel6]== USART_BUSY ){

				*RxBuffer[USARTChannel6]  = (u8) (0xFF & Uart_Channels[USARTChannel6]->USART_DR ) ;
				if(Rx_Idx[USARTChannel6] == Rx_Size[USARTChannel6]){
					Rx_Status[USARTChannel6] = USART_IDLE;
					/* Diable Rx Interrupt */
					Uart_Channels[USARTChannel6]->USART_CR1 &= ~ (1 << USART_CR1_RXNEIE);
				}
				Rx_Idx[USARTChannel6]++;
			}
}
