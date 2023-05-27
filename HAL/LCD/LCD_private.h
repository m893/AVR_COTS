#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define FOUR_BIT_MODE       0
#define EIGHT_BIT_MODE      1

#define FUNCTION_SET_CMD    0x3c
#define FUNCTION_ON_OFF_CMD 0x0c
#define DISPLAY_CLEAR_CMD   0x01
#define ROW1_OFFSET 		0x40
#define ROW1_CMD 			0x80



#define POSITIVE 0
#define NEGATIVE 1

static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif
