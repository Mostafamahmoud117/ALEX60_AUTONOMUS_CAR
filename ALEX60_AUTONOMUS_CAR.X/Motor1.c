#include <avr/io.h>
#include "DIO.h"
#include "Motor1.h"

void init_Motors() {

    setPINB_DIR(MotorEN1, OUT);
    setPIND_DIR(MotorEN2, OUT);

    setPINC_DIR(MotorINPUT1, OUT);
    setPINC_DIR(MotorINPUT2, OUT);
    setPINC_DIR(MotorINPUT3, OUT);
    setPINC_DIR(MotorINPUT4, OUT);

}

void Motor1_Forward() {

    Motor1_EN();
    setPINC(MotorINPUT1, HIGH);
    setPINC(MotorINPUT2, LOW);


}

void Motor1_Backward() {

    Motor1_EN();
    setPINC(MotorINPUT1, LOW);
    setPINC(MotorINPUT2, HIGH);

}

void Motor1_EN() {

    setPINB(MotorEN1, HIGH);

}

void Motor1_DISABLE(){
    
    setPINB(MotorEN1, LOW);
}


void Motor2_Forward() {

    Motor2_EN();
    setPINC(MotorINPUT3, HIGH);
    setPINC(MotorINPUT4, LOW);


}

void Motor2_Backward() {

    Motor2_EN();
    setPINC(MotorINPUT3, LOW);
    setPINC(MotorINPUT4, HIGH);

}

void Motor2_EN() {

    setPIND(MotorEN2, HIGH);

}

void Motor2_DISABLE(){
    
    setPIND(MotorEN2, LOW);
    
}


void Motors_spin_right() {

    Motor1_Forward();
    Motor2_Backward();

}

void Motors_spin_left() {

    Motor2_Forward();
    Motor1_Backward();
}

void Motors_stop(){
    
    Motor1_DISABLE();
    Motor2_DISABLE();
    
}