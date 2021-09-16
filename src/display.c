/**
 * @file display.c
 * @author JAHNAVI JHA
 * @brief Activity 4
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<avr/io.h>
#include<string.h>
#include "display.h"

#define BAUD 9600
#define F_CPU 16000000
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

void USART_init()
{
    
    UBRR0H = (BAUDRATE>>8); //baudrate set
    UBRR0L = BAUDRATE;
    
    UCSR0C = (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);

    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0);//receiver transmitter
}

char USART_read()  //read
{
    while( !(UCSR0A & (1<<RXC0)) );
    return UDR0;
}

void USART_write(char data)  //write
{
    while( !(UCSR0A & (1<<UDRE0)) );
    UDR0 = data;
}

void write_string(char *string)
{
    int count;
    int len_string = strlen(string);
    for(count = 0 ; count < len_string; count++)
    {
        USART_write(*(string+count));
    }
}


void display(char *data) //function
{
  
    USART_init();
    write_string(data);
}
