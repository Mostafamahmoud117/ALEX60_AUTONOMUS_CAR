/* 
 * File:   TIMER0.h
 * Author: arabm
 *
 * Created on September 5, 2025, 8:41 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H

#define TIMER0_NORMAL 0
#define TIMER0_CTC 2
#define TIMER0_PWM 1
#define TIMER0_FPWM 3

#define state_ENABLE 1
#define state_DISABLE 0

#define TIMER0_DISABLE   0
#define TIMER0_NO_PRE    1
#define TIMER0_PRE_1024  5

#define TIMER0_NORMAL_PWM  0
#define TIMER0_INV_PWM  2
#define TIMER0_NON_INV_PWM  3

#define TIMER0_NORMAL_FPWM  0
#define TIMER0_INV_FPWM  3
#define TIMER0_NON_INV_FPWM  2

#define OC0 PB3

#define TIMER0_OCR0 230

void init_Timer0(char clock ,char MODE);
void Timer0_clock_select(char clock);
void Timer0_Mode_select(char MODE);
void Timer0_OVF_INT(char state);
void Timer0_OCF_INT(char state);
void Timer0_PWM_Modes(char mode);
void Timer0_FPWM_Modes(char mode);


#endif	/* TIMER0_H */

