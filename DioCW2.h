/*----------------------------------------------------------------*/
/*--------------------------DIOCW2.h------------------------------*/
/*----------------------------------------------------------------*/
#ifndef DIOCW2_H
#define DIOCW2_H

#include <stdbool.h>

// LED setup
#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_PIN PB5

// Buttons setup
#define PUSH1_DDR DDRB
#define PUSH1_PORT PORTB
#define PUSH1_PIN PINB
#define PUSH1_BIT PB4

#define PUSH2_DDR DDRB
#define PUSH2_PORT PORTB
#define PUSH2_PIN PINB
#define PUSH2_BIT PB3

#define PUSH3_DDR DDRB
#define PUSH3_PORT PORTB
#define PUSH3_PIN PINB
#define PUSH3_BIT PB2

#define PUSH4_DDR DDRB
#define PUSH4_PORT PORTB
#define PUSH4_PIN PINB
#define PUSH4_BIT PB1

void DIO_Init(void);
void LED_ON(void);
void LED_OFF(void);

bool Button1(void);
bool Button2(void);
bool Button3(void);
bool Button4(void);

#endif
/*----------------------------------------------------------------*/
/*--------------------------DIOCW2.h------------------------------*/
/*----------------------------------------------------------------*/
