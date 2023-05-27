/***********
 * Author :   Mohammed Akram
 * Date  :   17 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              17 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef  SPI_INTERFACE_H
#define  SPI_INTERFACE_H


void SPI_VoidMAsterInit(void);

void SPI_VoidSlaveInit(void);

u8 SPI_u8SendReceive(u8 Copy_Data);




#endif