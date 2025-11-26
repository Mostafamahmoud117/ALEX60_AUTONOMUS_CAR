#include <avr/io.h>
#include "DIO.h"

void setPINA_DIR(char PINnum, char PinDirection) {

    //making PINnum receive or execute by PINdirection
    switch (PinDirection) {

        case OUT:
            DDRA |= (1 << PINnum);
            break;
        case IN:
            DDRA &= ~(1 << PINnum);
            break;
    }
}

void setPORTA_DIR(char PORTdir) {

    switch (PORTdir) {

        case OUT:

            DDRA = 0xFF;

        case IN:

            DDRA = 0X00;
    }


}

void setPINA(char PINnum, char state) {

    switch (state) {

        case HIGH:

            PORTA |= (1 << PINnum);
            break;

        case LOW:

            PORTA &= ~(1 << PINnum);
            break;
    }

}

void setPORTA(char state) {

    PORTA = state;

}
void togglePINA(char PINnum){
    
    PORTA ^=(1<<PINnum);
    
}
void togglePORTA(){
    
    PORTA ^= 0xFF;
    
}

char checkPINA(char PINnum){
    
    if(PINA & (1<<PINnum)){
        
        return 1;
        
    }
    else{
        
        return 0;
    }
    
    
}
char checkPORTA(){
    
    return PINA ;
}



void setPINB_DIR(char PINnum, char PinDirection) {

    //making PINnum receive or execute by PINdirection
    switch (PinDirection) {

        case OUT:
            DDRB |= (1 << PINnum);
            break;
        case IN:
            DDRB &= ~(1 << PINnum);
            break;
    }
}

void setPORTB_DIR(char PORTdir) {

    switch (PORTdir) {

        case OUT:

            DDRB = 0xFF;

        case IN:

            DDRB = 0X00;
    }


}

void setPINB(char PINnum, char state) {

    switch (state) {

        case HIGH:

            PORTB |= (1 << PINnum);
            break;

        case LOW:

            PORTB &= ~(1 << PINnum);
            break;
    }

}

void setPORTB(char state) {

    switch (state) {

        case HIGH:

            PORTB = 0xFF;
            break;

        case LOW:

            PORTB = 0X00;
            break;

    }

}
void togglePINB(char PINnum){
    
    PORTB ^=(1<<PINnum);
    
}
void togglePORTB(){
    
    PORTB ^= 0xFF;
    
}

char checkPINB(char PINnum){
    
    if(PINB & (1<<PINnum)){
        
        return 1;
        
    }
    else{
        
        return 0;
    }
    
    
}
char checkPORTB(){
    
    return PINB ;
}




void setPINC_DIR(char PINnum, char PinDirection) {

    //making PINnum receive or execute by PINdirection
    switch (PinDirection) {

        case OUT:
            DDRC |= (1 << PINnum);
            break;
        case IN:
            DDRC &= ~(1 << PINnum);
            break;
    }
}

void setPORTC_DIR(char PORTdir) {

    switch (PORTdir) {

        case OUT:

            DDRC = 0xFF;

        case IN:

            DDRC = 0X00;
    }


}

void setPINC(char PINnum, char state) {

    switch (state) {

        case HIGH:

            PORTC |= (1 << PINnum);
            break;

        case LOW:

            PORTC &= ~(1 << PINnum);
            break;
    }

}

void setPORTC(char state) {

    switch (state) {

        case HIGH:

            PORTC = 0xFF;
            break;

        case LOW:

            PORTC = 0X00;
            break;

    }

}
void togglePINC(char PINnum){
    
    PORTC ^=(1<<PINnum);
    
}
void togglePORTC(){
    
    PORTC ^= 0xFF;
    
}

char checkPINC(char PINnum){
    
    if(PINC & (1<<PINnum)){
        
        return 1;
        
    }
    else{
        
        return 0;
    }
    
    
}
char checkPORTC(){
    
    return PINC ;
}




void setPIND_DIR(char PINnum, char PinDirection) {

    //making PINnum receive or execute by PINdirection
    switch (PinDirection) {

        case OUT:
            DDRD |= (1 << PINnum);
            break;
        case IN:
            DDRD &= ~(1 << PINnum);
            break;
    }
}

void setPORTD_DIR(char PORTdir) {

    switch (PORTdir) {

        case OUT:

            DDRD = 0xFF;

        case IN:

            DDRD = 0X00;
    }


}

void setPIND(char PINnum, char state) {

    switch (state) {

        case HIGH:

            PORTD |= (1 << PINnum);
            break;

        case LOW:

            PORTD &= ~(1 << PINnum);
            break;
    }

}

void setPORTD(char state) {

    switch (state) {

        case HIGH:

            PORTD = 0xFF;
            break;

        case LOW:

            PORTD = 0X00;
            break;

    }

}
void togglePIND(char PINnum){
    
    PORTD ^=(1<<PINnum);
    
}
void togglePORTD(){
    
    PORTD ^= 0xFF;
    
}

char checkPIND(char PINnum){
    
    if(PIND & (1<<PINnum)){
        
        return 1;
        
    }
    else{
        
        return 0;
    }
    
    
}
char checkPORTD(){
    
    return PIND;
}