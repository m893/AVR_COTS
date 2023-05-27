/***********
 * Author :   Mohammed Akram
 * Date  :   17 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              17 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef  SPI_PRIVATE_H
#define  SPI_PRIVATE_H

      /* SPI CONTROL REGISTER */
#define SPCR     *((volatile u8 *)0X2D)

#define SPCR_SPR0       0               /* SPI Clock Rate Select 1 and 0*/
#define SPCR_SPR1       1               /* SPI Clock Rate Select 1 and 0*/
#define SPCR_CPHA       2               /* Clock Phase */
#define SPCR_CPOL       3               /*Clock Polarity*/
#define SPCR_MSTR       4               /* Master/Slave Select*/
#define SPCR_DORD       5               /*Data Order*/
#define SPCR_SPE        6               /*Data Order*/
#define SPCR_SPIE       7               /*SPI Interrupt Enable*/

        /* SPI STATUS  REGISTER */
#define SPSR     *((volatile u8 *)0X2E)

#define SPSR_SPI2X      0               /*SPI Interrupt Enable*/
#define SPSR_WCOL       6               /* Write COLlision Flag*/
#define SPSR_SPIF       7               /* SPI Interrupt Flag*/

            /* SPI DATA REGISTER */
#define SPDR     *((volatile u8 *)0X2F)






#endif