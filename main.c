/* 
 * File:   main.c
 * Author: arabm
 *
 * Created on November 26, 2025, 12:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#define F_CPU 16000000UL        
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Motor1.h"
#include "TIMER1.h"
#include "ultrasonic sensor.h"
#include "DIO.h"
#include "MLCD4.h"
/*
 * 
 */
int main() {

    init_LCD4();
    
    while(1){
        
       LCD4_data('A'); 
        
        
    }
    
    return (EXIT_SUCCESS);
}

