#include <iostream>
#include <stdio.h>
#include <wiringPi.h>

int main()
{
    int led = 13;
    std::cout << "Enabling I/O control" << std::endl;
    wiringPiSetup();
    std::cout << "Setting pinmode" << std::endl;
    pinMode(led,OUTPUT);
    while (true) {
        std::cout << "LED on" << std::endl;
        digitalWrite(led, HIGH);
        delay(5000);
        std::cout << "LED off" << std::endl;
        digitalWrite(led, LOW);
        delay(5000);
    }
    return 0;
}

