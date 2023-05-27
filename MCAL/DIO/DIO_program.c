/***********
 * Author :   Mohammed Akram 
 * Date  :   22 March,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              22 Marc, 2023               Mohammed Akram
***************************************************************************/
/*Library Inclusions*/
#include "../../../COTS/LIB/STD_TYPES.h"
#include "../../../COTS/LIB/BIT_MATH.h"
/*lower layer Inclusion  if iam in  HAL  include MCAL*/
/*Self files INclusions in the same sequence  */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
void 	DIO_voidSetPinDirection(u8 Copy_U8PortNmame , u8 Copy_u8PinNumber , u8 Copy_u8Direction)
{
	switch (Copy_U8PortNmame)
	{
		case DIO_PORTA:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRA , Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLEAR_BIT(DDRA , Copy_u8PinNumber);
			}
			else 
			{
				// no thing
			}
		break;
		case DIO_PORTB:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRB , Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLEAR_BIT(DDRB , Copy_u8PinNumber);
			}
			else 
			{
				// no thing
			}
		break;
		case DIO_PORTC:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRC , Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLEAR_BIT(DDRC , Copy_u8PinNumber);
			}
			else 
			{
				// no thing
			}
		break;
		case DIO_PORTD:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRD , Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLEAR_BIT(DDRD , Copy_u8PinNumber);
			}
			else 
			{
				// no thing
			}
		break;
	
	default:
			//do no thing 
		break;
	}
}

void DIO_VoidSetPinValue(u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_U8PinState)
{
	switch (Copy_u8PortNumber)
	{
		case DIO_PORTA :
			switch(Copy_U8PinState)
			{
				case LOW :
					CLEAR_BIT(PORTA , Copy_u8PinNumber );
				break;
				case HIGH :
					SET_BIT(PORTA , Copy_u8PinNumber );
				break;
			}
		break;
		case DIO_PORTB :
			switch(Copy_U8PinState)
			{
				case LOW :
					CLEAR_BIT(PORTB , Copy_u8PinNumber );
				break;
				case HIGH :
					SET_BIT(PORTB , Copy_u8PinNumber );
				break;
			}
		break;
		case DIO_PORTC :
			switch(Copy_U8PinState)
			{
				case LOW :
					CLEAR_BIT(PORTC , Copy_u8PinNumber );
				break;
				case HIGH :
					SET_BIT(PORTC , Copy_u8PinNumber );
				break;
			}
		break;
		case DIO_PORTD :
			switch(Copy_U8PinState)
			{
				case LOW :
					CLEAR_BIT(PORTD , Copy_u8PinNumber );
				break;
				case HIGH :
					SET_BIT(PORTD , Copy_u8PinNumber );
				break;
			}
		break;
	
	default:
			// Do nothing 
		break;
	}
}

