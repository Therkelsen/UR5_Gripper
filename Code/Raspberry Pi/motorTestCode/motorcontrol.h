#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H


class MotorControl
{
public:
    MotorControl();
    MotorControl(int motorEnable, int motorPin1, int motorPin2, int sensor);
    void calibrate();
    void grip(unsigned int object);
    void release();
    void close(int time);

private:
    int _motorEnable, _motorPin1, _motorPin2, _sensor;
};

#endif // MOTORCONTROL_H
