/***********
 * Author :   Mohammed Akram 
 * Date  :   22 March,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              22 Marc, 2023               Mohammed Akram
***************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PIN0    0       
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define LOW     0
#define HIGH    1

#define OUTPUT  1
#define INPUT   0

#define PULLUP          1
#define NO_PULLUP       0

void 	DIO_voidSetPinDirection(u8 Copy_U8PortNmame , u8 Copy_u8PinNumber , u8 Copy_u8Direction);
void DIO_VoidSetPinValue(u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_U8PinState);
u8  DIO_VoidGetPinValue(u8 Copy_u8PortName , u8 Copy_u8PinNumber);
void DIO_VoidSetPortSpecificDirection(u8 Copy_U8PortName, u8 Copy_U8SpectificDirection);
u8 DIO_U8GetPortValue(u8 Copy_U8PortName );
void DIO_VoidSetSpacificvalue(u8 Copy_U8PortName , u8 Copy_U8Value);
void DIO_VOidTogglePortValue(u8 Copy_U8PortName);
void DIO_VoidSetPortDirection(u8 Copy_U8PortName , u8  Copy_U8PortState);
void DIO_VoidTogglePinValu(u8 Copy_U8PortName ,u8 Copy_u8PinNumber ) ;
#endif /* DIO_INTERFACE_H_ */
