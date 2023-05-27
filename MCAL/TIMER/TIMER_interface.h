/***********
 * Author :   Mohammed Akram
 * Date  :   10 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              10 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/**************************************************   TIMER0   *****************************************************************/

#define   TIMER0_NORMAL_MODE                            0            
#define   TIMER0_CTC_MODE                               1     
#define   TIMER0_FAST_PWM_MODE                          2    
#define   TIMER0_PHASE_CORRECT_MODE                     3


#define   TIMER0_PRESCALER_TIMER_STOP                    0
#define   TIMER0_PRESCALER_1                             1
#define   TIMER0_PRESCALER_8                             2
#define   TIMER0_PRESCALER_64                            3
#define   TIMER0_PRESCALER_256                           4
#define   TIMER0_PRESCALER_1024                          5
#define   TIMER0_COUNTER_WITH_FALLING                    6            
#define   TIMER0_COUNTER_WITH_RISSING                    7


#define   OC0_disconnected                               0
#define   Toggle_OC0_on_compare_match                    1
#define   Clear_OC0_on_compare_match                     2
#define   Set_OC0_on_compare_match                       3

#define   FAST_OC0_DISCONNECTED                          0
#define   FAST_SET_ON_TOP                                1
#define   FAST_CLEAR_ON_TOP                              2


#define   PHASE_OC0_DISCONNECTED                         0
#define   PHASE_SET_OC0_ON_COMAPRE                       1
#define   PHASE_CLEAR_OC0_ON_COMPARE                     2

/**************************************************   TIMER 1    ******************************************************************/
    
/*
    mode Options :
*/

#define    TIMER1_Normal_MODE           0
#define    TIMER1_PHASE_CORRECT_8_BIT   1
#define    TIMER1_PHASE_CORRECT_9_BIT   2
#define    TIMER1_PHASE_CORRECT_10_BIT  3
#define    TIMER1_CTC                   4
#define    TIMER1_FAST_MODE_8_BIT       5
#define    TIMER1_FAST_MODE_9_BIT       6
#define    TIMER1_FAST_MODE_10_BIT      7
#define    TIMER1_FAST_PWM              14  //ICR1  IS THE TOP 

/*
    PRESCALER OPTIONS :
*/
#define   TIMER1_PRESCALER_TIMER_STOP                    0
#define   TIMER1_PRESCALER_1                             1
#define   TIMER1_PRESCALER_8                             2
#define   TIMER1_PRESCALER_64                            3
#define   TIMER1_PRESCALER_256                           4
#define   TIMER1_PRESCALER_1024                          5
#define   TIMER1_COUNTER_WITH_FALLING                    6            
#define   TIMER1_COUNTER_WITH_RISSING                    7

/*
    options :
*/
#define   FAST_OC1A_DISCONNECTED                          0
#define   FAST_OC1B_DISCONNECTED                          0
#define   PHASE_OC1A_DISCONNECTED                         0
#define   PHASE_OC1B_DISCONNECTED                         0

/*      
        OPTIONS :
*/
#define   PHASE_SET_OC1A_ON_COMAPRE                       1
#define   PHASE_CLEAR_OC1A_ON_COMPARE                     2
#define   PHASE_SET_OC1B_ON_COMAPRE                       1
#define   PHASE_CLEAR_OC1B_ON_COMPARE                     2
/*
    OPTIONS:
*/
#define   OC1A_disconnected                               0
#define   Toggle_OC1A_on_compare_match                    1
#define   Clear_OC1A_on_compare_match                     2
#define   Set_OC1A_on_compare_match                       3

#define   OC1B_disconnected                               0
#define   Toggle_OC1B_on_compare_match                    1
#define   Clear_OC1B_on_compare_match                     2
#define   Set_OC1B_on_compare_match                       3


#define NORMAL_MODE           0
#define CTC_MODE              1
#define FAST_PWM_MODE         2
#define PHASE_CORRECT_MODE    3

#define ICU_FALLING_EDGE       1
#define ICU_RISING_EDGE        0

#define ICU_INTERRUPT_ENABLE   1
#define ICU_INTERRUPT_DISABLE   0






void TIMER0_voidInit(u8 TIMER0_MODE_SELECT  , u8 TIMER0_PRESCALER_SELECT );

void TIMER2_voidInit(void);


void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value);

void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void));
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void));

void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode);

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time);
void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32Time);


#endif