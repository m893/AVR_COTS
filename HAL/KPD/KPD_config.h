/***********
 * Author :   Mohammed Akram 
 * Date  :   28 March,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              28 Marc, 2023               Mohammed Akram
***************************************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

#define KPD_ROWS_PORT         DIO_PORTD
#define KPD_COLUMNS_PORT      DIO_PORTD


#define KPD_ROW0_PIN       PIN0
#define KPD_ROW1_PIN       PIN1
#define KPD_ROW2_PIN       PIN2
#define KPD_ROW3_PIN       PIN3


#define KPD_COLUMN0_PIN       PIN4
#define KPD_COLUMN1_PIN       PIN5
#define KPD_COLUMN2_PIN       PIN6
#define KPD_COLUMN3_PIN       PIN7

#define KPD_NOT_PRESSED       255

#define  KPD_ARRAY_VALUES    {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}}
#define KPD_ROWS_NUMBER       4
#define KPD_COLUMNS_NUMBER    4




#endif