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
    softPwmWrite(motorEnable, 0);

    tcp_server socket(8080);

    MotorControl mc(motorEnable, motorPin1, motorPin2, sensor, socket);

    mc.calibrate();

    softPwmWrite(motorEnable, 0);

    XMLRPC server(mc);
    server.runServer(xmlrpcPort);

    return 0;
}
