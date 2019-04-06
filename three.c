#include <avr/io.h>

int main(void){
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTC = 0x00;
    unsigned char tempD = 0x00;
    unsigned char tempHold = 0x00;
    while(1){
        tempD = 0x00;  
        tempHold = PORTA + PORTB + PORTC;
        //if
        if(tempHold > 0x8C){
            tempD << 4;
            tempD | 0x01;
        }
        if(PORTA - PORTC > 0x50 || PORTC - PORTA > 0x50 ){
            tempD | 0x02;
        }
        //set
        PORTC = tempD;    
        
    }
    return 0;
}
