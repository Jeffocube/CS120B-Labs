/*
 * CS120B_LAB4_PART2.c
 *
 * Created: 4/10/2019 1:59:39 AM
 * Author : Jeff
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	enum state {UP, DOWN, ZERO};
	enum state s;
	unsigned char BUTTON;
	unsigned char numOut;
	numOut = 7;
	s = ZERO;
	PORTC = numOut;
    while (1) 
    {
		LABEL:
		BUTTON = (PINA & 0x03);
		switch(BUTTON)
		{
			case 0x01 :
				s = UP;
				break;
			case 0x02 :
				s = DOWN;
				break;
			case 0x03 :
				s = ZERO;
				break;
			default :
				break;
		}
		if(BUTTON == 0x00)
			goto LABEL;
		while(BUTTON == (PINA & 0x03)){} 
		switch(s)
		{
			case UP :
				switch(numOut)
				{
					case 9 :
						break;
					default :
						numOut++;
						break;
				}
				break;
			case DOWN :
				switch(numOut)
				{
					case 0 :
						break;
					default :
						numOut--;
						break;
				}
				break;
			case ZERO : 
				numOut = 0;
				break;
			default :
				break;
		}
		PORTC = numOut;
    }
}

