/*
 * CS120B_LAB5_PART1.c
 *
 * Created: 4/16/2019 9:05:54 PM
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
		if((PINA & 0x0F) < 3)
		{
			tempC = tempC | 0x20;
			tempC = tempC | 0x40;
		}
		if((PINA & 0x0F) < 5 && (PINA & 0x0F) >= 3)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x20;
			tempC = tempC | 0x40;
		}
		if((PINA & 0x0F) < 7 && (PINA & 0x0F) >= 5)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x20;
			tempC = tempC | 0x08;
		}
		if((PINA & 0x0F) < 10 && (PINA & 0x0F) >= 7)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x20;
			tempC = tempC | 0x08;
			tempC = tempC | 0x04;
		}
		if((PINA & 0x0F) < 13 && (PINA & 0x0F) >= 10)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x20;
			tempC = tempC | 0x08;
			tempC = tempC | 0x02;
			tempC = tempC | 0x04;
		}
		if((PINA & 0x0F) < 16 && (PINA & 0x0F) >= 13)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x20;
			tempC = tempC | 0x08;
			tempC = tempC | 0x02;
			tempC = tempC | 0x04;
			tempC = tempC | 0x01;
		}
		PORTC = tempC;
	}
}