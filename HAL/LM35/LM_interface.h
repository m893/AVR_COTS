#ifndef LM_INTERFACE_H
#define LM_INTERFACE_H



typedef struct 
{
    u8 Lm_Port ;
    u8 Lm_pin ;

}Lm_t;


void LM_VoidInit(Lm_t * lm_obj);

u8 Lm_U8ReturnTemperture(Lm_t * lm_obj);

#endif

