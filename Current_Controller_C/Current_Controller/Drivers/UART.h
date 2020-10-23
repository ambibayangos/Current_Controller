/*
 * UART.h
 *
 * Created: 13/10/2020 9:52:36 PM
 *  Author: ambib
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

//Proteus setup with 0.8MHz external clock 
//(everything scaled by // 1/10 from a typical implementation)
#define F_CPU 8000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

/*
 * This function initializes the UART
 * 
 */
void UART_init(unsigned int ubrr);


/*
 * This function transmit a character serially via UART
 * 
 */
void UART_transmit_char(unsigned char data);


/*
 * This function transmit a string serially via UART
 * 
 */
void UART_transmit_string(char *str);


/* 
 * This function transmits an array of byte serially via UART
 */
void UART_transmit(uint8_t* byte_array, uint32_t byte_array_length);


/* 
 * This function transmits a byte serially via UART
 */
void uart_transmit_byte(uint8_t byte);


/* 
 * This function transmits a number via uart
 */
void UART_transmit_number(uint16_t data);


/* This function takes in a 16 bit integer  
 * and converts it into an array of integer which
 * corresponds to its ascii encoding.
 *
 * e.g int a = 123
 * becomes b[3] = {"1","2","3"} 
 */
uint32_t int2str(uint16_t number, uint8_t* buffer);


#endif /* UART_H_ */