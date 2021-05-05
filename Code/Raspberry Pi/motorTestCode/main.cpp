
#include <iostream>
#include "motorcontrol.h"

#define motorEnable 1
#define motorPin1 0
#define motorPin2 2

int beerCan = 1000;

using namespace std;

int main() {
    MotorControl mc(motorEnable, motorPin1, motorPin2);

    mc.grip(beerCan);

    return 0;
}
