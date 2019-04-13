/*
 * CS120B_LAB3_PART1.c
 *
 * Created: 4/9/2019 10:01:23 PM
 * Author : Jeff
 */ 

#include <avr/io.h>


int main(void)
{
	//initialize ports
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char num_to_add;
	unsigned char tempA;
	unsigned char tempB;
	unsigned short count;
    while (1) 
    {
		tempA = PINA;
		tempB = PINB;
		num_to_add = 0x00;
		for(count = 0; count < 8; count++)
		{
			if((tempA & 0x80) == 0x80)
			{
				num_to_add++;
			}
			if((tempB & 0x80) == 0x80)
			{
				num_to_add++;
			}
			tempA = tempA << 1;
			tempB = tempB << 1;
		}
		PORTC = num_to_add;
    }
}

