#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "TIMER2.h"
#include "DIO.h"

void init_Timer2(char MODE,char clock ) {

    Timer2_Mode_select(MODE);

    //Start
    Timer2_clock_select(clock);

}

void Timer2_clock_select(char clock) {


    TCCR2 &= 0xF8;
    TCCR2 |= clock;



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

void Timer2_Mode_select(char MODE) {

    switch (MODE) {

        case TIMER2_NORMAL:
            TCCR2 &= ~(1 << WGM20);
            TCCR2 &= ~(1 << WGM21);

            Timer2_OVF_INT(state_ENABLE);
            break;

        case TIMER2_CTC:
            TCCR2 &= ~(1 << WGM20);
            TCCR2 |= (1 << WGM21);

            OCR2 = TIMER2_OCR2; // 100
            Timer2_OCF_INT(state_ENABLE);
            break;

        case TIMER2_PWM:

            setPIND_DIR(OC2, OUT);
            _delay_ms(20);

            TCCR2 &= ~(1 << WGM21);
            TCCR2 |= (1 << WGM20);


            OCR2 = TIMER2_OCR2;
            break;

        case TIMER2_FPWM:

            setPIND_DIR(OC2, OUT);
            _delay_ms(20);

            TCCR2 |= (1 << WGM20);
            TCCR2 |= (1 << WGM21);

            OCR2 = TIMER2_OCR2;
            break;



    }


}

void Timer2_PWM_Modes(char mode) {

    switch (mode) {

        case TIMER2_INV_PWM:
            TCCR2 |= (1 << COM21);
            TCCR2 &= ~(1 << COM20);

            break;

        case TIMER2_NON_INV_PWM:
            TCCR2 |= (1 << COM21);
            TCCR2 |= (1 << COM20);

            break;

        case TIMER2_NORMAL_PWM:
            TCCR2 &= ~(1 << COM21);
            TCCR2 &= ~(1 << COM20);

            break;


    }



}

void Timer2_FPWM_Modes(char mode) {

    switch (mode) {

        case TIMER2_INV_FPWM:
            TCCR2 |= (1 << COM21);
            TCCR2 &= ~(1 << COM20);

            break;

        case TIMER2_NON_INV_FPWM:
            TCCR2 |= (1 << COM21);
            TCCR2 |= (1 << COM20);

            break;

        case TIMER2_NORMAL_FPWM:
            TCCR2 &= ~(1 << COM21);
            TCCR2 &= ~(1 << COM20);

            break;


    }
}

void Timer2_OVF_INT(char state) {

    switch (state) {

        case state_ENABLE:

            TIMSK |= (1 << TOIE2);
            break;

        case state_DISABLE:

            TIMSK &= ~(1 << TOIE2);
            break;

    }


}

void Timer2_OCF_INT(char state) {

    switch (state) {

        case state_ENABLE:


            TIMSK |= (1 << OCIE2);
            break;

        case state_DISABLE:


            TIMSK &= ~(1 << OCIE2);
            break;

    }


}

void init_Timer2_ASYNC_Mode(char mode,char clock) {

    Timer2_OCF_INT(state_DISABLE);
    Timer2_OVF_INT(state_DISABLE);

    ASSR |= (1 << AS2);

    TCNT2 = 0;
    OCR2 = TIMER2_OCR2;

    Timer2_Mode_select(mode);
    
    Timer2_clock_select(clock);

    while (ASSR & (1 << TCN2UB));
    while (ASSR & (1 << TCR2UB));
    while (ASSR & (1 << OCR2UB));

    Timer2_CLEAR_INT();

    Timer2_OVF_INT(state_ENABLE);

    // Timer2_OCF_INT(state_ENABLE);


}

void Timer2_CLEAR_INT() {

    TIFR &= ~((1 << TOV2) | (1 << OCF2));


}