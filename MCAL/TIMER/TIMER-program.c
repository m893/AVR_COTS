/***********
 * Author :   Mohammed Akram
 * Date  :   10 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              10 April, 2023               Mohammed Akram
***************************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/TIMER/TIMER_interface.h"
#include "../../MCAL/TIMER/TIMER_config.h"
#include "../../MCAL/TIMER/TIMER_private.h"


static void (*Global_pvOVFNotificationFunction)(void) = NULL;
static void (*Global_pvOCNotificationFunction)(void) = NULL;

static void (*ICU_NotificationFunction)(void)=NULL ;
/**********************************************    TIMER 0  ***************************************************************************/
void TIMER0_voidInit(u8 TIMER0_MODE_SELECT  , u8 TIMER0_PRESCALER_SELECT )
{

	switch (TIMER0_MODE_SELECT)
	{
	case TIMER0_NORMAL_MODE :
					/* Set Normal Mode for timer0*/ 
					CLEAR_BIT(TCCR0,TCCR0_WGM00);
					CLEAR_BIT(TCCR0,TCCR0_WGM01);
		break;
		case TIMER0_CTC_MODE :
					/* Set CTC Mode for timer0 */
					CLEAR_BIT(TCCR0,TCCR0_WGM00);
					SET_BIT(TCCR0,TCCR0_WGM01);
		break;
		case TIMER0_FAST_PWM_MODE  :
					/* set fast mode */ 
					SET_BIT(TCCR0,TCCR0_WGM00);
					SET_BIT(TCCR0,TCCR0_WGM01);
		break;
		case TIMER0_PHASE_CORRECT_MODE :
					/* set PHASE CORRECT  mode */ 
					SET_BIT(TCCR0,TCCR0_WGM00);
					CLEAR_BIT(TCCR0,TCCR0_WGM01);
		break;
	default:
				//DO NOTHING
		break;
	}
	/*Set The Prescaler */
		TCCR0 &= PRESCALER_MASK ;
		TCCR0 |= TIMER0_PRESCALER_SELECT ;
}
void TIMER0_VoidSetModeForFastmode(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case FAST_OC0_DISCONNECTED :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		CLEAR_BIT(TCCR0,TCCR0_COM01);
		break;
	case FAST_SET_ON_TOP :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	case FAST_CLEAR_ON_TOP :
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	default:
		break;
	}
}
void TIMER0_VoidSetModeForPhaseCorrectmode(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case PHASE_OC0_DISCONNECTED :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		CLEAR_BIT(TCCR0,TCCR0_COM01);
		break;
	case PHASE_SET_OC0_ON_COMAPRE :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	case PHASE_CLEAR_OC0_ON_COMPARE :
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	default:
		break;
	}
}
void TIMER0_VoidSetOc0ForCtcmode(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case OC0_disconnected :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		CLEAR_BIT(TCCR0,TCCR0_COM01);
		break;
	case Toggle_OC0_on_compare_match :
		SET_BIT(TCCR0,TCCR0_COM00);
		CLEAR_BIT(TCCR0,TCCR0_COM01);
		break;
	case Clear_OC0_on_compare_match :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	case Set_OC0_on_compare_match :
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	default:
		break;
	}

}
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOVFNotificationFunction = pvNotificationFunction;
}
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOCNotificationFunction = pvNotificationFunction;
}

void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode == NORMAL_MODE)
	{
		SET_BIT(TIMSK,TIMSK_TOIE0);
	}
	else if(Copy_u8Mode == CTC_MODE)
	{
		SET_BIT(TIMSK,TIMSK_OCIE0);
	}
}
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode == NORMAL_MODE)
	{
		CLEAR_BIT(TIMSK,TIMSK_TOIE0);
	}
	else if(Copy_u8Mode == CTC_MODE)
	{
		CLEAR_BIT(TIMSK,TIMSK_OCIE0);
	}
}

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time)
{
	/*Set The Prescaler to be 8*/
	CLEAR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLEAR_BIT(TCCR0, TCCR0_CS02);

	TIMER0_voidSetPreloadValue(6);
	u32 Number_of_OVF = ((u32)(Copy_u32Time*1000)) / 250;

	u32 Counter = 0;

	while(Counter < Number_of_OVF)
	{
		while(GET_BIT(TIFR , TIFR_TOV0) == 0);
		SET_BIT(TIFR , TIFR_TOV0);
		Counter++;
		TIMER0_voidSetPreloadValue(6);
	}
}
void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32Time)
{
	/*Set The Prescaler to be 8*/
	CLEAR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLEAR_BIT(TCCR0, TCCR0_CS02);

	TIMER0_voidSetOCMatchValue(250);
	/*You should cast the constants, i.e., 1000 and 250 to unsigned long (u32) and compute the multiplication operation first before the division */
	//u32 Number_of_OCFlags = ((u32)(Copy_u32Time*1000)) / 250;
	u32 Number_Of_OCF = ((u32)Copy_u32Time * 1000UL) / 250UL;

	u32 Local_u32Counter = 0;

	while(Local_u32Counter <= Number_Of_OCF)
	{
		while(GET_BIT(TIFR , TIFR_OCF0) == 0);
		SET_BIT(TIFR , TIFR_OCF0);
		Local_u32Counter++;
	}
}

