#ifndef UART_Interface_H_
#define UART_Interface_H_

typedef enum{
	UART_RX_INTERRUPT = 0,
	UART_UDRE_INTERRUPT ,
	UART_TX_INTERRUPT
}UART_INTERRUPTS_e;

void MUART_voidInit(void);
void MUART_voidReadStringSyncBlocking(u8 *str);
void MUART_voidSendByteSyncBlocking (u8 A_u8DataByte);
u8 MUART_u8ReadByteAsync (void);
void MUART_voidSendByteSyncNonBlocking (u8 A_u8DataByte);
u8 MUART_u8ReadByteSyncBlocking (void);
void MUART_voidSendStringSyncNonBlocking (u8 *A_pu8String);
void MUART_voidSendStringSyncBlocking (u8 *A_pu8String);
void MUART_voidSendByteAsync (u8 A_u8DataByte);
u8 MUART_u8ReadByteSyncNonBlocking (void);
void MUART_voidSetCallBack (UART_INTERRUPTS_e A_InterruptSource , void (*A_PtoFunc)(void));
void MUART_u8ReceiveString(u8  Copy_Pu8DataString[]);
void UART_ClearBuffer(void);

#endif /* UART_Interface_H_ */