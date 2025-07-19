

#include "keypad.h"


char keyPad[4][4] = {
{ '7', '8', '9', '/'},
{ '4', '5', '6', '*'},
{ '1', '2', '3', '-'},
{ 'C', '0', '=', '+'}};

	
void keypadConfig()
{
	//keyPad
	key_DDR = 0x0F; //input(row)	output(col)
	key_Port = 0xFF; //pull-up		high 4 bit	
}


uint8_t keyRelease()
{
	key_Port = 0xF0; //pullup
	if(key_PIN == 0xF0)
	{
		return 1;
	}
	return 0;
}

uint8_t keyPress()
{
	uint8_t read_row = 0;
	
	key_Port = 0xF0;  //pull up
	if((read_row = (key_PIN & 0xF0)) != 0xF0 )  // 0x ---- 0000  != 0x1111 0000
	{
		_delay_ms(20);
		if( read_row == (key_PIN & 0xF0))
		{
			return 1;
		}
	}
	return 0;
}

char returnKey()
{
		   for(uint8_t i = 0;i<4; i++)
		   {
			   key_Port = 0xFF;  //set 1 all pins and pull up
			   cbi(key_Port, i); //set 0 each row
			   _delay_ms(3); //stablity
			   for(uint8_t j = 4; j<8; j++)
			   {
				   if(!CHECKBIT(key_PIN, j))
				   {
					   char select = keyPad[i][j-4];
					   //seg_Port = select;
					   return select;
					   
				   }
				   _delay_ms(10);
			   }
			   _delay_ms(10);
		   }
		   return 'z';   	
}

void keypadInit()
{
	key_Port = 0xF0;
/*	for(uint8_t i = 0;i<4; i++)
	{
		key_Port = 0xFF;  //set 1 all pins and pull up
		cbi(key_Port, i); //set 0 each row
		_delay_ms(3); //stablity
	}*/	
}
