/*
 * CS120B_LAB5_PART2.c
 *
 * Created: 4/16/2019 11:01:01 PM
 * Author : Jeff
 */ 


#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	enum state {UP, DOWN, ZERO, NOTHING};
	enum state s;
	unsigned char BUTTON;
	unsigned char numOut;
	numOut = 7;
	s = ZERO;
	PORTC = numOut;
	while (1)
	{
		BUTTON = (PINA & 0x03);
		switch(s)
		{
			case UP :
				if(BUTTON == 0x02 && numOut < 9)
					s = UP;
				else if(BUTTON == 0x02 && numOut == 9)
					s = NOTHING;
				else if(BUTTON == 0x01)
					s = DOWN;
				else if(BUTTON == 0x00)
					s = ZERO;
				else
					s = NOTHING;
			break;
			case DOWN :
				if(BUTTON == 0x02)
					s = UP;
				else if(BUTTON == 0x01 && numOut > 0)
					s = DOWN;
				else if(BUTTON == 0x01 && numOut == 0)
					s = NOTHING;
				else if(BUTTON == 0x00)
					s = ZERO;
				else
					s = NOTHING;
			break;
			case ZERO:
				if(BUTTON == 0x02)
					s = UP;
				else
					s = NOTHING;
			break;
			case NOTHING:
				if(BUTTON == 0x02 && numOut < 9)
					s = UP;
				else if(BUTTON == 0x01 && numOut > 0)
					s = DOWN;
				else if(BUTTON == 0x00)
					s = ZERO;
				else
					s = NOTHING;
			break;
			default :
			break;
					
		}
		switch(s)
		{
			case UP :
				numOut++;
			break;
			case DOWN :
				numOut--;
			break;
			case NOTHING :
			break;
			case ZERO :
				numOut = 0;
			break;
			default :
			break;
		}
		PORTC = numOut;
		while(BUTTON == (PINA & 0x03)){}
	}
}


