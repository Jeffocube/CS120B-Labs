/*	Partner 1 Name & E-mail: Jeffery Lai
 *	Partner 2 Name & E-mail: n/a
 *	Lab Section: 025
 *	Assignment: Lab # 2 Exercise # 3
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
  unsigned char cntAvail = 0x00;
	while(1){
		cntAvail = 0x00;
		tempC = PINA & 0x0F;
		//switch
		if((tempC & 0x01) == 0x01){
			cntAvail++;
		}
		if((tempC & 0x02) == 0x02){
			cntAvail++;
		}
		if((tempC & 0x04) == 0x04){
			cntAvail++;
		}
		if((tempC & 0x08) == 0x08){
			cntAvail++;
		}
    if(tempC == 0x0F){
      cntAvail = cntAvail | 0x80;
    }
		//set
		PORTC = cntAvail;
		
	}
	return 0;
}
