#include "motorcontrol.h"
#include "tcp_server.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
#include <sstream>

MotorControl::MotorControl(){};

MotorControl::MotorControl(int motorEnable, int motorPin1, int motorPin2, int sensor, tcp_server socket) {
    _motorEnable = motorEnable;
    _motorPin1 = motorPin1;
    _motorPin2 = motorPin2;
    _sensor = sensor;

    _numberOfGrips = 0;
    STATE = "SETUP";

    this->socket = socket;

    wiringPiSetup();

    std::cout << "MotorControl: Inclusions and definitions handled" << std::endl;

    pinMode(_motorEnable,OUTPUT);
    pinMode(_motorPin1,OUTPUT);
    pinMode(_motorPin2,OUTPUT);
    pinMode(_sensor, INPUT);

    softPwmCreate(_motorEnable,35,100);

    std::cout << "MotorControl: GPIO access has been set up" << std::endl;

    std::stringstream ss;
    ss << _numberOfGrips;
    ss >> string;
    string.append(", ");
    string.append(STATE);

    socket.runServer(string);
}

int MotorControl::calibrate(){
    std::cout << "MotorControl: Calibrating gripper" << std::endl;
    STATE = " CALIBRATE";
    while (true) {
        if (digitalRead(_sensor) == HIGH) {
            digitalWrite(_motorPin1, HIGH);
            digitalWrite(_motorPin2, LOW);
            softPwmWrite(_motorEnable, 100);
        } else {
            softPwmWrite(_motorEnable,0);
            digitalWrite(_motorPin1, LOW);
            digitalWrite(_motorPin2, HIGH);

            //sendString();
            return 0;
        }
    }
}

void MotorControl::grip(unsigned int time){
    std::cout << "MotorControl: Gripping object" << std::endl;

    //  Calibrate gripper
    calibrate();

    STATE = "GRIP";
    _numberOfGrips++;

    //  Run motor for x seconds, to grip can
    softPwmWrite(_motorEnable,100);
    delay(time);
    softPwmWrite(_motorEnable,0);
    sendString();
}

void MotorControl::release(){
    //  Just calls calibrate, is called release for semantic reasons
    calibrate();
}

void MotorControl::close(unsigned int time) {
    std::cout << "MotorControl: Closing gripper" << std::endl;
    softPwmWrite(_motorEnable,100);
    delay(time);
    softPwmWrite(_motorEnable,0);
    STATE = "CLOSE";
    sendString();
}

void MotorControl::sendString() {
    std::cout << "MotorControl: Sending status string" << std::endl;
    std::stringstream ss;
    ss << _numberOfGrips;
    ss >> string;
    string.append(", ");
    string.append(STATE);

    std::cout << "String: " << string << std::endl;

    socket.runServer(string);
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
