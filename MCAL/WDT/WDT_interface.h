/***********
 * Author :   Mohammed Akram
 * Date  :   12 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              12 April, 2023               Mohammed Akram
***************************************************************************/

#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#define WDT_TIMER_PRESCELER_16_16MS         0b00000000
#define WDT_TIMER_PRESCELER_32_32MS         0b00000001
#define WDT_TIMER_PRESCELER_64_65MS         0b00000010
#define WDT_TIMER_PRESCELER_128_13S         0b00000011
#define WDT_TIMER_PRESCELER_256_26S         0b00000100
#define WDT_TIMER_PRESCELER_512_52S         0b00000101
#define WDT_TIMER_PRESCELER_1024_1S         0b00000110
#define WDT_TIMER_PRESCELER_2048_2S         0b00000111

void  WDT_VoidEnable(void);
void WDT_VoidSleep(u8 Copy_U8sleeptime);
void WDT_VoidDisable(void);

#endif