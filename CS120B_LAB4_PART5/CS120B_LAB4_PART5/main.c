/*
 * CS120B_LAB4_PART5.c
 *
 * Created: 4/12/2019 9:44:50 PM
 * Author : Jeff
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	enum state {ONE, TWO, THREE, FOUR, OPEN};
	enum state s = ONE;
	unsigned char LIGHT;
	unsigned char BUTTON;
	LIGHT = 0x00;
	BUTTON = 0x00;
	while (1)
	{
		BUTTON = PINA & 0x07;
		switch(s)
		{
			case ONE :
				if((BUTTON & 0x0F) == 0x04)
				{
					s = TWO;
				}else if(BUTTON != 0x00)
				{
					s = ONE;
				}
				break;
			case TWO :
				if((BUTTON & 0x0F) == 0x01)
				{
					s = THREE;
				}else  if(BUTTON != 0x00)
				{
					s = ONE;
				}
				break;
			case THREE :
				if((BUTTON & 0x0F) == 0x02)
				{
					s = FOUR;
				}else if(BUTTON != 0x00)
				{
					s = ONE;
				}
				break;
			case FOUR :
				if((BUTTON & 0x0F) == 0x01)
				{
					s = OPEN;
				}else if(BUTTON != 0x00)
				{
					s = ONE;
				}
				break;
			case OPEN :
				s = ONE;
				break;
			default :
				break;
				
		}
		while(BUTTON == (PINA & 0x07) && PINA != 0x00){ }
		switch(s)
		{
			case OPEN :
				LIGHT = !LIGHT & 0x01;
				break;
			case ONE :
				break;
			case TWO :
				break;
			case THREE :
				break;
			case FOUR :
				break;
			default	:
				break;
		}
		PORTB = LIGHT & 0x01;
	}
}


