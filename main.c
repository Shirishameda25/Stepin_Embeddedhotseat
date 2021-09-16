/**
 * @file main.c
 * @author SHIRISHAMEDA
 * @brief main file for all activities
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include"./inc/led.h"
#include"./inc/user_utils.h"
#include"./inc/ADCREAD.h"
#include"./inc/pwmo.h"
#include"./inc/display.h"

void led();
int main(void)
{
    while(1)
    {
        pwmo();
    }
    return 0;
}