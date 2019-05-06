
/*	Partner 1 Name & E-mail: Jeffery Lai jlai030@ucr.edu
 *	Partner 2 Name & E-mail:
 *	Lab Section: 025
 *	Assignment: Lab # 8 Exercise # 3
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

unsigned short my_short;
unsigned char tempB;
unsigned char tempD;
void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC ) | (1 << ADATE);
}

int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTB = 0x00;
	/* Replace with your application code */
	ADC_init();
	while (1)
	{
		my_short = ADC;
		if(my_short >= 256)
			PORTB = 0x01;
		else
			PORTB = 0x00;
	}
}



