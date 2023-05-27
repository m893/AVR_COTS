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


#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_VoidMAsterInit(void)
{
       /* set as master */
    SET_BIT(SPCR,SPCR_MSTR);
      /*chosse MSB*/
    CLEAR_BIT(SPCR , SPCR_DORD);
        /*select leading edge  as rising  egde and trailing  as falling edge */
    CLEAR_BIT(SPCR ,SPCR_CPOL);
        /*select clock phase at leading as sample */
        CLEAR_BIT(SPCR ,SPCR_CPHA);
        /* select clock frequency clk /16*/
        SET_BIT(SPCR,SPCR_SPR0);
        CLEAR_BIT(SPCR , SPCR_SPR1);
        CLEAR_BIT(SPSR , SPSR_SPI2X);

        /* ENABLE SPI */
        SET_BIT(SPCR ,SPCR_SPE);


}
void SPI_VoidSlaveInit(void)
{

            /* set as master */
         CLEAR_BIT(SPCR,SPCR_MSTR);
            /*chosse MSB*/
         CLEAR_BIT(SPCR , SPCR_DORD);
            /*select leading edge  as rising  egde and trailing  as falling edge */
        CLEAR_BIT(SPCR ,SPCR_CPOL);
            /*select clock phase at leading as sample */
        CLEAR_BIT(SPCR ,SPCR_CPHA);
            /* ENABLE SPI */
        SET_BIT(SPCR ,SPCR_SPE);

}
u8 SPI_u8SendReceive(u8 Copy_Data)
{   
    SPDR = Copy_Data ;

    while(GET_BIT(SPSR , SPSR_SPIF)==0);

    SET_BIT(SPSR ,SPSR_SPIF);

    return SPDR ;
}