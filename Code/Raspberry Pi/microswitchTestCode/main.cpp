
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

int main() {

    int sensor = 3;

    wiringPiSetup();
    pinMode(sensor, INPUT);

    while (true) {
        if (digitalRead(sensor) == HIGH) {
            cout << "HIGH" << endl;
        } else {
            cout << "LOW" << endl;
        }
    }
}
