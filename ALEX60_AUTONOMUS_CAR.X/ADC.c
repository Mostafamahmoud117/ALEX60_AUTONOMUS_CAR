#include <avr/io.h>
#include "ADC.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void ADC_CH_SELECT(char CH) {

    ADMUX &= 0XE0; //for the make sure of clearing

    ADMUX |= CH;

}

void ADC_REF_SELECT(char REF) {

    ADMUX &= 0x3F; //00111111

    ADMUX |= (REF << 6);

}

void ADC_EN() {

    ADCSRA |= (1 << ADEN);

}

void ADC_FREQ_SELECT(char FREQ) {

    ADCSRA &= 0xF8;

    ADCSRA |= FREQ;
}

void ADC_SC() {

    ADCSRA |= (1 << ADSC);

}

int ADC_READ() {

    return ADCW*ADC_step;

}

void ADC_WAIT() {

    while (1) {

        if (ADCSRA & (1 << ADIF)) {

            break;
        }

    }

}

void init_ADC(char CH, char REF, char FREQ) {

    ADC_CH_SELECT(CH);

    ADC_REF_SELECT(REF);

    ADC_FREQ_SELECT(FREQ);

    ADC_INT_EN();

    ADC_EN();


}

void ADC_INT_EN() {

    ADCSRA |= (1 << ADIE);

}
