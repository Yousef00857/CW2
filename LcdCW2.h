/*----------------------------------------------------------------*/
/*--------------------------LcdCW2.h------------------------------*/
/*----------------------------------------------------------------*/
#ifndef _LCD_
#define _LCD_

void LCD_Command(unsigned char cmd);
void LCD_Char(unsigned char char_data);
void LCD_Init(void);
void LCD_String(char *str);
void LCD_String_xy(char row, char pos, char *str);
void LCD_Clear(void);
void LCD_Display(unsigned int LL, unsigned int LH, unsigned int Sensor);

#endif
/*----------------------------------------------------------------*/
/*--------------------------LcdCW2.h------------------------------*/
/*----------------------------------------------------------------*/
