#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H


class MotorControl
{
public:
    MotorControl();
    MotorControl(int motorEnable, int motorPin1, int motorPin2);
    void calibrate();
    void grip(int object);
    void release();

private:
    int _motorEnable, _motorPin1, _motorPin2;
};

#endif // MOTORCONTROL_H
