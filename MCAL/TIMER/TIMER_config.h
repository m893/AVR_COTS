/***********
 * Author :   Mohammed Akram
 * Date  :   10 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              10 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H






/*
    OPTIONS: TIMER 2
                NORMAL_MODE           
                CTC_MODE              
                FAST_PWM_MODE         
                PHASE_CORRECT_MODE
*/
#define     TIMER2_MODE      NORMAL_MODE

/*
    *OPTIONS FOR TIMER 0
 PRESCALER_TIMER_STOP      0
 PRESCALER_1               1
 PRESCALER_8               2
 PRESCALER_64              3
 PRESCALER_256             4
 PRESCALER_1024            5
 COUNTER_WITH_FALLING      6            
 COUNTER_WITH_RISSING      7
*/

#define TIMER0_PRESCALER       PRESCALER_8

/*
    *OPTIONS FOR TIMER 2
 PRESCALER_TIMER_STOP      0
 PRESCALER_1               1
 PRESCALER_8               2
 PRESCALER_64              3
 PRESCALER_256             4
 PRESCALER_1024            5
 COUNTER_WITH_FALLING      6            
 COUNTER_WITH_RISSING      7
*/

#define TIMER2_PRESCALER       PRESCALER_8








#endif

