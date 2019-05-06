/*	Partner 1 Name & E-mail: Jeffery Lai jlai030@ucr.edu
 *	Partner 2 Name & E-mail:
 *	Lab Section: 025
 *	Assignment: Lab #  8 Exercise # 1
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

void tick(){
	tempB = 0x00;
	if(my_short >= 512)
		tempB = (tempB | 0x80);
	if(my_short >= 448)
		tempB = (tempB | 0x40);
	if(my_short >= 384)
		tempB = (tempB | 0x20);
	if(my_short >= 320)
		tempB = (tempB | 0x10);
	if(my_short >= 256)
		tempB = (tempB | 0x08);
	if(my_short >= 192)
		tempB = (tempB | 0x04);
	if(my_short >= 128)
		tempB = (tempB | 0x02);
	if(my_short > 0)
		tempB = (tempB | 0x01);
	PORTB = tempB;
}
int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
    /* Replace with your application code */
	ADC_init();
    while (1) 
    {
		my_short = ADC;
		tick();
		
    }
}


