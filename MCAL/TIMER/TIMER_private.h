/***********
 * Author :   Mohammed Akram
 * Date  :   10 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              10 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H


#define PRESCALER_MASK      0b11111000

#define PRESCALER_TIMER_STOP      0
#define PRESCALER_1               1
#define PRESCALER_8               2
#define PRESCALER_64              3
#define PRESCALER_256             4
#define PRESCALER_1024            5
#define COUNTER_WITH_FALLING      6            
#define COUNTER_WITH_RISSING      7            


/*REGISTER TO SELECT MODE FOR TIMER OR COUNTER AND THE PRESCALER AND SELECT MODE TIMER O */
#define  TCCR0           *((volatile u8 *)0x53)

#define TCCR0_CS00        0       //SELECT TIMER OR COUNTER AND PRESCAELR FOR TIMER MODE
#define TCCR0_CS01        1       //SELECT TIMER OR COUNTER AND PRESCAELR FOR TIMER MODE
#define TCCR0_CS02        2       //SELECT TIMER OR COUNTER AND PRESCAELR FOR TIMER MODE
#define TCCR0_WGM01       3       //SELECT NORMAL MODE OR CTC MODE
#define TCCR0_COM00       4       //MODE OF OC0 IN CTC MODE
#define TCCR0_COM01       5       //MODE OF OC0 IN CTC MODE
#define TCCR0_WGM00       6       //SELECT NORMAL MODE OR CTC MODE
#define TCCR0_FOC0        7       


/*REGISTER TO SELECT MODE FOR TIMER OR COUNTER AND THE PRESCALER AND SELECT MODE TIMER 2 */
 
#define TCCR2                       *((volatile u8 *)0x45)

#define TCCR2_CS20          0               //SELECT TIMER OR COUNTER AND PRESCAELR FOR TIMER MODE
#define TCCR2_CS21          1               //SELECT TIMER OR COUNTER AND PRESCAELR FOR TIMER MODE
#define TCCR2_CS22          2               //SELECT TIMER OR COUNTER AND PRESCAELR FOR TIMER MODE
#define TCCR2_WGM21         3
#define TCCR2_COM20         4
#define TCCR2_COM21         5
#define TCCR2_WGM20         6
#define TCCR2_FOC2          7       


//REGISTER TO STORE TIMER VALUE FOR TIMER 0
#define  TCNT0                  *((volatile u8 *)0x52)

//REGISTER TO STORE TIMER VALUE FOR TIMER 2
#define TCNT2                    *((volatile u8 *)0X44)       


// REISTER TO SET THE COMPARE VALUE FOR TIMER 0
#define OCR0                        *((volatile u8 *)0x5c)


// REISTER TO SET THE COMPARE VALUE FOR TIMER 2
#define OCR2                        *((volatile u8 *)0X43)


//REGISTER TO SET INTERRUPT ENABLE FOR NORMAL MODE AND CTC MODE
#define TIMSK                       *((volatile u8 *)0x59)

#define TIMSK_TOIE0                    0       //TIMER OVERFLOW INTERRUPT ENABLE 
#define TIMSK_OCIE0                    1       //TIMER OUTPUT COMPARE MATCH ENABLE
#define TIMSK_TOIE1                    2        // TIMER 1 OVERFLOW ENTERRUPT
#define TIMSK_OCIE1B                   3        //TIMER 1 COMPARE B  MATCH INTERRUPT ENABLE
#define TIMSK_OCIE1A                   4        //TIMER 1 COMPARE A MATCH INTERRUPT ENABLE
#define TIMSK_TICIE1                   5           //TO ENABLE INPUT CAPTURE UNIT  INTERRUPT
#define TIMSK_TOIE2                    6        //TIMER OUTPUT COMPARE MATCH ENABLE FOR TIMER 2
#define TIMSK_OCIE2                    7        //TIMER OVERFLOW INTERRUPT ENABLE FOR TIMER 2



#define TIMSK_TICIE1                    5           //TO ENABLE INPUT CAPTURE INTERRUPT




//REGISTER FOR TIMER FLAGS
#define  TIFR                           *((volatile u8 *)0x58)

#define TIFR_TOV0                      0    //flag for overflow mode
#define TIFR_OCF0                      1    //flag for output compare (CTC)

#define TIFR_TOV2                      6    //flag for overflow mode FOR TIMER 2
#define TIFR_OCF2                      7    //flag for output compare (CTC) FOR TIMER 2

#define TIFR_TOV1                      2
#define TIFR_OCF1B                     3
#define TIFR_OCF1A                     4
#define TIFR_ICF1                      5


#define SFIOR                  *((volatile u8 *)0x50)

#define SFIOR_PSR2                     1               //CLEAR PRESCALER WHEN WRITTEN 1



#define ASSR                *((volatile u8 *)0x42)
        
#define ASSR_TCR2UB                   0
#define ASSR_OCR2UB                   1
#define ASSR_TCN2UB                   2
#define ASSR_AS2                      3


#define TCCR1A          *((volatile u8 *)0x4F)

#define TCCR1A_WGM10                 0
#define TCCR1A_WGM11                 1
#define TCCR1A_FOC1B                 2
#define TCCR1A_FOC1A                 3
#define TCCR1A_COM1B0                4
#define TCCR1A_COM1B1                5
#define TCCR1A_COM1A0                6
#define TCCR1A_COM1A1                7


#define TCCR1B              *((volatile u8 *)0x4E)

#define TCCR1B_CS10         0
#define TCCR1B_CS11         1
#define TCCR1B_CS12         2
#define TCCR1B_WGM12        3
#define TCCR1B_WGM13        4
#define TCCR1B_ICES1        6               //SELECT ICU SENSE RISING OR FALLIN EDGE
#define TCCR1B_ICNC1        7               //INPUT CAPTURE NOISE CANSELATION

#define TCNT1            *((volatile u16 *)0x4C) 

#define OCR1A              *((volatile u16 *)0x4A)       

#define OCR1B            *((volatile u16 *)0x48)

#define ICR1                *((volatile u16 *)0x46)




#endif