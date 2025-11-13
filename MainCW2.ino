/*----------------------------------------------------------------*/
/*--------------------------Main.ino------------------------------*/
/*----------------------------------------------------------------*/
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#include "DioCW2.h"
#include "LcdCW2.h"
#include "AdcCW2.h"

#define MIN_LIMIT 0
#define MAX_LIMIT 1023

// ---------- Smooth ADC Read ----------
unsigned short Read_SmoothADC(unsigned char ch)
{
  unsigned long sum = 0;
  for (uint8_t i = 0; i < 8; i++)
    sum += ADC_ReadChannel(ch);
  return (unsigned short)(sum / 8);
}

int main(void)
{
  LCD_Init();
  ADC_Init();
  DIO_Init();

  unsigned short LH = 900;
  unsigned short LL = 200;
  unsigned short Sensor = 0;
  unsigned short lastSensor = 0;

  LCD_Display(LL, LH, Sensor);

  while (1)
  {
    Sensor = Read_SmoothADC(0);

    // ----- BUTTON CONTROL -----
    if (Button1())
    {
      if (LH < MAX_LIMIT - 10) LH += 10;
      _delay_ms(150);
    }
    if (Button2())
    {
      if (LH > MIN_LIMIT + 10) LH -= 10;
      _delay_ms(150);
    }
    if (Button3())
    {
      if (LL < MAX_LIMIT - 10) LL += 10;
      _delay_ms(150);
    }
    if (Button4())
    {
      if (LL > MIN_LIMIT + 10) LL -= 10;
      _delay_ms(150);
    }

    // ----- LED CONTROL (OUTSIDE RANGE = ON) -----
    if (Sensor < LL || Sensor > LH)
      LED_ON();       // light up when outside limits
    else
      LED_OFF();      // off when within range

    // ----- LCD UPDATE -----
    if (abs(Sensor - lastSensor) > 5)
    {
      LCD_Display(LL, LH, Sensor);
      lastSensor = Sensor;
    }

    _delay_ms(20);
  }
}
/*----------------------------------------------------------------*/
/*--------------------------Main.ino------------------------------*/
/*----------------------------------------------------------------*/
