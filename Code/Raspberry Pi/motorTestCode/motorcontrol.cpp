#include "motorcontrol.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>

MotorControl::MotorControl(){};

MotorControl::MotorControl(int motorEnable, int motorPin1, int motorPin2, int sensor) {
    _motorEnable = motorEnable;
    _motorPin1 = motorPin1;
    _motorPin2 = motorPin2;
    _sensor = sensor;

    wiringPiSetup();

    std::cout << "MotorControl: Inclusions and definitions handled" << std::endl;

    pinMode(motorEnable,OUTPUT);
    pinMode(_motorPin1,OUTPUT);
    pinMode(_motorPin2,OUTPUT);
    pinMode(_sensor, INPUT);

    softPwmCreate(_motorEnable,35,100);

    std::cout << "GPIO access has been set up" << std::endl;

}

void MotorControl::calibrate(){
    //  Reverse polarity to run motor backwards
    digitalWrite(_motorPin1, HIGH);
    digitalWrite(_motorPin2, LOW);

    //  Run motor backwards until sensor is pressed
    while(digitalRead(_sensor != HIGH)) {
        softPwmWrite(_motorEnable,65);
    }
    softPwmWrite(_motorEnable, 0);

    //  Forwards polarity to prepare for gripping an object
    digitalWrite(_motorPin1, LOW);
    digitalWrite(_motorPin2, HIGH);
}

void MotorControl::grip(unsigned int object){
    //  Calibrate gripper
    calibrate();
    //  Run motor for x seconds, to grip can

    softPwmWrite(_motorEnable,100);
    delay(object);
    softPwmWrite(_motorEnable, 0);
}

void MotorControl::release(){
    //  Just calls calibrate, is called release for semantic reasons
    calibrate();
}

void MotorControl::close(int time) {
    softPwmWrite(_motorEnable,100);
    delay(time);
    softPwmWrite(_motorEnable, 0);
}
