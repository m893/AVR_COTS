/***********
 * Author :   Mohammed Akram
 * Date  :   17 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              17 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef  UART_PRIVATE_H
#define  UART_PRIVATE_H

        /* UART DATA REGISTER */
#define  UDR      *((volatile  u8 *)0x2C)

        /*UART CONTEROL AND STATUS REGISTER A */
#define  UCSRA      *((volatile  u8 *)0x2B)

#define  UCSRA_RXC           7      /* USART Receive Complete*/
#define  UCSRA_TXC           6      /* USART Transmit Complete*/
#define  UCSRA_UDRE          5      /* USART Data Register Empty*/
#define  UCSRA_FE            4      /* Frame Error*/
#define  UCSRA_DOR           3      /* Data OverRun*/
#define  UCSRA_PE            2      /*Parity Error*/
#define  UCSRA_U2X           1      /*Double the USART Transmission Speed*/
#define  UCSRA_MPCM          0      /*   Multi-processor Communication Mode */

        /*UART CONTEROL AND STATUS REGISTER B */
#define  UCSRB      *((volatile  u8 *)0x2A)

#define UCSRB_RXCIE         7           /*RX Complete Interrupt Enable*/
#define UCSRB_TXCIE         6           /* TX Complete Interrupt Enable*/
#define UCSRB_UDRIE         5           /* USART Data Register Empty Interrupt Enable*/
#define UCSRB_RXEN          4           /* Receiver Enable*/
#define UCSRB_TXEN          3           /* Transmitter Enable*/
#define UCSRB_UCSZ2         2           /* Character Size BIT 2*/
#define UCSRB_RXB8          1           /* Receive Data Bit 9  */
#define UCSRB_TXB8          0           /* Transmit Data Bit 9 */

            /*UART CONTEROL AND STATUS REGISTER C    (BYTE ACCESABLE )*/
#define  UCSRC      *((volatile  u8 *)0x40)
             
#define UCSRC_URSEL         7           /* Register Select  the UCSRC or the UBRRH Register */
#define UCSRC_UMSEL         6           /* USART Mode Select*/
#define UCSRC_UPM1          5           /* Parity Mode  BIT 1*/
#define UCSRC_UPM0          4           /* Parity Mode  BIT 0*/
#define UCSRC_USBS          3           /* Stop Bit Select*/
#define UCSRC_UCSZ1         2           /*Character Size BIT 1*/
#define UCSRC_UCSZ0         1           /*Character Size BIT 0*/
#define UCSRC_UCPOL         0           /* Clock Polarity*/


            /*UART Baud Rate Registers*/
#define  UBRRL      *((volatile  u8 *)0x29)

#define  UBRRH      *((volatile  u8 *)0x40) /* SHARED WITH UCSRC REGISTER*/

#define  UBRRH_URSEL        7                /* Register Select  the UCSRC or the UBRRH Register */




#endif