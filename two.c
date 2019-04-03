#include <avr/io.h>

int main(void){
    DDRA = 0x0; PORTA = 0xF;
    DDRC = 0xF; PORTC = 0x0;
    unsigned char tempC = 0x0;
    while(1){
        //switch
        tempC = PINA & 0xF;   	
        //set
        PORTC = tempC;    
        
    }
    return 0;
}
