/*
 * CS120B_LAB3_PART5.c
 *
 * Created: 4/10/2019 1:02:44 AM
 * Author : Jeff
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB = 0xFE; PORTB = 0x01;
	DDRD = 0x00; PORTD = 0xFF;
	unsigned int tempSense;
	unsigned char tempB;
    while (1) 
    {
		tempB = 0x00;
		tempSense = 0x00;
		tempSense = PIND;
		tempSense = tempSense << 1;
		tempSense = tempSense | (PINB & 0x01);
		if(tempSense >= 70)
		{
			tempB = tempB | 0x02;
		}
		if(tempSense <= 70 && tempSense > 5)
		{
			tempB = tempB | 0x04;
		}
		
		PORTB = tempB;
    }
}

