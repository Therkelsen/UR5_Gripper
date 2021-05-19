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

    softPwmWrite(motorEnable,HIGH);
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);

    delay(5000);

    softPwmWrite(motorEnable,LOW);

    return 0;
}
