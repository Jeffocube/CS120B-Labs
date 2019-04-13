/*
 * CS120B_LAB4_PART1.c
 *
 * Created: 4/10/2019 1:27:57 AM
 * Author : Jeff
 */ 

#include <avr/io.h>


int main(void)
{
	enum state {ZERO, ONE};
	enum state  s = ZERO;
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char BUTTON;
	unsigned char tempB;
    /* Replace with your application code */
    while (1) 
    {
		tempB = 0x00;
		BUTTON = (PINA & 0x01);
		switch(BUTTON)
		{
			case 0x01 :
				switch(s)
				{
					case ZERO :
						s = ONE;
						break;
					case ONE :
						s = ZERO;
						break;
				}
				break;
			default :
				break;
		}
		while(BUTTON == (PINA & 0x01)){}
		BUTTON = 0x00;
		switch(s)
		{
			case ZERO :
				tempB = 0x01;
				break;
			case ONE :
				tempB = 0x02;
				break;
			default :
				break;
		}
		PORTB = tempB;
    }
}

