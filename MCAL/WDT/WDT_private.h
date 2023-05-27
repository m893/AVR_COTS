/***********
 * Author :   Mohammed Akram
 * Date  :   12 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              12 April, 2023               Mohammed Akram
***************************************************************************/

#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

//register to control whatchdog timer
#define WDTCR               *((volatile u8 *)0x41)

#define WDTCR_WDP0      0           //WDT PRESCALER AND DETERMINE THE TIME OF SLEEP WHEN ENABLED
#define WDTCR_WDP1      1           //WDT PRESCALER AND DETERMINE THE TIME OF SLEEP WHEN ENABLED
#define WDTCR_WDP2      2           //WDT PRESCALER AND DETERMINE THE TIME OF SLEEP WHEN ENABLED
#define WDTCR_WDE       3           // Watchdog Enable
#define WDTCR_WDTOE     4           //Watchdog TURNOFF


#endif