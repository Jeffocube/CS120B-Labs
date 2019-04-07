/*	Partner 1 Name & E-mail: Jeffery Lai
 *	Partner 2 Name & E-mail: n/a
 *	Lab Section: 025
 *	Assignment: Lab # 2 Exercise # 2
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tempC = 0x00;
	while(1){
		tempC = 0x00;
		tempC = PINA & 0x0F;
		//switch
		switch(tempC) {
			case 0x0F :
			tempC = tempC | 0x80;
			break;
			default :
			break;
		}
		//set
		PORTC = tempC;
		
	}
	return 0;
}
