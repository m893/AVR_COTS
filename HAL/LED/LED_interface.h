/***********
 * Author :   Mohammed Akram 
 * Date  :   28 March,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              28 Marc, 2023               Mohammed Akram
***************************************************************************/
#ifndef  LED_INTERFACE_H
#define LED_INTERFACE_H

typedef struct 
{
    u8 Copy_U8led_Port ;
    u8 Copy_U8Led_Pin ;
} led_t;


void LED_VoidInit(led_t * ledobj);
void LED_VoidTurnOn(led_t * ledobj);
void LED_VoidTurnOff(led_t * ledobj);
void LED_VoidToggleLed(led_t * ledobj);



#endif