/*********************************************	TIMER 1 **************************************************************************************/


void TIMER1_VoidInit(u8 Copy_u8Mode , u8 Copy_u8Prescaler)
{
	switch (Copy_u8Mode)
	{
		case TIMER1_Normal_MODE:
			CLEAR_BIT(TCCR1A ,TCCR1A_WGM10);
			CLEAR_BIT(TCCR1A ,TCCR1A_WGM11);
			CLEAR_BIT(TCCR1B , TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B ,TCCR1B_WGM13);
		break;
		case TIMER1_PHASE_CORRECT_8_BIT:
			SET_BIT(TCCR1A ,TCCR1A_WGM10);
			CLEAR_BIT(TCCR1A ,TCCR1A_WGM11);
			CLEAR_BIT(TCCR1B , TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B ,TCCR1B_WGM13);
		break;
		case TIMER1_PHASE_CORRECT_9_BIT:
			CLEAR_BIT(TCCR1A ,TCCR1A_WGM10);
			SET_BIT(TCCR1A ,TCCR1A_WGM11);
			CLEAR_BIT(TCCR1B , TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B ,TCCR1B_WGM13);
		break;
		case TIMER1_PHASE_CORRECT_10_BIT:
			SET_BIT(TCCR1A ,TCCR1A_WGM10);
			SET_BIT(TCCR1A ,TCCR1A_WGM11);
			CLEAR_BIT(TCCR1B , TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B ,TCCR1B_WGM13);
		break;
		case TIMER1_CTC:
			CLEAR_BIT(TCCR1A ,TCCR1A_WGM10);
			CLEAR_BIT(TCCR1A ,TCCR1A_WGM11);
			SET_BIT(TCCR1B , TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B ,TCCR1B_WGM13);
		break;
		case TIMER1_FAST_MODE_8_BIT:
			SET_BIT(TCCR1A ,TCCR1A_WGM10);
			CLEAR_BIT(TCCR1A ,TCCR1A_WGM11);
			SET_BIT(TCCR1B , TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B ,TCCR1B_WGM13);
		break;
		case TIMER1_FAST_MODE_9_BIT:
			CLEAR_BIT(TCCR1A ,TCCR1A_WGM10);
			SET_BIT(TCCR1A ,TCCR1A_WGM11);
			SET_BIT(TCCR1B , TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B ,TCCR1B_WGM13);
		break;
		case TIMER1_FAST_MODE_10_BIT:
			SET_BIT(TCCR1A ,TCCR1A_WGM10);
			SET_BIT(TCCR1A ,TCCR1A_WGM11);
			SET_BIT(TCCR1B , TCCR1B_WGM12);
			CLEAR_BIT(TCCR1B ,TCCR1B_WGM13);
		break;
		case TIMER1_FAST_PWM:
			CLEAR_BIT(TCCR1A ,TCCR1A_WGM10);
			SET_BIT(TCCR1A ,TCCR1A_WGM11);
			SET_BIT(TCCR1B , TCCR1B_WGM12);
			SET_BIT(TCCR1B ,TCCR1B_WGM13);
		break;

	
	default:
		break;
	}

	TCCR1B &= PRESCALER_MASK ;
	TCCR1B |= Copy_u8Prescaler ;

}
void TIMER0_VoidSetModeForFastmodeChannelA(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case FAST_OC1A_DISCONNECTED :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	case FAST_SET_ON_TOP :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	case FAST_CLEAR_ON_TOP :
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	default:
		break;
	}
}
void TIMER0_VoidSetModeForFastmodeChannelB(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case FAST_OC1B_DISCONNECTED :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	case FAST_SET_ON_TOP :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	case FAST_CLEAR_ON_TOP :
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	default:
		break;
	}
}
void TIMER1_VoidSetModeForPhaseCorrectChannelA(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case PHASE_OC1A_DISCONNECTED :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	case PHASE_SET_OC1A_ON_COMAPRE :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	case PHASE_CLEAR_OC1B_ON_COMPARE :
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	default:
		break;
	}
}
void TIMER1_VoidSetModeForPhaseCorrectChannelB(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case PHASE_OC1B_DISCONNECTED :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	case PHASE_SET_OC1B_ON_COMAPRE :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	case PHASE_CLEAR_OC1B_ON_COMPARE :
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	default:
		break;
	}
}
void TIMER1_VoidSetOc1AForCtcmode(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case OC1A_disconnected :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	case Toggle_OC1A_on_compare_match :
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	case Clear_OC1A_on_compare_match :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	case Set_OC1A_on_compare_match :
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		break;
	default:
		break;
	}

}
void TIMER1_VoidSetOc1BForCtcmode(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case OC1B_disconnected :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	case Toggle_OC1B_on_compare_match :
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	case Clear_OC1B_on_compare_match :
		CLEAR_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	case Set_OC1B_on_compare_match :
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	default:
		break;
	}

}
void TIMER1_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT1 = Copy_u8Value;
}
void TIMER0_voidSetOCMatchValueChannelA(u8 Copy_u8Value)
{
	OCR1A = Copy_u8Value;
}
void TIMER0_voidSetOCMatchValueChannelB(u8 Copy_u8Value)
{
	OCR1B = Copy_u8Value;
}
void TIMER1_VoidEnableCopmareMatchValueInterruptChannelA(void)
{
	SET_BIT(TIMSK , TIMSK_OCIE1A);
}
void TIMER1_VoidDisableCopmareMatchValueInterruptChannelA(void)
{
	CLEAR_BIT(TIMSK , TIMSK_OCIE1A);
}
void TIMER1_VoidEnableCopmareMatchValueInterruptChannelB(void)
{
	SET_BIT(TIMSK , TIMSK_OCIE1B);
}
void TIMER1_VoidDisableCopmareMatchValueInterruptChannelB(void)
{
	CLEAR_BIT(TIMSK , TIMSK_OCIE1B);
}
void TIMER1_VoidEnableOverflowInterrupt(void)
{	
	SET_BIT(TIMSK , TIMSK_TOIE1);
}
void TIMER1_VoiddDisableOverflowInterrupt(void)
{	
	CLEAR_BIT(TIMSK , TIMSK_TOIE1);
}


