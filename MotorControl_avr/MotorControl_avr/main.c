/*
 * intruppt.c
 *
 * Created: 7/7/2025 9:23:28 AM
 * Author : Mr_Rayaneh_Kerman
 */ 

#define F_CPU 1000000UL

//#include <avr/io.h>
#include <avr/interrupt.h>

#include "keypad.h"

#define seg_DDR		DDRC
#define seg_Port	PORTC

char key = '0';

void Config();



int main(void)
{
	Config();
	keypadConfig();
	
	
    while (1) 
    {
		//keypadInit();
		//_delay_ms(20);
		if(keyPress())
		{
			key = returnKey();
			seg_Port = key;  
			_delay_ms(20); //stable
			while(!keyRelease());
		}
		//_delay_ms(20); //stable
    }
}

void Config()
{

	//7segment
	seg_DDR = 0xFF;  //output
	seg_Port = 0xFF;
	
}



