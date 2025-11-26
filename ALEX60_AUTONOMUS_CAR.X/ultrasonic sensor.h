/* 
 * File:   ultrasonic sensor.h
 * Author: arabm
 *
 * Created on November 25, 2025, 6:23 PM
 */

#ifndef ULTRASONIC_SENSOR_H
#define	ULTRASONIC_SENSOR_H

#define TRIGGER_pin PA0
#define ECHO_pin PA1
#define VCC PA2
#define GND PA3

void init_ultrasonic();
unsigned int ultrasonic_time();
unsigned int ultrasonic_get_distance_cm();
void trig_pulse();





#endif	/* ULTRASONIC_SENSOR_H */

