
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

#define motorEnable 1
#define motorPin1 0
#define motorPin2 2

using namespace std;

int main() {
    cout << "Inclusions and definitions handled" << endl;

    wiringPiSetup();

    pinMode(motorPin1,OUTPUT);
    pinMode(motorPin2,OUTPUT);
    pinMode(motorEnable,OUTPUT);

    softPwmCreate(motorEnable,0,100);
    cout << "GPIO access has been set up" << endl;

    cout << "Driving motor with 100% power for 5 seconds" << endl;
    softPwmWrite(motorEnable,100);

    delay(5000);

    cout << "Stopping motor" << endl;
    softPwmStop(motorEnable);

    return 0;
}
