#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "tcp_server.h"
#include <string>

class MotorControl
{
public:
    MotorControl();
    MotorControl(int motorEnable, int motorPin1, int motorPin2, int sensor, tcp_server socket);
    int calibrate();
    void grip(unsigned int time);
    void release();
    void close(unsigned int time);
    void sendString();
    void reverse(unsigned int time);
    void test();

private:
    int _motorEnable, _motorPin1, _motorPin2, _sensor, _numberOfGrips;
    std::string STATE, string;
    tcp_server socket;
};

#endif // MOTORCONTROL_H
