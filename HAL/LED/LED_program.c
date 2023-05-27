/***********
 * Author :   Mohammed Akram 
 * Date  :   28 March,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              28 Marc, 2023               Mohammed Akram
***************************************************************************/



#include "../../../COTS/LIB/BIT_MATH.h"
#include "../../../COTS/LIB/STD_TYPES.h"

#include "../../../COTS/MCAL/DIO/DIO_interface.h"   


#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void LED_VoidInit(led_t * ledobj)
{
    DIO_voidSetPinDirection(ledobj->Copy_U8led_Port,ledobj->Copy_U8Led_Pin,OUTPUT);
}
void LED_VoidTurnOn(led_t * ledobj)
{
    DIO_VoidSetPinValue(ledobj->Copy_U8led_Port,ledobj->Copy_U8Led_Pin,HIGH);
}
void LED_VoidTurnOff(led_t * ledobj)
{
    DIO_VoidSetPinValue(ledobj->Copy_U8led_Port,ledobj->Copy_U8Led_Pin,LOW);
}
void LED_VoidToggleLed(led_t * ledobj)
{
    DIO_VoidTogglePinValu(ledobj->Copy_U8led_Port,ledobj->Copy_U8Led_Pin);
}
