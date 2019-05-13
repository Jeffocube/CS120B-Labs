/*
 * CS120B_LAB10_PART1.c
 *
 * Created: 5/12/2019 8:47:59 PM
 * Author : Jeff
 */ 

#include <avr/io.h>

unsigned char threeLEDS;
unsigned char blinkingLED;
unsigned long i;
enum state1{ONE, TWO, THREE};
enum state2{ON, OFF};
enum state1 s1;
enum state2 s2;
void SM1_tick(){
	switch(s1){
		case ONE :
			s1 = TWO;
		break;
		case TWO :
			s1 = THREE;
		break;
		case THREE :
			s1 = ONE;
		break;
		default :
			s1 = ONE;
		break;
	}
	switch(s1){
		case ONE :
			threeLEDS = 0x02;
		break;
		case TWO :
			threeLEDS = 0x04;
		break;
		case THREE :
			threeLEDS = 0x08;
		break;
		default :
			threeLEDS = 0x00;
		break;
	}
}
void SM2_tick(){
	switch(s2){
		case ON :
			s2 = OFF;
		break;
		case OFF :
			s2 = ON;
		break;
		default :
			s2 = ON;
		break;
	}
	switch(s2){
		case ON :
			blinkingLED = 0x01;
		break;
		case OFF :
			blinkingLED = 0x00;
		break;
		default :
			blinkingLED = 0x00;
		break;
	}
}
int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	s1 = ONE;
	s2 = ON;
    /* Replace with your application code */
    while (1) 
    {
	    i = 0;
		while(i < 1000000){
			i++;
		}
		SM1_tick();
		SM2_tick();
		PORTB = blinkingLED | threeLEDS;
    }
}

