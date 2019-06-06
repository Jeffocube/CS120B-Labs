/*
 * CS120B_LAB9_PART1.c
 *
 * Created: 5/5/2019 11:05:52 PM
 * Author : Jeff
 */ 

#include <avr/io.h>
// 0.954 hz is lowest frequency possible with this function,
// based on settings in PWM_on()
// Passing in 0 as the frequency will stop the speaker from generating sound
void set_PWM(double frequency) {
	static double current_frequency; // Keeps track of the currently set frequency
	// Will only update the registers when the frequency changes, otherwise allows
	// music to play uninterrupted.
	if (frequency != current_frequency) {
		if (!frequency) { TCCR3B &= 0x08; } //stops timer/counter
		else { TCCR3B |= 0x03; } // resumes/continues timer/counter
		
		// prevents OCR3A from overflowing, using prescaler 64
		// 0.954 is smallest frequency that will not result in overflow
		if (frequency < 0.954) { OCR3A = 0xFFFF; }
		
		// prevents OCR3A from underflowing, using prescaler 64					// 31250 is largest frequency that will not result in underflow
		else if (frequency > 31250) { OCR3A = 0x0000; }
		
		// set OCR3A based on desired frequency
		else { OCR3A = (short)(8000000 / (128 * frequency)) - 1; }

		TCNT3 = 0; // resets counter
		current_frequency = frequency; // Updates the current frequency
	}
}

void PWM_on() {
	TCCR3A = (1 << COM3A0);
	// COM3A0: Toggle PB6 on compare match between counter and OCR3A
	TCCR3B = (1 << WGM32) | (1 << CS31) | (1 << CS30);
	// WGM32: When counter (TCNT3) matches OCR3A, reset counter
	// CS31 & CS30: Set a prescaler of 64
	set_PWM(0);
}

void PWM_off() {
	TCCR3A = 0x00;
	TCCR3B = 0x00;
}

enum state{C, D, E};
enum state s;
unsigned char button;
unsigned short i;
void tick(){
	PORTB = 0x08;
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xF7; PORTB = 0x08;
	
	PWM_on();
    /* Replace with your application code */
	set_PWM(349.23);
    while (1) 
    {
		
		button = PINA & 0x07;
		if(button == 0x06)
		set_PWM(261.63);
		else if(button == 0x05)
		set_PWM(293.66);
		else if(button == 0x3)
		set_PWM(329.63);
		else
		set_PWM(0);
		
		tick();		
    }
}

