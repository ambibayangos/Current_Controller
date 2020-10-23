/*
 * UART.c
 *
 * Created: 14/10/2020 1:30:55 AM
 *  Author: ambib
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <string.h>
#include "UART.h"

/*
 * This function initializes the UART
 * 
 */
void UART_init(unsigned int ubrr)
{
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
}


/*
 * This function transmit a character serially via UART
 * 
 */
void UART_transmit_char(unsigned char data)
{
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}


/*
 * This function transmit a string serially via UART
 * 
 */
void UART_transmit_string(char *str)
{
	int i;
	for(i = 0; i < strlen(str); i++) {
		UART_transmit_char(str[i]);
	}
}


/* 
 * This function transmits a number via uart
 */
void UART_transmit_number(uint16_t data)
{
	uint8_t byte_array[10];
 	uint32_t byte_array_length = int2str(data,byte_array);
	UART_transmit(byte_array,byte_array_length);
}

/* 
 * This function transmits an array of byte serially via UART
 */
void UART_transmit(uint8_t* byte_array, uint32_t byte_array_length)
{
	// Loop through each byte
	for (uint32_t i = 0; i < byte_array_length; i++) {
		// Transmit it via the UART
		uart_transmit_byte(byte_array[i]);
	}
}


/* 
 * This function transmits a byte serially via UART
 */
void uart_transmit_byte(uint8_t byte)
{
	// Wait for the UART data register empty flag
	while ((UCSR0A & 0x20) == 0) {
		;
	}
	
	// Put the byte to be sent into the data register
	UDR0 = byte;
}



/* This function takes in a 16 bit integer  
 * and converts it into an array of integer which
 * corresponds to its ascii encoding.
 *
 * e.g int a = 123
 * becomes b[3] = {"1","2","3"} 
 */

uint32_t int2str(uint16_t number, uint8_t* buffer)
{
	uint32_t i = 0;
	
	if(number == 0) buffer[0] = 0;
	while(number != 0)
	{
		buffer[i] = (number%10) + 48;
		number = number/10;
		i++;
	}
	
	/*
	uint8_t* temp = buffer;
	uint8_t idx = 0;
	for(int j = i-1 ; j >= 0 ; j--)
	{
		buffer[idx] = temp[j];
		idx++;
	}
	*/
	
	
	return i;
}