#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H


class MotorControl
{
public:
    MotorControl();
    MotorControl(int motorEnable, int motorPin1, int motorPin2, int sensor);
    int calibrate();
    void grip(unsigned int time);
    void release();
    void close(unsigned int time);
    void reverse(unsigned int time);
    void test();

private:
    int _motorEnable, _motorPin1, _motorPin2, _sensor;
};

#endif // MOTORCONTROL_H
