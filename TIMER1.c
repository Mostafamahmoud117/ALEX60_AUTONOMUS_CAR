#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "TIMER1.h"

void init_TIMER1(char mode, char CLOCK_SELECT) {
    
    TIMER1_MODE(mode);

// //Activate Noise Canceler
//    TCCR1A |= (1<<ICNC1);
////    // Select Rising edge at INPUT CAPTURE 
////    TCCR1A |= (1<<ICES1);
////    
    
    TIMER1_clock_SELECT(CLOCK_SELECT);
}

void TIMER1_MODE(char mode) {
    
     if(mode == TIMER1_NORMAL) {
        // Normal mode - no WGM bits set
        TCCR1A = 0;
        TCCR1B &= ~(1 << WGM12);
        
    } else if(mode == TIMER1_CTC) {
        TCCR1B |= (1 << WGM12);
        OCR1A = 15625;
    }
     else if(mode == TIMER1_PWM) {  // 
        // Fast PWM Mode 14: TOP = ICR1
        TCCR1A = (1 << COM1A1) | (1 << WGM11);  // Non-inverting, WGM11
        TCCR1B = (1 << WGM13) | (1 << WGM12);   // WGM13:12
        ICR1 = 39999;  // 50Hz (20ms period)
        OCR1A = 1500;  // Initial 1.5ms pulse (90°)
     }
    
//    // TCCR1A
//
//    // TCCR1B
//    TCCR1B |= (1<<WGM12); // CTC MODE 
//    OCR1A = 15625; // ONE second code
}

void TIMER1_clock_SELECT(char CLOCK_SELECT) {
    // TCCR1B
    TCCR1B &= 0xF8; // 11111000
    TCCR1B |= CLOCK_SELECT;
}

void Timer1_OVF_INT(char state) {
    if (state) {
        TIMSK |= (1 << TOIE1);
    } else {
        TIMSK &= ~(1 << TOIE1);
    }
}

void Timer1_OCF_INT(char state) {
    if (state) {
        TIMSK |= (1 << OCIE1A);
    } else {
        TIMSK &= ~(1 << OCIE1A);
    }
}
void Timer1_ICPF_INT(char state) {
    if (state) {
        TIMSK |= (1 << TICIE1);
    } else {
        TIMSK &= ~(1 << TICIE1);
    }
}