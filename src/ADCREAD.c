/**
 * @file ADCREAD.c
 * @author JAHNAVI JHA
 * @brief Activity 2
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include "ADCREAD.h"

uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0xf8; //ADC Channel Selection
    ch=ch & 0b00000111;
    ADMUX|=ch;

    ADCSRA|=(1<<ADSC);//for conversion
    

    while(!(ADCSRA & (1<<ADIF))); //Wait for conversion
    //Clear ADIF 
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

int ADCREAD()
{
int value=0;
InitADC();
value=ReadADC(0);
return value;

}
void InitADC()
{
    ADMUX=(1<<REFS0); //Resolution
    ADCSRA=(1<<ADEN)|(7<<ADPS0); //enable ADC AND PRESCALAR
}

