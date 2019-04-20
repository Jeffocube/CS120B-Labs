/*
 * CS120B_LAB4_PART3.c
 *
 * Created: 4/10/2019 2:41:57 AM
 * Author : Jeff
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	enum state {X, HASH, Y, OPEN};
	enum state s = X;
	unsigned char BUTTON;
	BUTTON = 0x00;
    while (1) 
    {
		BUTTON = PINA & 0x07;
		LABEL:
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
				PORTB = 0x01;
				s = X;
				PORTB = 0x00;
				break;
		}
		while(BUTTON == (PINA & 0x0F)){ }
    }
}

