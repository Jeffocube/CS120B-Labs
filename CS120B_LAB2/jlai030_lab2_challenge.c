/*	Partner 1 Name & E-mail: Jeffery Lai jlai030@ucr.edu
 *	Partner 2 Name & E-mail:n/a
 *	Lab Section: 025
 *	Assignment: Lab # 2 Exercise # Challenge
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned char tempD = 0x00;
	unsigned char tempHold = 0x00;
	while(1){
		tempD = 0x00;
		tempHold = (PINA + PINB + PINC);
		tempD = tempD | tempHold;
		tempD = tempD << 2;
		//if
		if(tempHold > 0x8C){
			tempD = tempD | 0x01;
		}
		if((PINA - PINC) > 0x50 || (PINC - PINA) > 0x50 ){
			tempD = tempD | 0x02;
		}
		//set
		PORTD = tempD;
		
	}
	return 0;
}
