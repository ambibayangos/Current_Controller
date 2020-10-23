#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "current_controller_fsm.h"
#include "Drivers/UART.h"

char* fsm_states[6];
char fsm_state;
volatile int timer_overflow_count = 0;


ISR(TIMER2_COMPA_vect)
{
	UART_transmit_number(88);
	// avoid overlow on the variable "timer_overflow_count"
	if(timer_overflow_count == 1000000)
	{
		timer_overflow_count = 1;
	}
	else
	{
		timer_overflow_count++;
	}
}

void init_timer(void)
{
	// set to ctc mode
	TCCR2A |= (1<<WGM21);
	
	// set timer resolution to 1ms
	OCR2A = 124;

	// enable interrupt on match
	TIMSK2 |= (1<<OCIE2A);
	
	//set prescaller to 64 and start timer
	TCCR2B |= (1<<CS22);
	
}

void gp_io_init(void)
{
	// set OC1A and OC1B to output pins (coil pwm outputs)
	DDRB |= (1<<DDB1) | (1<<DDB2);
	
	// set OC0A to output pins (touch pwm outputs)
	DDRD |= (1<<DDD6);
}

void init_coil_pwm(void)
{
	// set to phase correct mode (mode 15)	
	TCCR1A |= (1<<WGM10) | (1<<WGM11); TCCR1B |= (1<<WGM12) | (1<<WGM13);
	
	// set frequency to 20Hz for prescaller 1024
	ICR1  = 388;
	
	// set the duty cycle
	OCR1A = 50*388/100;
	
	// set the duty cycle
	OCR1B = 50*388/100;
	
	// set precaller to 1024 and start pwm
	TCCR1B |= (1<<CS12) | (1<<CS10); TCCR1B &= ~(1<<CS11);
	
}

void stop_coil_pwm(int polarity)
{
	if(polarity) // turn off opening pwm
	{
		TCCR1A |= ~((1<<COM1A1) | (1<<COM1A0));
	}
	else  // turn off closing pwm
	{
		TCCR1A |= ~((1<<COM1B1) | (1<<COM1B0));
	}
}

void set_coil_pwm_to_idle(void)
{
	// set precaller to 1024 and start pwm
	TCCR1B &= ~((1<<CS12) | (1<<CS10) | (1<<CS11));
}

void start_coil_pwm(int polarity)
{
	if(polarity) // turn off opening pwm
	{
		// clear OCA1A at compare match
		TCCR1A |= (1<<COM1A1);
	}
	else  // turn off closing pwm
	{
		// clear OCA1B at compare match
		TCCR1A |= (1<<COM1B1);
	}
}

void touch_pwm_init(void)
{
	// set to fast pwm mode 0xFF is top
	TCCR0A |= (1<<WGM00)|(1<<WGM01);
	
	// clear OC1A on compare match A
	TCCR0A |= (1<<COM0A1);
	
	// set duty cyle to 50%
	OCR0A = 128;
	

}

void start_touch_pwm(void)
{
	// reset timer count to zero
	TCNT0 = 0;
	// set prescaller to 8 and start pwm
	TCCR0B |= (1<<CS01);
}

void stop_touch_pwm(void)
{
	// disconnect prescaller
	TCCR0B &= ~((1<<CS02) | (1<<CS01) | (1<<CS00));
}

int main(void)
{
	reset();
	
	init_timer();
	gp_io_init();
	init_coil_pwm();
	touch_pwm_init();
	UART_init(MYUBRR);
	
	start_coil_pwm(0);
	start_touch_pwm();
	
	sei();
	
	while (1)
	{		
		tick();
		
		if(init_state)
		{
			//UART_transmit_string("Current state: init state\n\r");
		}
	}
	

	
}