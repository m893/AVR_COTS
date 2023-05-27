/***********
 * Author :   Mohammed Akram 
 * Date  :   22 March,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              22 Marc, 2023               Mohammed Akram
***************************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define input   0
#define outout  1

#define low     0
#define high    1
//registers Location in memory mirror of  (I/O Memory)
#define PORTA   *((volatile u8* ) 0x3B)
#define DDRA   *((volatile u8* ) 0x3A)  
#define PINA   *((volatile u8* ) 0x39) 

#define PORTB   *((volatile u8* ) 0x38)
#define DDRB   *((volatile u8* ) 0x37)  
#define PINB   *((volatile u8* ) 0x36)

#define PORTC   *((volatile u8* ) 0x35)
#define DDRC   *((volatile u8* ) 0x34)  
#define PINC   *((volatile u8* ) 0x33)

#define PORTD   *((volatile u8* ) 0x32)
#define DDRD   *((volatile u8* ) 0x31)  
#define PIND   *((volatile u8* ) 0x30)


#endif 
