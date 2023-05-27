/***********
 * Author :   Mohammed Akram 
 * Date  :   29 March,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              29 Marc, 2023               Mohammed Akram
***************************************************************************/

#include "../../../COTS/LIB/STD_TYPES.h"
#include "../../../COTS/LIB/BIT_MATH.h"


#include "GIE_interface.h"
#include "GIE_private.h"

void GIE_VoidEnabledGlobalInterrupt(void)
{
    SET_BIT(SREG , SREG_BIT7);


}
void GIE_VoidDisabledGlobalInterrupt(void)
{
    CLEAR_BIT(SREG , SREG_BIT7);


}