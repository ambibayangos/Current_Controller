/*
 * Timers.h
 *
 * Created: 28/10/2020 9:44:54 pm
 *  Author: abay643
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include <avr/io.h>

void init_coil_pwm(void);

void start_coil_pwm(void);

void disable_coil_pwm_timer(void);


#endif /* TIMERS_H_ */