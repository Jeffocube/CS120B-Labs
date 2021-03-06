/*
 * CS120B_LAB9_PART3.c
 *
 * Created: 5/9/2019 2:53:41 AM
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

enum state{ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
enum state s;
unsigned char button;
unsigned short i;
unsigned short period;
void tick(){
	switch(s){
		case ONE:
		if(i <= period){
			i++;
			s = ONE;
		}
		else{
			s = TWO;
			i = 0;
			period = 100000;
			set_PWM(293.66);
		}
		
		break;
		case TWO:
		if(i <= period){
			i++;
			s = TWO;
			}else{
			s = THREE;
			i = 0;
			period = 100000;
			set_PWM(261.63);
		}
		break;
		case THREE:
		if(i <= period){
			i++;
			s = THREE;
			}else{
			s = FOUR;
			i = 0;
			period = 100000;
			set_PWM(349.23);
		}
		break;
		
		case FOUR:
		if(i <= period){
			i++;
			s = FOUR;
			}else{
			s = FIVE;
			i = 0;
			period = 100000;
			set_PWM(261.63);
		}
		break;
		case FIVE:
		if(i <= period){
			i++;
			s = FIVE;
			}else{
			s = SIX;
			i = 0;
			period = 100000;
			set_PWM(440.00);
		}
		break;
		
		case SIX:
		if(i <= period){
			i++;
			s = SIX;
			}else{
			s = SEVEN;
			i = 0;
			period = 100000;
			set_PWM(261.63);
		}
		break;
		
		case SEVEN:
		if(i <= period){
			i++;
			s = SEVEN;
			}else{
			s = EIGHT;
			i = 0;
			period = 100000;
			set_PWM(523.25);
		}
		break;
		case EIGHT:
		if(i <= period){
			i++;
			s = EIGHT;
			}else{
			s = ONE;
			i = 0;
			period = 100000;
			set_PWM(261.23);
		}
		default:
		s = ONE;
		period = 200000;
		set_PWM(261.63);
		break;
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xF7; PORTB = 0x08;
	
	PWM_on();
	/* Replace with your application code */
	set_PWM(523.25);
	i = 0;
	s = EIGHT;
	while (1)
	{
		tick();
		PORTB = 0x08;
	}
}