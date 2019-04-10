/*
 * CS120B_LAB3_PART2.c
 *
 * Created: 4/9/2019 10:21:25 PM
 * Author : Jeff
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tempC;
    while (1) 
    {
		tempC = 0x00;
		if((PINA & 0xFF) < 3)
		{
			tempC = tempC | 0x20;
			tempC = tempC | 0x40;
		}
		if((PINA & 0xFF) < 5)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x40;
		}
		if((PINA & 0xFF) < 7)
		{
			tempC = tempC | 0x08;
		}
		if((PINA & 0xFF) < 10)
		{
			tempC = tempC | 0x04;
		}
		if((PINA & 0xFF) < 13)
		{
			tempC = tempC | 0x02;
		}
		if((PINA & 0xFF) < 16)
		{
			tempC = tempC | 0x01;
		}
		PORTC = tempC;
    }
}

