#include "motorcontrol.h"
#include <wiringPi.h>
#include <softPwm.h>

MotorControl::MotorControl(){};

MotorControl::MotorControl(int motorEnable, int motorPin1, int motorPin2) {
    _motorEnableClock = motorEnable;
    _motorEnableCounter = motorPin1;
    _motorPin2 = motorPin2;

    wiringPiSetup();

    std::cout << "MotorControl: Inclusions and definitions handled" << std::endl;

    pinMode(motorEnable,OUTPUT);
    pinMode(_motorPin1,OUTPUT);
    pinMode(_motorPin2,OUTPUT);

    softPwmCreate(_motorEnable,35,100);

    std::cout << "GPIO access has been set up" << std::endl;

}

void MotorControl::calibrate(){
    //  Reverse polarity to run motor backwards
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);

    //  Run motor backwards until sensor is pressed
    while(sensor != true) {
        softPwmWrite(_motorEnable,100);
    }

    //  Forwards polarity to prepare for gripping an object
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
}

void MotorControl::grip(int object){
    //  Calibrate gripper
    calibrate();
    //  Run motor for x seconds, to grip can

    softPwmWrite(_motorEnable,100);
    delay(object);
    softPwmStop(_motorEnable);
}

void MotorControl::release(){
    //  Just calls calibrate, is called release for semantic reasons
    calibrate();
}

/*
    cout << "Driving motor with 100% power for 5 seconds" << endl;
    softPwmWrite(motorEnable,100);

    delay(5000);

    cout << "Stopping motor" << endl;
    softPwmStop(motorEnable);
*/
