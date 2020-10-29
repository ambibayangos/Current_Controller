/*
 * Timers.c
 *
 * Created: 28/10/2020 11:36:02 PM
 *  Author: ambib
 */ 


#include <avr/io.h>
#include "Timers.h"

extern int duty;

/* This function initializes timer 0
 * to generate the PWM for the coil at about 30 Hz
 */
void init_coil_pwm(void)
{
	// set fast pwm mode
	TCCR0A |= (1<<WGM00) | (1<<WGM01); TCCR0B &= ~(1<<WGM02);
	
	//set initial duty cycle to 50%
	OCR0A = 10*255/100;
	
	//set initial duty cycle to 50%
	OCR0B = 10*255/100;
}

/* This function starts the PWM generation for closing or opening force
 */
void start_coil_pwm(int polarity, int init)
{	
	//set prescaller to 1024 and start generating PWM on the coil
	TCCR0B |= (1<<CS00) | (1<<CS02); TCCR0B &= ~(1<<CS01);
		
	
	if(polarity == 1 && init == 0) // closing current
	{	
		//clear on match and set on bottom
		TCCR0A |= (1<<COM0A1); TCCR0A &= ~(1<<COM0A0); // OC0A pin
		
		//diconnect OC0B pin (stop generating PWM)
		TCCR0A &= ~((1<<COM0B0)|(1<<COM0B1));
		
		// enable ISR on match B and disable on match A
		TIMSK0 |= (1<<OCIE0B); TIMSK0 &= ~(1<<OCIE0A);
		
		// sample coil current after 3.2ms
		OCR0B = 25;
		
		//enable interupt on overflow
		TIMSK0 |= (1<<TOIE0);
				
	}
	else if(polarity == 0 && init == 0) // opening current
	{
		//clear on match and set on bottom
		TCCR0A |= (1<<COM0B1); TCCR0A &= ~(1<<COM0B0); // OC0B pin
		
		//diconnect OC0A pin (stop generating PWM)
		TCCR0A &= ~((1<<COM0A1)|(1<<COM0A0));
		
		// enable ISR on match A and disable on match B
		TIMSK0 |= (1<<OCIE0A); TIMSK0 &= ~(1<<OCIE0B);
		
		// sample coil current after 3.2ms
		OCR0A = 25;	
		
		//enable interupt on overflow
		TIMSK0 |= (1<<TOIE0);
	}
	else if(polarity == 1 && init == 1)
	{	
		// set duty cycle to 50%
		//set initial duty cycle to 50%
		OCR0A = 50*255/100;
		
		//clear on match and set on bottom
		TCCR0A |= (1<<COM0A1); TCCR0A &= ~(1<<COM0A0); // OC0A pin
		
		//diconnect OC0B pin (stop generating PWM)
		TCCR0A &= ~((1<<COM0B0)|(1<<COM0B1));
		
		// enable ISR on match B and disable on match A
		TIMSK0 |= (1<<OCIE0B); TIMSK0 &= ~(1<<OCIE0A);
		
		// sample coil current after 3.2ms
		OCR0B = 25;
		
		//disable interupt on overflow
		TIMSK0 &= ~(1<<TOIE0);
		
	}
}
	
/* This function disconnects the CPU clock from the PWM timer
 * in able to save power
 */	
void disable_coil_pwm(void)
{	
	// set precaller to zero (stopt timer0)
	TCCR0B &= ~((1<<CS00) | (1<<CS01) | (1<<CS02));
}


/* Initialize the 16 bit timer to just count till it oveflows
 *
 */
void timer_init(void)
{
	//set normal mode
	TCCR1B &= ~((1<<WGM13) | (1<<WGM12)); TCCR1A &= ~((1<<WGM10) | (1<<WGM11));
	
	//set prescaller to 1024
	TCCR1B |= (1<<CS12) | (1<<CS10); TCCR1B &= ~(1<<CS11);
	
	// enable "timer" interrupt every 150ms and disable other interrupts on timer1
	//TIMSK1 |= (1<<OCIE1A); OCR1A = 1170;
}

