/***********
 * Author :   Mohammed Akram
 * Date  :   17 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              17 April, 2023               Mohammed Akram
***************************************************************************/

#include "../../../COTS/LIB/BIT_MATH.h"
#include "../../../COTS/LIB/STD_TYPES.h"


#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void UART_VoidInit(void)
{
        u8 Local_u8UCSRCTemp=0 ;  

        /* asynchrounous mode */
        CLEAR_BIT(Local_u8UCSRCTemp , UCSRC_URSEL);

        /* enable tx and rx circuits*/
            SET_BIT(UCSRB , UCSRB_TXEN);
            SET_BIT(UCSRB , UCSRB_RXEN);
        /*data size */
        SET_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ0);
        SET_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ1);
        SET_BIT(UCSRB , UCSRB_UCSZ2);
        /*parity disabled*/

        CLEAR_BIT(Local_u8UCSRCTemp , UCSRC_UPM0);
        CLEAR_BIT(Local_u8UCSRCTemp , UCSRC_UPM0);

        /* stop bit 1 bit*/
        CLEAR_BIT(Local_u8UCSRCTemp , UCSRC_USBS);


        SET_BIT(Local_u8UCSRCTemp,UCSRC_URSEL);     //write in ucsrc register
            /* assign variable value to register */
        UCSRC=Local_u8UCSRCTemp ;

        

        /* disable double speed mode*/
        CLEAR_BIT(UCSRA , UCSRA_U2X);
        /* set baudrate to be 9600*/
        UBRRL=51 ;
        /*write in UBRRH register*/
        SET_BIT(UBRRH,UBRRH_URSEL);

        UBRRH = 0;

}

void UART_VoidTransmitDataSynchronous(u8 Copy_u8Data)
{
            /*polling untill UDR empty*/
        while(GET_BIT(UCSRA ,UCSRA_UDRE)==0);
            /*copy data to udr register*/
        UDR = Copy_u8Data ;
            /*polling untill transmitting complete*/
        while(GET_BIT(UCSRA ,UCSRA_TXC)==0);
            /* clear flag*/
        SET_BIT(UCSRA , UCSRA_TXC);
}

void UART_u8ReceiveDataSynchronous(u8 * Copy_u8ReceivedData)
{
        /*polling untill receiving complete*/
        while(GET_BIT(UCSRA , UCSRA_RXC)==0);
            /* get the receive data */
            * Copy_u8ReceivedData = UDR ;
      
}