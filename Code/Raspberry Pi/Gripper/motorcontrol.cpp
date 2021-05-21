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

int MotorControl::calibrate(){
    while (true) {
        if (digitalRead(_sensor) == HIGH) {
            digitalWrite(_motorPin1, HIGH);
            digitalWrite(_motorPin2, LOW);
            softPwmWrite(_motorEnable, 100);
            //std::cout << "HIGH" << std::endl;
        } else {
            softPwmWrite(_motorEnable,0);
            digitalWrite(_motorPin1, LOW);
            digitalWrite(_motorPin2, HIGH);
            //std::cout << "LOW" << std::endl;
            return 0;
        }
    }
}

void MotorControl::grip(unsigned int time){
    //  Calibrate gripper
    calibrate();

    //  Run motor for x seconds, to grip can
    softPwmWrite(_motorEnable,100);
    delay(time);
    softPwmWrite(_motorEnable,0);
}

void MotorControl::release(){
    //  Just calls calibrate, is called release for semantic reasons
    calibrate();
}

void MotorControl::close(unsigned int time) {
    softPwmWrite(_motorEnable,100);
    delay(time);
    softPwmWrite(_motorEnable,0);
}

void MotorControl::reverse(unsigned int time){
    digitalWrite(_motorPin1, HIGH);
    digitalWrite(_motorPin2, LOW);
    softPwmWrite(_motorEnable,100);
    delay(time);
    digitalWrite(_motorPin1, LOW);
    digitalWrite(_motorPin2, HIGH);
    softPwmWrite(_motorEnable,0);
}

void MotorControl::test(){
    while (true) {
        if (digitalRead(_sensor) != HIGH) {
            std::cout << "HIGH" << std::endl;
        } else {
            std::cout << "LOW" << std::endl;
        }
    }
}
