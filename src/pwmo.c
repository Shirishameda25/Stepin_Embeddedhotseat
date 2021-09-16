/**
 * @file pwmo.c
 * @author JAHNAVI JHA
 * @brief activity 3
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include<string.h>

#include"../inc/led.h"
#include"../inc/ADCREAD.h"
#include"../inc/pwmo.h"
#include"../inc/display.h"


void pwmo()
{
    unsigned volatile int ADC_val;
    DDRD |= (1<<PD6); //led

    //timer 0 configurations 
    //PD5 and PD6 pins
    
    TCCR0A |= (1<<COM0A1) | (1<<WGM01) |(1<<WGM00); //noninverting

    
    TCCR0B |= (1<<CS01) | (1<<CS00); //prescalar

    TCNT0 = 0;
    while (1)
    {
        led();
        ADC_val = ADCREAD();
        if(ADC_val > 0 && ADC_val <= 200) //Temperature conditions as specified in case study
        {
            OCR0A = 51;  //20 degrees 20% duty cycle
            display("Temperature: 20 deg C \n");
        }
        else if(ADC_val > 210 && ADC_val <= 500) //Temperature conditions as specified in case study
        {
            OCR0A = 102;  //25 degrees 40% duty cycle
         display("Temperature: 25 deg C \n");
        }
        else if(ADC_val > 510 && ADC_val <= 700) //Temperature conditions as specified in case study
        {
            OCR0A = 180;  //29 degrees 70% duty cycle
         display("Temperature: 29 deg C \n");
        }
        else if(ADC_val > 710 && ADC_val <= 1024) //Temperature conditions as specified in case study
        {
            OCR0A = 250;   //33 degrees 95% duty cycle
         display("Temperature: 33 deg C \n");
        }
        
    }
}
