/* 
 * File:   Motor1.h
 * Author: arabm
 *
 * Created on November 25, 2025, 3:41 PM
 */

#ifndef MOTOR1_H
#define	MOTOR1_H

#define MotorEN1 PB3
#define MotorEN2 PD4

#define MotorINPUT1 PC3
#define MotorINPUT2 PC4

#define MotorINPUT3 PC5
#define MotorINPUT4 PC6

void init_Motors();
void Motor1_EN();
void Motor1_DISABLE();
void Motor1_Forward();
void Motor1_Backward();

void Motor2_EN();
void Motor2_DISABLE();
void Motor2_Forward();
void Motor2_Backward();

void Motors_spin_right();
void Motors_spin_left();

void Motors_stop();

#endif	/* MOTOR1_H */

