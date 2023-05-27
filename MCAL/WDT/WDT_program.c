/***********
 * Author :   Mohammed Akram
 * Date  :   12 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              12 April, 2023               Mohammed Akram
***************************************************************************/


#include "../../../COTS/LIB/BIT_MATH.h"
#include "../../../COTS/LIB/STD_TYPES.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void  WDT_VoidEnable(void)
{
    //set WDTCR_WDE to enable
    SET_BIT(WDTCR,WDTCR_WDE);
}
 

 void WDT_VoidSleep(u8 Copy_U8sleeptime)
 {
    //mask to clear the first 3 bit
    WDTCR &= 0b11111000 ;
    // or with time user select 
    WDTCR |=Copy_U8sleeptime ;
 }

 void WDT_VoidDisable(void)
 {
    // set bit in  in enable bit and turn off bit in same time and clear WDE 
   WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);
   WDTCR = 0;
 }