/***************************************	TIMER2	**************************************/

void TIMER2_voidInit(void)
{
		/* Set Normal Mode for timer2*/ 
	#if TIMER2_MODE == NORMAL_MODE
		CLEAR_BIT(TCCR2,TCCR2_WGM20);
		CLEAR_BIT(TCCR2,TCCR2_WGM21);
		/* Set CTC Mode for timer0 2*/
	#elif TIMER2_MODE == CTC_MODE
			CLEAR_BIT(TCCR2,TCCR2_WGM20);
			SET_BIT(TCCR2,TCCR2_WGM21);
			/* set fast mode FOR TIMER 2*/
	#elif TIMER2_MODE == FAST_PWM_MODE
            SET_BIT(TCCR2,TCCR2_WGM20);
			SET_BIT(TCCR2,TCCR2_WGM21); 
			/* set PHASE CORRECT  mode  FOR TIMER 2*/      
	#elif TIMER2_MODE == PHASE_CORRECT_MODE
			SET_BIT(TCCR2,TCCR2_WGM20);
			CLEAR_BIT(TCCR2,TCCR2_WGM21);
	#else

	#endif

	/*Set The Prescaler to be 8*/
		TCCR2 &= PRESCALER_MASK ;
		TCCR2 |= TIMER2_PRESCALER ;

}




void TIMER2_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT2 = Copy_u8Value ;
}
void TIMER2_voidSetOCMatchValue(u8 Copy_u8Value)
{
	OCR2 = Copy_u8Value;
}



u16 ICU_U16GetICRRegister(void)
{
	return ICR1 ;
}
void ICU_VoidSetTriggerSignal( u8 Copy_u8TriggerSignal)
{
	switch (Copy_u8TriggerSignal)
	{
	case  ICU_FALLING_EDGE :
				//SET BIT TO MAKE SENSE OF ICU IS FALLING
				CLEAR_BIT(TCCR1B,TCCR1B_ICES1);
		break;
		case  ICU_RISING_EDGE :
				//SET BIT TO MAKE SENSE OF ICU IS RISING
				SET_BIT(TCCR1B,TCCR1B_ICES1);
		break;
	
	default:
		break;
	}
}
void ICU_VoidEnableIntrrupt(u8 Copu_U8InterruptStatus)
{
	switch (Copu_U8InterruptStatus)
	{
	case  ICU_INTERRUPT_ENABLE :
				SET_BIT(TIMSK,TIMSK_TICIE1);
		break;
		case  ICU_INTERRUPT_DISABLE :
				CLEAR_BIT(TIMSK,TIMSK_TICIE1);
		break;
	
	default:
		break;
	}
}
void ICU_VoidSetCallBack(void (*notification)(void))
{
	
	ICU_NotificationFunction=notification;
}
//ISR FOR ICU INTERRUPT FLAG 

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if (ICU_NotificationFunction != NULL)
	{
		ICU_NotificationFunction();
	}
	else
	{
		//do nothing
	}
	
}
