#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*to set 2 bits of refence selection using bit mask*/
#define REFERENCE_SELECTION_MASK        0b00111111
#define AREF                            0b00000000
#define AVCC                            0b01000000
#define INTERNAL_2V56                   0b11000000  

/* to set the selection chanel using the 5 bit of mux */
#define CHANEL_SELECTION_MASK            0b11100000

/*to set the prescalr using 3 bit */
#define PRESCALER_SELECTION_MASK             0B11111000

#define PRESCALER_DIVIDE_BY_2            0b00000000
#define PRESCALER_DIVIDE_BY_4            0b00000010
#define PRESCALER_DIVIDE_BY_8            0b00000011
#define PRESCALER_DIVIDE_BY_16           0b00000100
#define PRESCALER_DIVIDE_BY_32           0b00000101
#define PRESCALER_DIVIDE_BY_64           0b00000110
#define PRESCALER_DIVIDE_BY_128          0b00000111


#define ENABLE    1
#define DISABLE   0

//first register of ADC for select channel ,  select left adjust or right adjust and select 
#define  ADMUX     *((volatile u8 *)0x27)

#define  REFS1  7
#define  REFS0  6
#define  ADLAR  5
#define  MUX4   4   
#define  MUX3   3
#define  MUX2   2
#define  MUX1   1
#define  MUX0   0


//second register of ADC for prescaler , ADC interrupt enable , interrupt flag  ,  auto trrigerd ,  start conversion  and ADC enable 
#define ADCSRA      *((volatile u8 *)0x26)

#define  ADEN       7
#define  ADSC       6
#define  ADATE      5
#define  ADIF       4
#define  ADIE       3
#define  ADPS2      2
#define  ADPS1      1
#define  ADPS0      0



#define ADCH        *((volatile u8 *)0x25)
#define ADCL        *((volatile u8 *)0x24)          
#define ADC         *((volatile u16 *)0x24)         //TO READ THE 10 BIT VALUE




#endif