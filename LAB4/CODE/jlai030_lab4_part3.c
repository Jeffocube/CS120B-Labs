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
		START:
		BUTTON = PINA & 0x07;
		switch(BUTTON)
		{
			case 0x01 :
				if(s == X){
					s = HASH;
				}else{
					s = X;
					goto START;
				}
				break;
			case 0x02 :
				if(s == HASH){
					s = Y;
				}else{
					s = X;
					goto START;
				}
				break;
			case 0x04 :
				if(s == Y){
					s = OPEN;
				}else{
					s = X;
					goto START;
				}
				break;
			case 0x00 :
				break;
			default :
				s = X;
				goto START;
				break;
		}
		if((PINA & 0x07) == 0x00)
			goto START;
		while(BUTTON == (PINA & 0x07) ){ }
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
				while((PINA & 0x80) != 0x80){ }
				s = X;
				PORTB = 0x00;
				break;
		}
    }
}

