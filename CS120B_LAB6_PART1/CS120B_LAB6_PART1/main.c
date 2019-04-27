/*
 * CS120B_LAB6_PART1.c
 *
 * Created: 4/26/2019 1:21:50 PM
 * Author : Jeff
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

// tick
unsigned char tempC;
enum state {ONE, TWO, THREE};
enum state s;
enum state s = ONE;
// end
volatile unsigned char TimerFlag = 0;

unsigned long _avr_timer_M = 1;
unsigned long _avr_timer_cntcurr = 0;

void TimerOn(){
	TCCR1B = 0x0B;
	OCR1A = 125;
	TIMSK1 = 0x02;
	_avr_timer_cntcurr = _avr_timer_M;
	SREG |= 0x80;
}
void TimerOff(){
	TCCR1B = 0x00;
}

void TimerISR(){
	TimerFlag = 1;
}
void TimerSet(unsigned long M){
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}
ISR(TIMER1_COMPA_vect){
	_avr_timer_cntcurr--;
	if(_avr_timer_cntcurr == 0){
		TimerISR();
		_avr_timer_cntcurr = _avr_timer_M;
	}
}
void tick(){
	tempC = 0x00;
	switch(s){
		case ONE:
			s = TWO;
			break;
		case TWO:
			s = THREE;
			break;
		case THREE:
			s = ONE;
			break;
		default:
			s = ONE;
			break;
	}
	switch(s){
		case ONE:
			tempC = 0x01;
			break;
		case TWO:
			tempC = 0x02;
			break;
		case THREE:
			tempC = 0x04;
			break;
		default:
			break;
	}
	PORTC = tempC;
}
int main()
{
	DDRC = 0xFF; // Set port B to output
	PORTC = 0x00; // Init port B to 0s
	tempC = 0x00;
	TimerSet(1000);
	TimerOn();
	while(1) {
		// User code (i.e. synchSM calls)
		while (TimerFlag){
			tick();
			TimerFlag = 0;
		}
	}
}
