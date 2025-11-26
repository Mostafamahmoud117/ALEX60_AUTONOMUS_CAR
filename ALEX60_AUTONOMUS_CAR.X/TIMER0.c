#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "TIMER0.h"
#include "DIO.h"

void init_Timer0(char clock, char MODE) {

    Timer0_Mode_select(MODE);

    //Start
    Timer0_clock_select(clock);

}

void Timer0_clock_select(char clock) {

    
     TCCR0 &= 0xF8;
     TCCR0 |= clock;
    
    
    
//    switch (clock) {
//
//        case TIMER0_DISABLE:
//
//            TCCR0 &= 0xF8;
//
//            break;
//
//        case TIMER0_NO_PRE:
//
//            TCCR0 |= (1 << CS00);
//
//            break;
//
//        case TIMER0_PRE_1024:
//
//            TCCR0 |= (1 << CS00);
//            TCCR0 |= (1 << CS02);
//
//            break;
//
//
//    }



}

void Timer0_Mode_select(char MODE) {

    switch (MODE) {

        case TIMER0_NORMAL:
            TCCR0 &= ~(1 << WGM00);
            TCCR0 &= ~(1 << WGM01);
      
            Timer0_OVF_INT(state_ENABLE);
            break;

        case TIMER0_CTC:
            TCCR0 &= ~(1 << WGM00);
            TCCR0 |= (1 << WGM01);
            
            OCR0 = TIMER0_OCR0; // 100
            Timer0_OCF_INT(state_ENABLE);
            break;

        case TIMER0_PWM:
            
            setPINB_DIR(OC0,OUT);   
            _delay_ms(20);
            
            TCCR0 &= ~(1 << WGM01);
            TCCR0 |= (1 << WGM00);
            
            
            OCR0 = TIMER0_OCR0; 
            break;

        case TIMER0_FPWM:
            
            setPINB_DIR(OC0,OUT);
            _delay_ms(20);
            
            TCCR0 |= (1 << WGM00);
            TCCR0 |= (1 << WGM01);
            
           OCR0 = TIMER0_OCR0; 
            break;

    }


}


void Timer0_PWM_Modes(char mode){
    
    switch(mode){
        
        case TIMER0_INV_PWM:
            TCCR0 |= (1<<COM01);
            TCCR0 &= ~(1<<COM00);
            
            break;
        
            case TIMER0_NON_INV_PWM:
            TCCR0 |= (1<<COM01);
            TCCR0 |= (1<<COM00);
            
            break;
        
            case TIMER0_NORMAL_PWM :
            TCCR0 &= ~(1<<COM01);
            TCCR0 &= ~(1<<COM00);
            
            break;
        
        
    }
    
    
    
}

void Timer0_FPWM_Modes(char mode){
    
     switch(mode){
        
        case TIMER0_INV_FPWM:
            TCCR0 |= (1<<COM01);
            TCCR0 &= ~(1<<COM00);
            
            break;
        
            case TIMER0_NON_INV_FPWM:
            TCCR0 |= (1<<COM01);
            TCCR0 |= (1<<COM00);
            
            break;
        
            case TIMER0_NORMAL_FPWM :
            TCCR0 &= ~(1<<COM01);
            TCCR0 &= ~(1<<COM00);
            
            break;
        
        
    }
}

void Timer0_OVF_INT(char state) {

    switch (state) {

        case state_ENABLE:
           
            TIMSK |= (1 << TOIE0);
            break;

        case state_DISABLE:
            
            TIMSK &= ~(1 << TOIE0);
            break;

    }


}

void Timer0_OCF_INT(char state) {

    switch (state) {

        case state_ENABLE:

            
            TIMSK |= (1 << OCIE0);
            break;

        case state_DISABLE:

         
            TIMSK &= ~(1 << OCIE0);
            break;

    }


}