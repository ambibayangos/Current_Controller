#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "current_controller_fsm.h"
#include "Drivers/UART.h"
#include "Drivers/Timers.h"

char* fsm_states[6];
char fsm_state;
volatile int timer_overflow_count = 0;
static int overflowCount = 0;
static int duty = 50;


ISR(TIMER0_COMPA_vect)
{
	//UART_transmit_string("From match A \r\n");
}


ISR(TIMER0_COMPB_vect)
{
	//UART_transmit_string("From match B \r\n");
}

ISR(TIMER1_COMPA_vect)
{
	// do something
}

ISR(TIMER0_OVF_vect)
{	
	if(overflowCount == 10)
	{
		OCR0A = duty*255/100;
		duty = duty+10;
		duty = duty%100;
		overflowCount = 0;
	}
	
	overflowCount++;
}


void gp_io_init(void)
{
	// set OC0A and OC0B to output pins (coil pwm outputs)
	DDRD |= (1<<DDD5) | (1<<DDD6);
	
	// set OC0A to output pins (touch pwm outputs)
	//DDRD |= (1<<DDD6);
}


int main(void)
{
	reset();
	
	gp_io_init();
	init_coil_pwm();
	timer_init();
	UART_init(MYUBRR);
	sei();
	
	start_coil_pwm(1,1);
	while (1)
	{
		tick();
	}
	
}