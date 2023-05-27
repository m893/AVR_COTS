/***********
 * Author :   Mohammed Akram 
 * Date  :   29 March,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              29 Marc, 2023               Mohammed Akram
***************************************************************************/

#ifndef GIE_PRIVATE_H
#define  GIE_PRIVATE_H

//location of SREG register in RAm mirror of (I/O Memory)
#define  SREG     *((volatile u8 * )0x5f)
//bit number of global enable 
#define SREG_BIT7       7


#endif