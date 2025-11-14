/*----------------------------------------------------------------*/
/*--------------------------DIOCW2.INO----------------------------*/
/*----------------------------------------------------------------*/
#include <util/delay.h>
#include "DIOCW2.h"

void DIO_Init(void)
{
  LED_DDR |= (1 << LED_PIN);

  // Inputs with pull-ups
  PUSH1_DDR &= ~(1 << PUSH1_BIT);
  PUSH2_DDR &= ~(1 << PUSH2_BIT);
  PUSH3_DDR &= ~(1 << PUSH3_BIT);
  PUSH4_DDR &= ~(1 << PUSH4_BIT);

  PUSH1_PORT |= (1 << PUSH1_BIT);
  PUSH2_PORT |= (1 << PUSH2_BIT);
  PUSH3_PORT |= (1 << PUSH3_BIT);
  PUSH4_PORT |= (1 << PUSH4_BIT);
}

void LED_ON(void) { LED_PORT |= (1 << LED_PIN); }
void LED_OFF(void) { LED_PORT &= ~(1 << LED_PIN); }

bool Button1(void)
{
  if (!(PUSH1_PIN & (1 << PUSH1_BIT)))
  {
    _delay_ms(20);
    if (!(PUSH1_PIN & (1 << PUSH1_BIT))) return true;
  }
  return false;
}
bool Button2(void)
{
  if (!(PUSH2_PIN & (1 << PUSH2_BIT)))
  {
    _delay_ms(20);
    if (!(PUSH2_PIN & (1 << PUSH2_BIT))) return true;
  }
  return false;
}
bool Button3(void)
{
  if (!(PUSH3_PIN & (1 << PUSH3_BIT)))
  {
    _delay_ms(20);
    if (!(PUSH3_PIN & (1 << PUSH3_BIT))) return true;
  }
  return false;
}
bool Button4(void)
{
  if (!(PUSH4_PIN & (1 << PUSH4_BIT)))
  {
    _delay_ms(20);
    if (!(PUSH4_PIN & (1 << PUSH4_BIT))) return true;
  }
  return false;
}
/*----------------------------------------------------------------*/
/*--------------------------DIOCW2.INO----------------------------*/
/*----------------------------------------------------------------*/
