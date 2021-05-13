#include <iostream>
#include "softPwm.h"
#include "wiringPi.h"
#include "motorcontrol.h"

#define motorEnable 1
#define motorPin1 0
#define motorPin2 2
#define sensor 3

static const unsigned int beerCan = 1000;
static const unsigned int closeTime = 2500;

int main() {
    MotorControl mc(motorEnable, motorPin1, motorPin2, sensor);

    mc.grip(beerCan);

    while (true) {
        if (digitalRead(sensor) != HIGH) {
            mc.grip(beerCan);
        } else {
            mc.release();
        }
    }

    mc.close(closeTime);

    /*
    wiringPiSetup();

    std::cout << "MotorControl: Inclusions and definitions handled" << std::endl;

    pinMode(motorEnable,OUTPUT);
    pinMode(motorPin1,OUTPUT);
    pinMode(motorPin2,OUTPUT);
    pinMode(sensor, INPUT);

    softPwmCreate(motorEnable,35,100);

    std::cout << "MotorControl: GPIO access has been set up" << std::endl;

    while(true) {
        if (digitalRead(sensor != HIGH)) {
            digitalWrite(motorPin1, LOW);
            digitalWrite(motorPin2, HIGH);
            softPwmWrite(motorEnable,100);
            delay(1000);
            softPwmWrite(motorEnable, 0);
            digitalWrite(motorPin1, HIGH);
            digitalWrite(motorPin2, LOW);
            softPwmWrite(motorEnable,100);
            delay(1000);
            softPwmWrite(motorEnable, 0);
        }
    }
    */
}
