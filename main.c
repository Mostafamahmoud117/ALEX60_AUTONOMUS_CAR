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
#include "SERVO.h"
/*
 * 
 */

void obstcale_avoidance();

int main() {

    unsigned int distance;

    init_Motors();
    init_ultrasonic();
    init_LCD4();
    init_SERVO();
    while (1) {

        SERVO_SetAngle(90);
        _delay_ms(300);
        
        distance = ultrasonic_get_distance_cm();

        LCD4_cmd(0x01);
        LCD4_str("distance ");
        LCD4_num(distance);

        if (distance > 20) {

            LCD4_cmd(0xC0);
            LCD4_str("Moving");
            Motor1_Forward();
            Motor2_Forward();
        }
        else {

            LCD4_cmd(0xC0);
            LCD4_str("Obstacle");

            obstcale_avoidance();

        }

        _delay_ms(100);
    }

    return (EXIT_SUCCESS);
}

void obstcale_avoidance() {

    unsigned int RIGHT_distance;
    unsigned int LEFT_distance;

    //car stops

    Motors_stop();
_delay_ms(200);
    
    //car goes backwards 
    Motor1_Backward();
    Motor2_Backward();
    _delay_ms(400);

    Motors_stop();
_delay_ms(200);
    
    //scan with servo to go right

    SERVO_SetAngle(0);
    _delay_ms(300);
    

    //get distance ,, compare with safe distance 

    RIGHT_distance = ultrasonic_get_distance_cm();

    //scan with servo to go left

    SERVO_SetAngle(180);
    _delay_ms(300);
    

    //get distance ,, compare with safe distance

    LEFT_distance = ultrasonic_get_distance_cm();

    //compare distances 

    if (RIGHT_distance > LEFT_distance) {

        SERVO_SetAngle(90);
        Motors_spin_right();
        _delay_ms(300);
        Motor1_Forward();
        Motor2_Forward();

    } else if (LEFT_distance > RIGHT_distance) {

        SERVO_SetAngle(90);
        _delay_ms(300);
    
        Motors_spin_left();
        _delay_ms(400);
        Motor1_Forward();
        Motor2_Forward();

    } else {

        SERVO_SetAngle(90);
        _delay_ms(300);
    
        Motors_spin_right();
        _delay_ms(400);
        Motor1_Forward();
        Motor2_Forward();


    }

}