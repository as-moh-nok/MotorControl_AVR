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

ISR(INT0_vect)
{
	key = returnKey();
//	while(!keyRelease());
//    PORTA ^= (1 << 3);   // Toggle PA3
}

int main(void)
{
	Config();
	keypadConfig();
	
	

	
	/*sbi(DDRA, 3);  //set output PORTC.3 for led
	cbi(PORTA, 3);  //set led off
	*/
	cbi(DDRD, 2);	//set input PORTD.3 for button
	sbi(PORTD, 2);	//set pull-up
   
	
	GICR = (1<<INT0);	//enable intrppt pin
	MCUCR = 0;//set intruppt on changes
	MCUCSR = 0;
	
	GIFR = (1<<INTF0);  //be sure puplic interuppt flag is enable
	sei();
	

	
	
    while (1) 
    {
		keypadInit();
		_delay_ms(20);
//		if(keyPress())
//		{
//			key = returnKey();
			seg_Port = key;  
			_delay_ms(20); //stable
//			while(!keyRelease());
//		}
		//_delay_ms(20); //stable
    }
}

void Config()
{
	/*//inttrupt pin config
	cbi(DDRD, 2);
	sbi(PORTD, 2);*/
	//7segment
	seg_DDR = 0xFF;  //output
	seg_Port = 0xFF;
	
}



