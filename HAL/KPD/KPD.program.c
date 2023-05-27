/***********
 * Author :   Mohammed Akram 
 * Date  :   28 March,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              28 Marc, 2023               Mohammed Akram
***************************************************************************/
#include "../../../COTS/LIB/BIT_MATH.h"
#include "../../../COTS/LIB/STD_TYPES.h"


#include "../../../COTS/MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"



void KPD_VoidIntit(void)
{
    //set Rows pins to input pulled up
    DIO_voidSetPinDirection(KPD_ROWS_PORT,KPD_ROW0_PIN,INPUT);
    DIO_voidSetPinDirection(KPD_ROWS_PORT,KPD_ROW1_PIN,INPUT);
    DIO_voidSetPinDirection(KPD_ROWS_PORT,KPD_ROW2_PIN,INPUT);
    DIO_voidSetPinDirection(KPD_ROWS_PORT,KPD_ROW3_PIN,INPUT);
    // PuLLED UP 
    DIO_VoidSetPinValue(KPD_ROWS_PORT,KPD_ROW0_PIN,PULLUP);
    DIO_VoidSetPinValue(KPD_ROWS_PORT,KPD_ROW1_PIN,PULLUP);
    DIO_VoidSetPinValue(KPD_ROWS_PORT,KPD_ROW2_PIN,PULLUP);
    DIO_VoidSetPinValue(KPD_ROWS_PORT,KPD_ROW3_PIN,PULLUP);
    //set cols pins to output high
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT,KPD_COLUMN0_PIN,OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT,KPD_COLUMN1_PIN,OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT,KPD_COLUMN2_PIN,OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT,KPD_COLUMN3_PIN,OUTPUT);
    //SET COLUMNS HIGH
    DIO_VoidSetPinValue(KPD_COLUMNS_PORT,KPD_COLUMN0_PIN,HIGH);
    DIO_VoidSetPinValue(KPD_COLUMNS_PORT,KPD_COLUMN1_PIN,HIGH);
    DIO_VoidSetPinValue(KPD_COLUMNS_PORT,KPD_COLUMN2_PIN,HIGH);
    DIO_VoidSetPinValue(KPD_COLUMNS_PORT,KPD_COLUMN3_PIN,HIGH);


}
                                                 

u8 KPD_U8GetPressedKey(void)
{
    // 2D Array of keypad (rows and colums) 
   static u8 Local_u8KPDArray[KPD_ROWS_NUMBER][KPD_COLUMNS_NUMBER]=KPD_ARRAY_VALUES ;
   //array of colums pins
   static u8 Local_u8Array_of_columns[KPD_COLUMNS_NUMBER]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
   //array of rows pins
   static  u8 Local_U8Array_Of_Rows[KPD_ROWS_NUMBER]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
   //local variable to take the pressed key
    u8 local_u8Key_pressed= KPD_NOT_PRESSED ;
    u8 Local_u8ColumnCounter ;
    u8 Local_u8RowCounter ;
    u8 local_u8RowValue;
    for(Local_u8ColumnCounter=0 ; Local_u8ColumnCounter < KPD_COLUMNS_NUMBER ; Local_u8ColumnCounter++)
    {
        //avtivate column to zero
        DIO_VoidSetPinValue(KPD_COLUMNS_PORT,Local_u8Array_of_columns[Local_u8ColumnCounter],LOW);
        for(Local_u8RowCounter=0 ; Local_u8RowCounter < KPD_ROWS_NUMBER ; Local_u8RowCounter++)
        {
            //search for which key in this row pressed
           local_u8RowValue = DIO_VoidGetPinValue(KPD_ROWS_PORT,Local_U8Array_Of_Rows[Local_u8RowCounter]);
           if(local_u8RowValue== LOW)
           {    
        	   local_u8Key_pressed = Local_u8KPDArray[Local_u8RowCounter][Local_u8ColumnCounter];
                while(local_u8RowValue==LOW)
                {
                    local_u8RowValue = DIO_VoidGetPinValue(KPD_ROWS_PORT,Local_U8Array_Of_Rows[Local_u8RowCounter]);
                }

                return  local_u8Key_pressed ;

           }

        }
        //deactivate column to high
        DIO_VoidSetPinValue(KPD_COLUMNS_PORT,Local_u8Array_of_columns[Local_u8ColumnCounter],HIGH);

    }

    return local_u8Key_pressed ;
}

