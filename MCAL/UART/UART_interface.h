/***********
 * Author :   Mohammed Akram
 * Date  :   17 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              17 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef  UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_VoidInit(void);

void UART_VoidTransmitDataSynchronous(u8 Copy_u8Data);

void UART_u8ReceiveDataSynchronous(u8 * Copy_u8ReceivedData);




#endif