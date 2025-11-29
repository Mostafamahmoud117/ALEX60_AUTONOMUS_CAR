#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include "SERVO.h"
#include "DIO.h"
#include "TIMER1.h"

volatile uint16_t servo_pulse = 1500;

void init_SERVO() {

    setPIND_DIR(PD5, OUT);
    init_TIMER1(TIMER1_PWM, TIMER1_PRE_8);

}

void SERVO_SetAngle(char angle) {
    servo_pulse = 500 + ((uint32_t) angle * 2000 / 180);
    OCR1A = servo_pulse;
    
}
