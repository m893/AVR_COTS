#ifndef  ADC_CONFIG_H
#define  ADC_CONFIG_H

/*
options:
        AREF
        AVCC
        INTERNAL_2V56 
*/

#define  Reference_Selection    AREF

/* 
    options :
    PRESCALER_DIVIDE_BY_2
    PRESCALER_DIVIDE_BY_4
    PRESCALER_DIVIDE_BY_8
    PRESCALER_DIVIDE_BY_16
    PRESCALER_DIVIDE_BY_32
    PRESCALER_DIVIDE_BY_64
    PRESCALER_DIVIDE_BY_128
    */
#define PRESCALER_SELECTION         PRESCALER_DIVIDE_BY_4


/*
    READ_8_BIT
    RAED_10_BIT
*/

#define RAED_RESULT        READ_8_BIT
 
/* 
options: 
    LEFT_ADJUST
    RIGHT_ADJUST
*/
            
 #define ADC_AJUST_RESULT      LEFT_ADJUST

 /*
    options:
    ENABLE
    DISABLE
 */
#define ADC_ENABLE      ENABLE

/*
    options :
        ADC_INTERRUPT_STATUS ,
        ENABLE
        DISABLE
*/
#define ADC_INTERRUPT_STATUS    ENABLE






#endif