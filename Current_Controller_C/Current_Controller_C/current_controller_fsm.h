/*
 * current_controller_fsm.h
 *
 * Created: 23/10/2020 7:25:44 pm
 *  Author: abay643
 */ 


#ifndef CURRENT_CONTROLLER_FSM_H_
#define CURRENT_CONTROLLER_FSM_H_


/* This method initializes 
 * states in the controller fsm
 */
void reset();
 
/* This function updates the state
 * in the controller fsm depending
 * on the current inputs
 */
void tick(); 


//input signals
extern char door_closed;
extern char	door_open;
extern char	waitUser_ex;
extern char	door_touched;
extern char	opening_timer_ex;

//output signal
extern char	init_state;
extern char	waitUser_state;
extern char	waitTouch_state;
extern char	generateOpening_state;
extern char	generateClosing_state;

#endif /* CURRENT_CONTROLLER_FSM_H_ */