/*----------------------------------------------------------------*/
/*--------------------------LcdCW2.ino----------------------------*/
/*----------------------------------------------------------------*/
#include <util/delay.h>
#include <stdio.h>
#include "LcdCW2.h"

#define LCD_DIR DDRD
#define LCD_PORT PORTD
#define RS_EN_DIR DDRD
#define RS_EN_PORT PORTD
#define RS PD0
#define EN PD1

void LCD_Command(unsigned char cmd)
{
  LCD_PORT = (LCD_PORT & 0x0F) | (cmd & 0xF0);
  RS_EN_PORT &= ~(1 << RS);
  RS_EN_PORT |= (1 << EN);
  _delay_us(5);
  RS_EN_PORT &= ~(1 << EN);
  _delay_us(200);

  LCD_PORT = (LCD_PORT & 0x0F) | (cmd << 4);
  RS_EN_PORT |= (1 << EN);
  _delay_us(5);
  RS_EN_PORT &= ~(1 << EN);
  _delay_ms(2);
}

void LCD_Char(unsigned char data)
{
  LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
  RS_EN_PORT |= (1 << RS);
  RS_EN_PORT |= (1 << EN);
  _delay_us(5);
  RS_EN_PORT &= ~(1 << EN);
  _delay_us(200);

  LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
  RS_EN_PORT |= (1 << EN);
  _delay_us(5);
  RS_EN_PORT &= ~(1 << EN);
  _delay_ms(2);
}

void LCD_Init(void)
{
  LCD_DIR = 0xF0;
  LCD_DIR |= (1 << RS) | (1 << EN);
  _delay_ms(20);

  LCD_Command(0x02);
  LCD_Command(0x28);
  LCD_Command(0x0C);
  LCD_Command(0x06);
  LCD_Command(0x01);
  _delay_ms(2);
}

void LCD_String(char *str)
{
  for (int i = 0; str[i]; i++)
    LCD_Char(str[i]);
}

void LCD_String_xy(char row, char pos, char *str)
{
  if (row == 0 && pos < 16)
    LCD_Command((pos & 0x0F) | 0x80);
  else if (row == 1 && pos < 16)
    LCD_Command((pos & 0x0F) | 0xC0);
  LCD_String(str);
}

void LCD_Clear(void)
{
  LCD_Command(0x01);
  _delay_ms(2);
  LCD_Command(0x80);
}

void LCD_Display(unsigned int LL, unsigned int LH, unsigned int Sensor)
{
  char buffer[10];

  // first row: LDR + state
  LCD_String_xy(0, 0, "LDR:");
  sprintf(buffer, "%4u", Sensor);
  LCD_String_xy(0, 5, buffer);

  if (Sensor > LL && Sensor < LH)
    LCD_String_xy(0, 11, "ON ");
  else
    LCD_String_xy(0, 11, "OFF");

  // second row: LL and LH
  LCD_String_xy(1, 0, "LL:");
  sprintf(buffer, "%4u", LL);
  LCD_String_xy(1, 3, buffer);

  LCD_String_xy(1, 9, "LH:");
  sprintf(buffer, "%4u", LH);
  LCD_String_xy(1, 12, buffer);
}
/*----------------------------------------------------------------*/
/*--------------------------LcdCW2.ino----------------------------*/
/*----------------------------------------------------------------*/
