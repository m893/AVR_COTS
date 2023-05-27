/***********
 * Author :   Mohammed Akram 
 * Date  :   30 March,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              30 Marc, 2023               Mohammed Akram
***************************************************************************/
#include "../../../COTS/LIB/BIT_MATH.h"
#include "../../../COTS/LIB/STD_TYPES.h"

#include "../../../COTS/MCAL/DIO/DIO_interface.h"

#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"


// global pointer to function to take user addresss function 
static void (*EXTI_PVoidINT0NotificationFunction) (void) = NULL ;
static void (*EXTI_PVoidINT1NotificationFunction) (void) = NULL ;
static void (*EXTI_PVoidINT2NotificationFunction) (void) = NULL ;


void EXTI_VoidIntit( u8 Copy_U8INTNum)
{

    switch (Copy_U8INTNum)
    {
    case EXTI_INT0:
            #if INT0_PIN_CONNECTION==INTERNAL_PULLUP
                    DIO_voidSetPinDirection(EXTI0_PORT,EXTI0_PIN,INPUT);
                    DIO_VoidSetPinValue(EXTI0_PORT,EXTI0_PIN,HIGH);
            #elif  INT0_PIN_CONNECTION == EXTERNAL_PULLUP
                 DIO_voidSetPinDirection(EXTI0_PORT,EXTI0_PIN,INPUT);
            #elif INT0_PIN_CONNECTION == EXTERNAL_PULLDOWN
                DIO_voidSetPinDirection(EXTI0_PORT,EXTI0_PIN,INPUT);
            #endif             
        break;
        case EXTI_INT1:
            #if INT0_PIN_CONNECTION==INTERNAL_PULLUP
                    DIO_voidSetPinDirection(EXTI1_PORT,EXTI1_PIN,INPUT);
                    DIO_VoidSetPinValue(EXTI1_PORT,EXTI1_PIN,HIGH);
            #elif  INT0_PIN_CONNECTION == EXTERNAL_PULLUP
                 DIO_voidSetPinDirection(EXTI1_PORT,EXTI1_PIN,INPUT);
            #elif INT0_PIN_CONNECTION == EXTERNAL_PULLDOWN
                DIO_voidSetPinDirection(EXTI1_PORT,EXTI1_PIN,INPUT);
            #endif             
        break;
        case EXTI_INT2:
            #if INT0_PIN_CONNECTION==INTERNAL_PULLUP
                    DIO_voidSetPinDirection(EXTI2_PORT,EXTI2_PIN,INPUT);
                    DIO_VoidSetPinValue(EXTI2_PORT,EXTI2_PIN,HIGH);
            #elif  INT0_PIN_CONNECTION == EXTERNAL_PULLUP
                 DIO_voidSetPinDirection(EXTI2_PORT,EXTI2_PIN,INPUT);
            #elif INT0_PIN_CONNECTION == EXTERNAL_PULLDOWN
                DIO_voidSetPinDirection(EXTI2_PORT,EXTI2_PIN,INPUT);
            #endif             
        break;
    
    default:
        break;
    }
}

