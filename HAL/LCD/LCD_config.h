#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H



/*
 * Options:
 * 		FOUR_BIT_MODE
 * 		EIGHT_BIT_MODE
 */
#define LCD_MODE		  EIGHT_BIT_MODE




#if (LCD_MODE == EIGHT_BIT_MODE)
/*
 * Options:
 * 		DIO_PORTA
 * 		DIO_PORTB
 * 		DIO_PORTC
 * 		DIO_PORTD
 */
#define LCD_DATA_PORT     DIO_PORTC
#define LCD_CONTROL_PORT  DIO_PORTD

/*
 * Options:
 * 		PIN0
 * 		PIN1
 * 		PIN2
 * 		PIN3
 * 		PIN4
 * 		PIN5
 * 		PIN6
 * 		PIN7
 */
#define RS                PIN0
#define RW                PIN1
#define EN                PIN2

#define D0                PIN0
#define D1                PIN1
#define D2                PIN2
#define D3                PIN3
#define D4                PIN4
#define D5                PIN5
#define D6                PIN6
#define D7                PIN7

#elif (LCD_MODE == FOUR_BIT_MODE)

/*
 * Options:
 * 		DIO_PORTA
 * 		DIO_PORTB
 * 		DIO_PORTC
 * 		DIO_PORTD
 */
#define LCD_DATA_PORT     DIO_PORTC
#define LCD_CONTROL_PORT  DIO_PORTD

/*
 * Options:
 * 		PIN0
 * 		PIN1
 * 		PIN2
 * 		PIN3
 * 		PIN4
 * 		PIN5
 * 		PIN6
 * 		PIN7
 */
#define RS                PIN0
#define RW                PIN1
#define EN                PIN2

#define D4                PIN0
#define D5                PIN1
#define D6                PIN2
#define D7                PIN3

#else

#error ("LCD Mode Error Configurations")

#endif







#endif
