#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"
#include "ultrasonic sensor.h"
#include "TIMER1.h"

void init_ultrasonic() {

    setPINA_DIR(TRIGGER_pin, OUT);
    setPINA_DIR(ECHO_pin, IN);


    _delay_ms(10);

    init_TIMER1(TIMER1_NORMAL,TIMER1_PRE_8);
}

unsigned int ultrasonic_time() {
    unsigned int echo_time;
    unsigned long timeout;
    
    trig_pulse();
    
    // Step 2: Wait for ECHO to go HIGH
    timeout = 0;
    while(checkPINA(ECHO_pin) == LOW) {
        timeout++;
        if(timeout > 30000) return 0;
    }
    
    // Step 3: Start timer
    TCNT1 = 0;
    
    // Step 4: Wait for ECHO to go LOW
    timeout = 0;
    while(checkPINA(ECHO_pin) == HIGH) {
        timeout++;
        if(timeout > 30000) return 0;
    }
    
    // Step 5: Read timer
    echo_time = TCNT1;
    
    return echo_time;
    }


    void trig_pulse() {

        setPINA(TRIGGER_pin, LOW);
        _delay_us(3);
        setPINA(TRIGGER_pin, HIGH);
        _delay_us(10);
        setPINA(TRIGGER_pin, LOW);

    };

unsigned int ultrasonic_get_distance_cm() {
    unsigned int echo_time;
    unsigned int distance;
    
    // Get echo time in timer ticks
    echo_time = ultrasonic_time();
    
    if(echo_time == 0) {
        return 0;  // Error or out of range
    }
    
    // Convert to distance
    // With NO prescaler (TIMER1_NO_PRE) and F_CPU = 16MHz:
    // Each tick = 1/16MHz = 0.0625 microseconds
    // echo_time_us = echo_time * 0.0625
    // distance_cm = echo_time_us / 58
    // distance_cm = (echo_time * 0.0625) / 58
    // distance_cm = echo_time / 928
    
    distance = echo_time / 116;  // For no prescaler
    
    // If you use prescaler 8 (TIMER1_PRE_8):
    // Each tick = 0.5 microseconds
    // distance = echo_time / 116;
    
    return distance;
}
