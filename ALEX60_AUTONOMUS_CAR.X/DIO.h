/* 
 * File:   DIO.h
 * Author: arabm
 *
 * Created on August 9, 2025, 7:36 AM
 */

#ifndef DIO_H
#define	DIO_H
#define OUT 1
#define IN 0
#define HIGH 1
#define LOW 0
void setPINA_DIR(char PINnum ,char PinDirection);
void setPORTA_DIR(char PORTdir);
void setPINA(char PINnum,char state);
void setPORTA(char state);
void togglePINA(char PINnum);
void togglePORTA();
char checkPINA(char PINnum);
char checkPORTA();

void setPINB_DIR(char PINnum ,char PinDirection);
void setPORTB_DIR(char PORTdir);
void setPINB(char PINnum,char state);
void setPORTB(char state);
void togglePINB(char PINnum);
void togglePORTB();
char checkPINB(char PINnum);
char checkPORTB();

void setPINC_DIR(char PINnum ,char PinDirection);
void setPORTC_DIR(char PORTdir);
void setPINC(char PINnum,char state);
void setPORTC(char state);
void togglePINC(char PINnum);
void togglePORTC();
char checkPINC(char PINnum);
char checkPORTC();

void setPIND_DIR(char PINnum ,char PinDirection);
void setPORTD_DIR(char PORTdir);
void setPIND(char PINnum,char state);
void setPORTD(char state);
void togglePIND(char PINnum);
void togglePORTD();
char checkPIND(char PINnum);
char checkPORTD();

#endif	/* DIO_H */

