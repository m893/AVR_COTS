#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


void LCD_voidInit(void)
{

#if(LCD_MODE == EIGHT_BIT_MODE)
    //Initialize Data Port
    DIO_VoidSetPortDirection(LCD_DATA_PORT, OUTPUT);
    //Initialize Control Pins
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN, OUTPUT);

    //wait for more than 30ms
    _delay_ms(50);

    //Send Function Set Command
    LCD_voidSendCommand(FUNCTION_SET_CMD);
    //wait for 1ms
    //Send Display ON/ OFF Control Command
    LCD_voidSendCommand(FUNCTION_ON_OFF_CMD);

    //Send Clear Command
    LCD_voidSendCommand(DISPLAY_CLEAR_CMD);

#elif (LCD_MODE == FOUR_BIT_MODE)
    //initialize Data Pins
    DIO_voidSetPinDirection(LCD_DATA_PORT, D4, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, D5, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, D6, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, D7, OUTPUT);
    //Initialize Control Pins
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN, OUTPUT);

	//wait for more than 30ms
	_delay_ms(50);





#endif
}


void LCD_voidSendData(u8 Copy_u8Data)
{
    //SET RS Pin To Send Command (RS -> 0: Command, 1: Data)
    DIO_VoidSetPinValue(LCD_CONTROL_PORT, RS, HIGH);
    //Clear RW Pin To Write The Command (RW -> 0: Write, 1: Read)
    DIO_VoidSetPinValue(LCD_CONTROL_PORT, RW, LOW);

    //Set The Command On The Data/Command Port
    DIO_VoidSetSpacificvalue(LCD_DATA_PORT, Copy_u8Data);

    //Send Enable Pulse
    //LOW
    DIO_VoidSetPinValue(LCD_CONTROL_PORT, EN, LOW);
    //HIGH
    DIO_VoidSetPinValue(LCD_CONTROL_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_VoidSetPinValue(LCD_CONTROL_PORT, EN, LOW);

}


static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    //Clear RS Pin To Send Command (RS -> 0: Command, 1: Data)
	DIO_VoidSetPinValue(LCD_CONTROL_PORT, RS, LOW);
    //Clear RW Pin To Write The Command (RW -> 0: Write, 1: Read)
	DIO_VoidSetPinValue(LCD_CONTROL_PORT, RW, LOW);

    //Set The Command On The Data/Command Port
    DIO_VoidSetSpacificvalue(LCD_DATA_PORT, Copy_u8Command);

    //Send Enable Pulse
    //LOW
    DIO_VoidSetPinValue(LCD_CONTROL_PORT, EN, LOW);
    //HIGH
    DIO_VoidSetPinValue(LCD_CONTROL_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_VoidSetPinValue(LCD_CONTROL_PORT, EN, LOW);
}


void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(DISPLAY_CLEAR_CMD);
}


void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CharAddress = 0;
	if(Copy_u8XPos == 0)
	{
		if(Copy_u8YPos < 16)
		{
			//Address = Y-Position
			Local_u8CharAddress = Copy_u8YPos;
		}else{}
	}
	else if(Copy_u8XPos == 1)
	{
		if(Copy_u8YPos < 16)
		{
			Local_u8CharAddress = Copy_u8YPos + ROW1_OFFSET;
		}else{}
	}
	else
	{
		//Raise Error
	}

	Local_u8CharAddress += ROW1_CMD;

	LCD_voidSendCommand(Local_u8CharAddress);

}

void LCD_voidSendString(u8 * Copy_pu8StringArray)
{
	u8 Local_u8LoopCounter = 0;

	while(Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
	{
		LCD_voidSendData(Copy_pu8StringArray[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}


void LCD_voidSendNumber(s32 Copy_s8Number)
{
	s8 Local_u8DigitsDataArray[10] = {0};
	s8 Local_u8LoopCounter = 0;
	u8 Local_u8NumberSign = 0; //0 -> Positive Number, 1 for Negative Number

	if(Copy_s8Number >= 0)
	{
		Local_u8NumberSign = POSITIVE;
	}
	else
	{	//Convert The Number To Positive, and take the sign
		Local_u8NumberSign = NEGATIVE;
		Copy_s8Number--;
		Copy_s8Number = ~Copy_s8Number;
	}

	while(Copy_s8Number != 0)
	{	//Split the Number to digits, Get there ASCII, and store them in array.
		Local_u8DigitsDataArray[Local_u8LoopCounter] = (Copy_s8Number % 10) + '0';
		Copy_s8Number /= 10;
		Local_u8LoopCounter++;
	}

	Local_u8LoopCounter--;

	if(Local_u8NumberSign == NEGATIVE)
	{
		LCD_voidSendData('-');
	}else{}

	while(Local_u8LoopCounter >= 0)
	{
		LCD_voidSendData(Local_u8DigitsDataArray[Local_u8LoopCounter]);
		Local_u8LoopCounter--;
	}
}



void LCD_voidSendCustomCharachter(u8 * Copy_pu8CharArray,
								  u8 Copy_u8PatternNumber,
								  u8 Copy_u8XPos,
								  u8 Copy_u8YPos)
{
	u8 Local_u8LoopCounter = 0;
	u8 Local_u8CGRAMAddress = 0;
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
	SET_BIT(Local_u8CGRAMAddress, 6);

	LCD_voidSendCommand(Local_u8CGRAMAddress);

	for(Local_u8LoopCounter=0; Local_u8LoopCounter<8; Local_u8LoopCounter++)
	{
		LCD_voidSendData(Copy_pu8CharArray[Local_u8LoopCounter]);
	}

	LCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

	LCD_voidSendData(Copy_u8PatternNumber);

}
