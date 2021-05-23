#include "motorcontrol.h"
#include "xmlrpc.h"
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "tcp_server.h"

#define motorEnable 1
#define motorPin1 0
#define motorPin2 2
#define sensor 12
#define xmlrpcPort 12345
#define tcpipPort 8080

using namespace std;

int main() {
    softPwmStop(motorEnable);

    tcp_server socket(tcpipPort);

    MotorControl mc(motorEnable, motorPin1, motorPin2, sensor, socket);

    delay(10000);

    while (true) {
        mc.grip(500);

        delay(2500);

        mc.release();
    }

    softPwmWrite(motorEnable, 0);

    XMLRPC server(mc);
    //server.runServer(xmlrpcPort);

    return 0;
}
