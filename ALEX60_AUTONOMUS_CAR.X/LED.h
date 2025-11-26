/* 
 * File:   LED.h
 * Author: arabm
 *
 * Created on August 8, 2025, 8:05 PM
 */

#ifndef LED_H
#define	LED_H

#define LED1 3 //PB3
#define LED2 2  //PC2
#define LED3 7  //PC7
#define LED4 6  //PD6

void init_led();
void led_on(char lednum);
void led_off(char lednum);
void led_toggle(char lednum);

void led_all_on();
void led_all_off();
void led_all_toggle();

#endif	/* LED_H */

