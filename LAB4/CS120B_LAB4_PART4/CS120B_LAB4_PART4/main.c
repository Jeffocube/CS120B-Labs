/*
 * CS120B_LAB4_PART4.c
 *
 * Created: 4/10/2019 4:05:10 AM
 * Author : Jeff
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	enum state {X, HASH, Y, OPEN};
	enum state s = HASH;
	unsigned char LIGHT;
	unsigned char BUTTON;
	LIGHT = 0x00;
	BUTTON = 0x00;
	while (1)
	{
		
		LABEL:
		BUTTON = PINA & 0x07;
		if(BUTTON == 0x00)
			goto LABEL;
		switch(s)
		{
			case HASH :
				if(BUTTON == 0x04)
				{
					s = Y;
				}
				else
				{
					s = HASH;
				}
				break;
			case Y :
				if(BUTTON == 0x02)
				{
					s = OPEN;
				}
				else
				{
					s = HASH;
				}
				break;
			default :
				break;
				
		}
		switch(s)
		{
			case X :
			break;
			case HASH :
			break;
			case Y :
			break;
			case OPEN :
			LIGHT = !LIGHT;
			PORTB = LIGHT & 0x01;
			s = HASH;
			break;
		}
		while(BUTTON == (PINA & 0x07)){ }
	}
}


