#include <avr/io.h>

int main(void){
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tempC = 0x00;
    while(1){
        //switch
        tempC = PINA & 0x0F;   	
        //set
        PORTC = tempC;    
        
    }
    return 0;
}
