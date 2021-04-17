#include <iostream>
#include <stdio.h>
#include <wiringPi.h>

int main()
{
    std::cout << "Enabling I/O control" << std::endl;
    wiringPiSetup();
    std::cout << "Setting pinmode" << std::endl;
    pinMode(0,OUTPUT);
    while (true) {
        std::cout << "LED on" << std::endl;
        digitalWrite(0, HIGH);
        delay(1000);
        std::cout << "LED off" << std::endl;
        digitalWrite(0, LOW);
        delay(1000);
    }
    return 0;
}

