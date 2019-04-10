/*
 * CS120B_LAB3_PART4.c
 *
 * Created: 4/9/2019 11:05:05 PM
 * Author : Jeff
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tempB;
	unsigned char tempC;
    while (1) 
    {
		tempB = 0x00;
		tempC = 0x00;
		tempB = PINA & 0x0F;
		tempC = PINA & 0xF0;
		PORTC = tempC;
		PORTB = tempB;
    }
}

