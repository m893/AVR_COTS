#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/DIO/DIO_interface.h"
#include  "../../MCAL/ADC/ADC_interface.h"


#include "LM_interface.h"
#include "LM_config.h"



void LM_VoidInit(Lm_t * lm_obj)
{
    u8 Local_U8Flag =0 ;
    DIO_voidSetPinDirection(lm_obj->Lm_Port,lm_obj->Lm_pin,INPUT);    
    if(Local_U8Flag == 0)
    {
        ADC_VoidInit();
        Local_U8Flag =  1 ;
    }
    else{}

}

u8 Lm_U8ReturnTemperture(Lm_t * lm_obj)
{
    f32 LocalF32temp ;
    u8 LocalU8Temp ;
    u16 ADC_Value = ADC_U16StartConversionSynchronous(lm_obj->Lm_pin);

    f32 volt_value= ((f32)ADC_Value * Reference_volt)/Reslution ;


     LocalF32temp = (f32)volt_value/lm_volt_for_1_temp ;
     if(LocalF32temp - (s32)LocalF32temp >= .5)
     {
        LocalF32temp++;
     }else{}
     
     LocalU8Temp=(u8)LocalF32temp ;

    return LocalU8Temp ;
}
