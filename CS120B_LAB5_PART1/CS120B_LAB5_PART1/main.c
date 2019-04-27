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
	unsigned char num;
	while (1)
	{
		num = ~(PINA & 0x0F) & 0x0F;
		tempC = 0x00;
		if(num == 0)
			tempC = tempC | 0x40;
		if(num < 3 && num >= 1)
		{
			tempC = tempC | 0x20;
			tempC = tempC | 0x40;
		}
		if(num < 5 && num >= 3)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x20;
			tempC = tempC | 0x40;
		}
		if(num < 7 && num >= 5)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x20;
			tempC = tempC | 0x08;
		}
		if(num < 10 && num >= 7)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x20;
			tempC = tempC | 0x08;
			tempC = tempC | 0x04;
		}
		if(num < 13 && num >= 10)
		{
			tempC = tempC | 0x10;
			tempC = tempC | 0x20;
			tempC = tempC | 0x08;
			tempC = tempC | 0x02;
			tempC = tempC | 0x04;
		}
		if(num < 16 && num >= 13)
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