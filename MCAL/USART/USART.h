/*****************************************************************************/
/*
*Version: 1
*/
/****************************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

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

typedef	enum 	USART_states_e{
	USART_IDLE,
	USART_BUSY,
	USART_OK,


}USART_STATE_e;


typedef enum USART_e{
	/****************************************************************************/
	/*
	 * USART Channels
	 * Note: UART4 and UART5 work only in asynchronous mode
	 *
	 */
	USARTChannel1 ,
	USARTChannel2 ,
	/*
	USART3 ,
	UART4  ,
	UART5  ,
	*/
	USARTChannel6 ,
	/****************************************************************************/
	/*
	 * Mode
	 * Note: In current driver, if i choose DMA it can only be in transmitter or in receiver not both together
	 */
	Asynchronous,
	Synchronous,
	UART_DMA_Receiver,
	UART_DMA_Transmitter,
	/****************************************************************************/
	/*
	 * Parity Options
	 */
	Even_Parity,
	Odd_Parity,
	No_Parity,
	/****************************************************************************/
	/*
	 * Word Length
	 */
	Data_8_Bits,   /*The data frame is 8-bits with parity bit(MSB), received word is 7-bits*/
	Data_9_Bits,   /*The data frame is 9-bits with parity bit(MSB), received word is 8-bits*/
	/****************************************************************************/
	/*
	 * No. of stop bits
	 */
	One_Stop_Bit =0,
	Half_Stop_Bit,
	Two_Stop_Bits,
	OneAndHalf_Stop_Bits,
	/****************************************************************************/
	/*
	 * Baud Rate
	 * */
	BaudRate_2400 = 	2400,
	BaudRate_9600 = 	9600,
	BaudRate_19200 = 	19200,
	BaudRate_57600 = 	57600,
	BaudRate_115200 = 	115200,
	/****************************************************************************/
	USART_IdleLineInt =4,
	USART_RxDataNotEmptyInt,
	USART_TransmissionCompeleteInt,
	USART_TxDataEmptyInt,
	/****************************************************************************/
	USART_Interrupt_Enable,
	USART_Interrupt_Disable,
	/****************************************************************************/
	USART_TX_ENABLE ,
	USART_TX_DISABLE ,

	USART_RX_ENABLE ,
	USART_RX_DISABLE

}USART_enum;

typedef struct{
	
	u8 UartNo;
	USART_enum	TXen;
	USART_enum	RXen;
	USART_enum Word_Length;
	USART_enum Parity;
	USART_enum Baud_Rate;
	USART_enum Stop_Bits;
	USART_enum Mode;

}USART_Init_struct;


void MUSART_voidInit(USART_Init_struct * Copy_structInitConfig);
void MSUART_voidInterrupt(u8 Copy_USART_Channel , USART_enum Copy_eInt, USART_enum Copy_eState);




u8 MSUART_u8ReceiveWait(u8 Copy_USART_Channel);
void MSUART_voidTransmitCharWait(u8 Copy_USART_Channel, u8 Copy_u8Character);
void MSUART_voidTransmitStringArrayWait(u8 Copy_USART_Channel, u8 Copy_u8StringArray[]);

u8 MSUART_u8ReadDataRegister(u8 Copy_USART_Channel);
void MSUART_voidLoadDataRegister(u8 Copy_USART_Channel, u8 Copy_u8Character);

USART_STATE_e	MUSART_sendBufferAsync(u8	Copy_USART_Channel ,u8	*Buffer, u32 Size);
USART_STATE_e	MUSART_recieveBufferAsync(u8	Copy_USART_Channel ,u8	*Buffer, u32 Size);

u8 MSUART_u8GetFlagTC(u8 Copy_USART_Channel);
u8 MSUART_u8GetFlagRxNE(u8 Copy_USART_Channel);
u8 MSUART_u8GetFlagTxE(u8 Copy_USART_Channel);
u8 MSUART_u8GetFlagIdle(u8 Copy_USART_Channel);

void MUSART_VidClearFlags( u8 Copy_USART_Channel );


void MUSART1_voidSetCallBack( void (* ptr) (void) );
void MUSART2_voidSetCallBack(void (* ptr) (void));
/*void MUSART3_voidSetCallBack( void (* ptr) (void) );
void MUART4_voidSetCallBack( void (* ptr) (void) );
void MUART5_voidSetCallBack( void (* ptr) (void) );*/
void MUSART6_voidSetCallBack( void (* ptr) (void) );

#endif
