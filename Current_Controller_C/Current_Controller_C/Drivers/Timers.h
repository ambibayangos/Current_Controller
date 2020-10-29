/*
 * Timers.h
 *
 * Created: 28/10/2020 11:36:11 PM
 *  Author: ambib
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_


#include <avr/io.h>



/* This function initializes timer 0
 * to generate the PWM for the coil at about 30 Hz
 */
void init_coil_pwm(void);

/* This function starts the PWM generation for closing or opening force
 */
void start_coil_pwm(int polarity, int init);

/* This function disconnects the CPU clock from the PWM timer
 * in able to save power
 */	
void disable_coil_pwm(void);

/* Initialize the 16 bit timer to just count till it oveflows
 *
 */
void timer_init(void);



#endif /* TIMERS_H_ */