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
	enum state {WAITIN, WAITLIFT};
	enum state s;
	unsigned char BUTTON;
	unsigned char numOut;
	numOut = 7;
	s = WAITIN;
	PORTC = numOut;
	unsigned i;
	while (1)
	{
		i = 0;
		BUTTON = (PINA & 0x03);
		while(i < 50000){
			if((PINA & 0x03) == 0x00)
				BUTTON = (PINA & 0x00);
			i++;
			
		}
		switch(s)
		{
			case WAITIN :
				if(BUTTON == 0x3){
					break;
				}
				if(BUTTON == 0x02){
					if(numOut == 9){
						break;
					}else{
						s = WAITLIFT;
						numOut++;
						break;
					}
				}else if(BUTTON == 0x01){
					if(numOut == 0){
						break;
					}else{
						s = WAITLIFT;
						numOut--;
						break;
					}
				}else{
					s = WAITLIFT;
					numOut = 0;
					break;
				}
			break;
			case WAITLIFT :
				
				if(BUTTON != 0x3)
					s = WAITLIFT;
				else
					s = WAITIN;
				break;
			default :
			break;
					
		}
		switch(s)
		{
			case WAITIN :
			break;
			case WAITLIFT :
			break;
			default :
			break;
		}
		PORTC = numOut;
	}
}


