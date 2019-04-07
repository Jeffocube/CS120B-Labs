/*	Partner 1 Name & E-mail: Jeffery Lai jlai030@ucr.edu
 *	Partner 2 Name & E-mail: n/a
 *	Lab Section: 025
 *	Assignment: Lab # 2 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char temp0 = 0x00;
	unsigned char tempB = 0x00;
	while(1){
		temp0 = PINA;
		//switch
		switch(temp0){
			case 0x01:
			tempB = 0x01;
			break;
			default :
			tempB = 0x00;
			break;
		}
		//set
		PORTB = tempB;
		
	}
	return 0;
}
