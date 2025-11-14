/*------------------------------------------------------------------*/
/*---------------- ----------AdcCW2.ino-----------------------------*/
/*------------------------------------------------------------------*/
#include "AdcCW2.h"
#include <avr/io.h>

void ADC_Init(void)
{
  ADMUX = (1 << REFS0); // AVcc as reference
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable + prescaler 128
}

unsigned short ADC_ReadChannel(unsigned char ch)
{
  ch &= 0b00000111;
  ADMUX = (ADMUX & 0xF8) | ch;
  ADCSRA |= (1 << ADSC);
  while (ADCSRA & (1 << ADSC)); // wait for conversion
  return ADC;
}
/*------------------------------------------------------------------*/
/*---------------- ----------AdcCW2.ino-----------------------------*/
/*------------------------------------------------------------------*/
