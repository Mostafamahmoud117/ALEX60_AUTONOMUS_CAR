/* 
 * File:   TIMER1.h
 * Author: arabm
 *
 * Created on November 25, 2025, 7:18 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H

#define TIMER1_NORMAL  0
#define TIMER1_CTC     1
#define TIMER1_PWM     2
#define TIMER1_FPWM    3
#define TIMER1_PRE_8     2 


#define state_ENABLE     1
#define state_DISABLE    0




#define TIMER1_DISABLE   0
#define TIMER1_NO_PRE    1
#define TIMER1_PRE_1024  5


void init_TIMER1(char mode, char CLOCK_SELECT);

void TIMER1_MODE(char mode);
void TIMER1_clock_SELECT(char CLOCK_SELECT);

void Timer1_OVF_INT(char state);
void Timer1_OCF_INT(char state);
void Timer1_ICPF_INT(char state);

#endif	/* TIMER1_H */

//SERVO_SetAngle(0); // Move to 0°
//                _delay_ms(1000.0); // Safe double argument
//
//                SERVO_SetAngle(90); // Move to 90°
//                _delay_ms(1000.0);
//
//                SERVO_SetAngle(180); // Move to 180°
//                _delay_ms(1000.0);