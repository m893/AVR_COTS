/***********
 * Author :   Mohammed Akram 
 * Date  :   30 March,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              30 Marc, 2023               Mohammed Akram
***************************************************************************/
#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

#define LOW_LEVEL                0
#define ANY_LOGICAL_CHANGE       1
#define FALLING_EDGE             2
#define RISING_EDGE              3



#define EXTI_INT0        0
#define EXTI_INT1        1
#define EXTI_INT2        2






void EXTI_VoidIntit( u8 Copy_U8INTNum);
void EXTI_VoidEnable(u8 Copy_U8Intnum);
void EXTI_VoidDisable(u8 Copy_U8Intnum);
void EXTI_VoidTriggerEdge(u8 Copy_U8Intnum , u8 Copy_U8Edge);
void EXTI_VoidINT0SetCallBack(void (*NotificationFunction) (void));
void EXTI_VoidINT1SetCallBack(void (*NotificationFunction) (void));
void EXTI_VoidINT2SetCallBack(void (*NotificationFunction) (void));


#endif