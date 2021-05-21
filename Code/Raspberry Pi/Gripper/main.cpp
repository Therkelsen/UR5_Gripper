#include "motorcontrol.h"
#include "xmlrpc.h"
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

#define motorEnable 1
#define motorPin1 0
#define motorPin2 2
#define sensor 12

using namespace std;

unsigned int beerCan = 100;

int main() {
    softPwmStop(motorEnable);
    MotorControl mc(motorEnable, motorPin1, motorPin2, sensor);

    //mc.grip(500);
    //test();
    //mc.grip(4000);
    //mc.grip(1000);
    softPwmStop(motorEnable);



    XMLRPC server(mc);
    server.runServer(12345);


    //mc.grip(800);
    //mc.calibrate();
    //mc.test();






    /*
    while(true){
        if(server.getState() == "grip"){
            mc.grip(beerCan);
        }
        if(server.getState() == "release"){
            mc.release();
        }
    }*/
    return 0;
}
