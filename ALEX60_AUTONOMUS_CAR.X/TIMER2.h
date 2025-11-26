/* 
 * File:   TIMER2.h
 * Author: arabm
 *
 * Created on September 23, 2025, 4:21 PM
 */

#ifndef TIMER2_H
#define	TIMER2_H

#define TIMER2_NORMAL 0
#define TIMER2_CTC 2
#define TIMER2_PWM 1
#define TIMER2_FPWM 3
#define TIMER2_ASYNC 4

#define state_ENABLE 1
#define state_DISABLE 0

#define TIMER2_DISABLE   0
#define TIMER2_NO_PRE    1
#define TIMER2_PRE_64  4
#define TIMER2_PRE_128 5
#define TIMER2_PRE_1024  7


#define TIMER2_NORMAL_PWM  0
#define TIMER2_INV_PWM  2
#define TIMER2_NON_INV_PWM  3

#define TIMER2_NORMAL_FPWM  0
#define TIMER2_INV_FPWM  3
#define TIMER2_NON_INV_FPWM  2

#define OC2 PD7

#define TIMER2_OCR2 100

void init_Timer2(char MODE,char clock );
void Timer2_clock_select(char clock);
void Timer2_Mode_select(char MODE);
void Timer2_OVF_INT(char state);
void Timer2_OCF_INT(char state);
void Timer2_PWM_Modes(char mode);
void Timer2_FPWM_Modes(char mode);
void init_Timer2_ASYNC_Mode(char mode,char clock);
void Timer2_CLEAR_INT();

#endif	/* TIMER2_H */

