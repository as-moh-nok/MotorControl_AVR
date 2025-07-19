
#ifndef KYEPAD_H
#define KYEPAD_H

#include <avr/io.h>
#include <util/delay.h>
#include "global.h"

#define key_Port	PORTA
//#define seg_Port	PORTC
//#define lcd_Port	PORTB

#define key_DDR		DDRA
#define key_PIN		PINA

void keypadConfig();
uint8_t keyPress();
uint8_t keyRelease();

char returnKey();
void keypadInit();

#endif //KYEPAD_H