void EXTI_VoidEnable(u8 Copy_U8Intnum)
{
    switch (Copy_U8Intnum)
    {
    case  EXTI_INT0  :
            SET_BIT(GICR,INT0);
        break;
        case  EXTI_INT1:
            SET_BIT(GICR,INT1);
        break;
        case  EXTI_INT2 :
            SET_BIT(GICR,INT2);
        break;
    
    default:
        break;
    }
}
void EXTI_VoidDisable(u8 Copy_U8Intnum)
{
    switch (Copy_U8Intnum)
    {
    case  EXTI_INT0:
            CLEAR_BIT(GICR,INT0);
        break;
        case  EXTI_INT1:
            CLEAR_BIT(GICR,INT1);
        break;
        case  EXTI_INT2:
            CLEAR_BIT(GICR,INT2);
        break;
    
    default:
        break;
    }

}
void EXTI_VoidTriggerEdge(u8 Copy_U8Intnum , u8 Copy_U8Edge)
{

    switch (Copy_U8Intnum)
    {
    case  EXTI_INT0:
                switch (Copy_U8Edge)
                {
                     case  LOW_LEVEL:
                        CLEAR_BIT(MCUCR,ISC00);
                        CLEAR_BIT(MCUCR,ISC01);
                         break;
                    case  ANY_LOGICAL_CHANGE :
                        SET_BIT(MCUCR,ISC00);
                        CLEAR_BIT(MCUCR,ISC01);
                         break;
                     case  FALLING_EDGE :
                        CLEAR_BIT(MCUCR,ISC00);
                        SET_BIT(MCUCR,ISC01);
                         break;
                    case  RISING_EDGE :
                        SET_BIT(MCUCR,ISC00);
                        SET_BIT(MCUCR,ISC01);
                         break;
                
                     default:
                         break;
                }
        break;
        case  EXTI_INT1:
                switch (Copy_U8Edge)
                {
                     case  LOW_LEVEL:
                        CLEAR_BIT(MCUCR,ISC10);
                        CLEAR_BIT(MCUCR,ISC11);
                         break;
                    case  ANY_LOGICAL_CHANGE :
                        SET_BIT(MCUCR,ISC10);
                        CLEAR_BIT(MCUCR,ISC11);
                         break;
                     case  FALLING_EDGE :
                        CLEAR_BIT(MCUCR,ISC10);
                        SET_BIT(MCUCR,ISC11);
                         break;
                    case  RISING_EDGE :
                        SET_BIT(MCUCR,ISC10);
                        SET_BIT(MCUCR,ISC11);
                         break;
                
                     default:
                         break;
                }
        break;
        case  EXTI_INT2:
                switch (Copy_U8Edge)
                {
            
                     case  FALLING_EDGE :
                        CLEAR_BIT(MCUCSR,ISC2);
                        
                         break;
                    case  RISING_EDGE :
                        SET_BIT(MCUCSR,ISC2);
                         break;
                
                     default:
                            CLEAR_BIT(MCUCSR,ISC2);
                         break;
                }
            break;
    
        default:
        break;
    }
}

//function to take adress of user function  for EXTI0
void EXTI_VoidINT0SetCallBack(void (*NotificationFunction) (void))
{
    //assing global pointer to function to address that take from user 
    EXTI_PVoidINT0NotificationFunction=NotificationFunction ;
}

//ISR for INT0

/* we can change it wit macro as #define ISR(vector)    \
void __vector_1 (void)  __attribute__ ((signal))\
void __vector_1 (void)         */
//TELL LINKER OPTMIZER that function change within hardware donts delete it  
void __vector_1 (void)  __attribute__ ((signal)) ; 
//function implemention that takes global pointer to function and execute it  
// we can make macro to #define EXTI0_vector    __vector_1
void __vector_1 (void)
{   
     /*check if user didnot write function for interrupt if no ISR FOR INTERRUPT 
     THEN INTERRUPT WILL GO TO 0 ADDRESS AND RESTART THE PROGRAM SO WE CHECK FIRST*/
    if (EXTI_PVoidINT0NotificationFunction != NULL)
    {
        //execute function
        EXTI_PVoidINT0NotificationFunction();
    }
    
    
}

//function to take adress of user function  for EXTI1
void EXTI_VoidINT1SetCallBack(void (*NotificationFunction) (void))
{
    //assing global pointer to function to address that take from user
    EXTI_PVoidINT1NotificationFunction=NotificationFunction ;
}
//ISR for INT1
//TELL LINKER OPTMIZER that function change within hardware donts delete it
void __vector_2(void) __attribute__((signal));
//function implemention that takes global pointer to function and execute it 
void __vector_2(void)
{
    /*check if user didnot write function for interrupt if no ISR FOR INTERRUPT 
     THEN INTERRUPT WILL GO TO 0 ADDRESS AND RESTART THE PROGRAM SO WE CHECK FIRST*/
    if (EXTI_PVoidINT1NotificationFunction != NULL)
    {
        //execute function
        EXTI_PVoidINT1NotificationFunction();
    }
}

void EXTI_VoidINT2SetCallBack (void (*NotificationFunction) (void))
{
    EXTI_PVoidINT2NotificationFunction=NotificationFunction;
}

void __vector_3 (void) __attribute__ ((signal));
void __vector_3 (void)
{
   /*check if user didnot write function for interrupt if no ISR FOR INTERRUPT 
     THEN INTERRUPT WILL GO TO 0 ADDRESS AND RESTART THE PROGRAM SO WE CHECK FIRST*/
    if (EXTI_PVoidINT2NotificationFunction != NULL)
    {
        //execute function
        EXTI_PVoidINT2NotificationFunction();
    }
}
