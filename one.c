#include <avr/io.h>

int main(void){
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    unsigned char temp0 = 0x00;
    unsigned char tempB = 0x00;
    while(1){
        temp0 = PINA & 0x01;
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