u8  DIO_VoidGetPinValue(u8 Copy_u8PortName , u8 Copy_u8PinNumber)
{
	u8 Local_u8PinValue =0 ;
	switch (Copy_u8PortName)
	{
		case DIO_PORTA :
			Local_u8PinValue=GET_BIT(PORTA,Copy_u8PinNumber);
		break;
		case DIO_PORTB :
			Local_u8PinValue=GET_BIT(PORTB,Copy_u8PinNumber);
		break;
		case DIO_PORTC :
			Local_u8PinValue=GET_BIT(PORTC,Copy_u8PinNumber);
		break;
		case DIO_PORTD :
			Local_u8PinValue=GET_BIT(PORTD,Copy_u8PinNumber);
		break;
	
		default:
				//Do nothing
			break;
	}
	return Local_u8PinValue;
}
void DIO_VoidSetPortDirection(u8 Copy_U8PortName , u8  Copy_U8PortState)
{
	switch(Copy_U8PortName)
	{
		case DIO_PORTA :
			if(Copy_U8PortState==OUTPUT)
			{
				SET_REG(DDRA);
			}
			else if (Copy_U8PortState==INPUT)
			{
				CLEAR_REG(DDRA);
			}
			else 
			{
				//do no thing
			}
		break;
		case DIO_PORTB :
			if(Copy_U8PortState==OUTPUT)
			{
				SET_REG(DDRB);
			}
			else if (Copy_U8PortState==INPUT)
			{
				CLEAR_REG(DDRB);
			}
			else 
			{
				//do no thing
			}
		break;
		case DIO_PORTC :
			if(Copy_U8PortState==OUTPUT)
			{
				SET_REG(DDRC);
			}
			else if (Copy_U8PortState==INPUT)
			{
				CLEAR_REG(DDRC);
			}
			else 
			{
				//do no thing
			}
		break;
		case DIO_PORTD :
			if(Copy_U8PortState==OUTPUT)
			{
				SET_REG(DDRD);
			}
			else if (Copy_U8PortState==INPUT)
			{
				CLEAR_REG(DDRD);
			}
			else 
			{
				//do no thing
			}
		break;
		default:
			//do no thing
			break;

	}
}
void DIO_VOidTogglePortValue(u8 Copy_U8PortName)
{
	switch(Copy_U8PortName)
	{
		case DIO_PORTA :
			TOGGLE_REG(PORTA);
		break;
		case DIO_PORTB :
			TOGGLE_REG(PORTB);
		break;
		case DIO_PORTC :
			TOGGLE_REG(PORTC);
		break;
		case DIO_PORTD :
			TOGGLE_REG(PORTD);
		break;
		default:
			//do no thing
			break;

	}

}
void DIO_VoidSetSpacificvalue(u8 Copy_U8PortName , u8 Copy_U8Value)
{
	switch(Copy_U8PortName)
	{
		case DIO_PORTA :
			ASSIGN_REG(PORTA,Copy_U8Value);
		break;
		case DIO_PORTB :
			ASSIGN_REG(PORTB,Copy_U8Value);
		break;
		case DIO_PORTC :
			ASSIGN_REG(PORTC,Copy_U8Value);
		break;
		case DIO_PORTD :
			ASSIGN_REG(PORTD,Copy_U8Value);
		break;
		default:
			//do no thing
			break;

	}

}
u8 DIO_U8GetPortValue(u8 Copy_U8PortName )
{
	switch(Copy_U8PortName)
	{
		case DIO_PORTA :
			return PINA;
		break;
		case DIO_PORTB :
			return PINB ;
		break;
		case DIO_PORTC :
			return PINC;
		break;
		case DIO_PORTD :
			return PIND;
		break;
		default:
			//do no thing
			break;

	}

}
void DIO_VoidSetPortSpecificDirection(u8 Copy_U8PortName, u8 Copy_U8SpectificDirection)
{
	switch(Copy_U8PortName)
	{
		case DIO_PORTA :
			ASSIGN_REG(DDRA,Copy_U8SpectificDirection);
		break;
		case DIO_PORTB :
			ASSIGN_REG(DDRB,Copy_U8SpectificDirection);
		break;
		case DIO_PORTC :
			ASSIGN_REG(DDRC,Copy_U8SpectificDirection);
		break;
		case DIO_PORTD :
			ASSIGN_REG(DDRD,Copy_U8SpectificDirection);
		break;
		default:
			//do no thing
			break;

	}

}
void DIO_VoidTogglePinValu(u8 Copy_U8PortName ,u8 Copy_u8PinNumber ) 
{
	switch (Copy_U8PortName)
	{
	case DIO_PORTA:
			TOGGLE_BIT(PORTA ,Copy_u8PinNumber);
		break;
		case DIO_PORTB:
			TOGGLE_BIT(PORTB ,Copy_u8PinNumber);
		break;
		case DIO_PORTC:
			TOGGLE_BIT(PORTC ,Copy_u8PinNumber);
		break;
		case DIO_PORTD:
			TOGGLE_BIT(PORTD ,Copy_u8PinNumber);
		break;
	
	default:
		break;
	}
}

