#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_NTERRUPT_ENABLE     1
#define ADC_NTERRUPT_DISABLE    0


#define  ADC_CHANEL_0   0b00000000 
#define  ADC_CHANEL_1   0b00000001 
#define  ADC_CHANEL_2   0b00000010 
#define  ADC_CHANEL_3   0b00000011 
#define  ADC_CHANEL_4   0b00000100 
#define  ADC_CHANEL_5   0b00000101 
#define  ADC_CHANEL_6   0b00000110 
#define  ADC_CHANEL_7   0b00000111 


void ADC_VoidInit(void);
void ADC_VoidInterruptControl(u8 Copy_InterruptStatus);
u8 ADC_U8StartConversionSynchronous(u8 Copy_U8ChannelNumber);
void ADC_U8StartConversionAsynchronous(u8 Copy_U8ChannelNumber  ,  void (* Notification ) (void));




#endif