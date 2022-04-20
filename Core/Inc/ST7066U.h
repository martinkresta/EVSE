#ifndef __ST7066U_h
#define __ST7066U_h

#include "main.h"

#define LCD_Show_String(x,y) LCD_Insert_New_Text((uint8_t*)(x), (y))



void LCD_Init (void);
void LCD_Set_Position (uint8_t row, uint8_t column);
void LCD_Send_Text(uint8_t *data);
void LCD_Refresf_Display(void);
void LCD_Insert_New_Text(uint8_t *data, uint8_t row);

#endif
