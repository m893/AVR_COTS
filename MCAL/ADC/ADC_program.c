#include "../../../COTS/LIB/BIT_MATH.h"
#include "../../../COTS/LIB/STD_TYPES.h"

#include "../../../COTS/MCAL/DIO/DIO_interface.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

static void (*ADC_pvoidNotificationFunction)(void) = NULL;
volatile   u16  ADC_Digital_Value ;

void ADC_VoidInit(void)
{
    // ADC ENABLE BIT 
    #if ADC_ENABLE == ENABLE
        SET_BIT(ADCSRA,ADEN);
    #elif ADC_ENABLE == DISABLE
        CLEAR_BIT(ADCSRA,ADEN);
    #else
        #error "Error, ADC_ENABLE Configuration Error"
    #endif
    //ADC ENABLE interrupt 
    #if ADC_INTERRUPT_STATUS  ==  ENABLE
        SET_BIT(ADCSRA,ADIE);
    #elif ADC_INTERRUPT_STATUS  ==  DISABLE
        CLEAR_BIT(ADCSRA,ADIE);
    #else
        #error "Error, ADC_INTERRUPT_ENABLE Configuration Error"
    #endif
    //
    #if ADC_AJUST_RESULT  ==    LEFT_ADJUST
        SET_BIT(ADMUX,ADLAR);
    #elif ADC_AJUST_RESULT  ==    RIGHT_ADJUST
        CLEAR_BIT(ADMUX,ADLAR);
    #else
        #error "Error, ADC_ADJUST Configuration Error"
    #endif

    //set refereence volt selection
    ADMUX &= REFERENCE_SELECTION_MASK ;
    ADMUX |= Reference_Selection ;
        //set prescaler for adc 
    ADCSRA &= PRESCALER_SELECTION_MASK ;
    ADCSRA |=  PRESCALER_SELECTION ;

}
 void ADC_VoidInterruptControl(u8 Copy_InterruptStatus)
 {
    switch (Copy_InterruptStatus)
    {
    case DISABLE :
            CLEAR_BIT(ADCSRA,ADIE);
        break;
    case ENABLE :
        CLEAR_BIT(ADCSRA,ADIE);
    default:
        break;
    }
 }

 u8 ADC_U8StartConversionSynchronous(u8 Copy_U8ChannelNumber)
 {

   /// VARIABLE TO STORE THE DIGITAL DATA FROM ADC
    u8 Local_U8DigitalValue ;
    //SELECT THE CHANNEL FOR DOING CONVERSION 
    ADMUX &= CHANEL_SELECTION_MASK ;
    ADMUX |= Copy_U8ChannelNumber ;
    //START THE CONVERSION
    SET_BIT(ADCSRA , ADSC);
    //POLLING UNTILL CONVERSION END , PROCESSOR STOP UNTILL CONVERSION END 
    while(GET_BIT(ADCSRA,ADIF) == FALSE);
    //RESET THE ADC FLAG AFTER CONVERSION DONE
    SET_BIT(ADCSRA,ADIF);
    //TO READ VALUE FORM HIG REGISTER OR LOW
    #if ADC_AJUST_RESULT  ==    LEFT_ADJUST
        Local_U8DigitalValue = ADCH ;
    #elif ADC_AJUST_RESULT  ==    RIGHT_ADJUST  
        Local_U8DigitalValue = ADCL;
    #endif
    //RETURN THE DIGITAL VALUE FROM ADC 
    return Local_U8DigitalValue ;

 }
 u16 ADC_U16StartConversionSynchronous(u8 Copy_U8ChannelNumber)
 {

   /// VARIABLE TO STORE THE DIGITAL DATA FROM ADC
    u16 Local_U8DigitalValue ;
    //SELECT THE CHANNEL FOR DOING CONVERSION 
    ADMUX &= CHANEL_SELECTION_MASK ;
    ADMUX |= Copy_U8ChannelNumber ;
    //START THE CONVERSION
    SET_BIT(ADCSRA , ADSC);
    //POLLING UNTILL CONVERSION END , PROCESSOR STOP UNTILL CONVERSION END 
    while(GET_BIT(ADCSRA,ADIF) == FALSE);
    //RESET THE ADC FLAG AFTER CONVERSION DONE
    SET_BIT(ADCSRA,ADIF);
    //TO READ VALUE FORM 16 bit adc register 
    Local_U8DigitalValue=ADC ;
    //RETURN THE DIGITAL VALUE FROM ADC 
    return Local_U8DigitalValue ;

 }
 void ADC_U8StartConversionAsynchronous(u8 Copy_U8ChannelNumber  ,  void (* Notification ) (void))
 {
    //set channel 
    ADMUX &= CHANEL_SELECTION_MASK ;
    ADMUX |= Copy_U8ChannelNumber ;

    ADC_pvoidNotificationFunction = Notification;

    SET_BIT(ADCSRA , ADSC);

 }
 void __vector_16 (void)  __attribute__ ((signal));
 void __vector_16 (void)
{
     ADC_VoidInterruptControl(DISABLE);
    ADC_Digital_Value = ADCH;
    if(ADC_pvoidNotificationFunction != NULL)
    {
        ADC_pvoidNotificationFunction();
    }
    else
    {
        /* Do Nothing*/
    }
    ADC_VoidInterruptControl(ENABLE);

   /* #if  RAED_RESULT    ==    READ_10_BIT 

           ADC_Digital_Value = ADC ;

    #elif RAED_RESULT    ==    READ_8_BIT 
            #if ADC_AJUST_RESULT  ==    LEFT_ADJUST
                        ADC_Digital_Value = ADCH ;
                    #elif ADC_AJUST_RESULT  ==    RIGHT_ADJUST  
                        ADC_Digital_Value = ADCL;
                    
                    #endif

    #endif
    */
}







