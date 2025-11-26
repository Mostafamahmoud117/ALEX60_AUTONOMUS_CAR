/* 
 * File:   ADC.h
 * Author: arabm
 *
 * Created on August 29, 2025, 6:11 PM
 */

#ifndef ADC_H
#define	ADC_H

#define ADC_CH0 0 
#define ADC_CH1 1
#define ADC_CH2 2
#define ADC_CH3 3
#define ADC_CH4 4
#define ADC_CH5 5
#define ADC_CH6 6
#define ADC_CH7 7

#define ADC_AREF 0
#define ADC_AVCC 1
#define ADC_V_2_56 3

#define ADC_PRE_128 7

#define ADC_step  4.8828125 //4.8875855327468230694037145650049


void init_ADC(char CH ,char REF ,char FREQ);

void ADC_CH_SELECT(char CH);
void ADC_REF_SELECT(char REF);
void ADC_FREQ_SELECT(char FREQ);
void ADC_EN();
void ADC_SC();
int ADC_READ();
void ADC_WAIT();
void ADC_INT_EN();

#endif	/* ADC_H */

