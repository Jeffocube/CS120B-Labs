/*
 * CS120B_LAB7_PART1.c
 *
 * Created: 4/26/2019 1:40:18 PM
 * Author : Jeff
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "io.c"
// tick
unsigned char tempC;
unsigned char num;
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
	LCD_WriteData(num + '0');
	if(num > 9)
		num = 0;
}
int main(void)
{
	DDRC = 0xFF; PORTC = 0x00; // LCD data lines
	DDRD = 0xFF; PORTD = 0x00; // LCD control lines
	// Initializes the LCD display
	LCD_init();
	
	// Starting at position 1 on the LCD screen, writes Hello World
	LCD_DisplayString(1, "Hello World");
	tempC = 0x00;
	TimerSet(1000);
	TimerOn();
	while(TimerFlag){
		tick();
	}
}


