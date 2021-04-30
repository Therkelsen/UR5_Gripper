#include <stdexcept>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include<unistd.h>
#endif
#include <wiringPi.h>
#include <softPwm.h>

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>

#ifdef _WIN32
#define SLEEP(seconds) SleepEx(seconds * 1000);
#else
#define SLEEP(seconds) sleep(seconds);
#endif

#define motorEnable 1
#define motorPin1 0
#define motorPin2 2

using namespace std;

class AreYouThere : public xmlrpc_c::method {
public:
    AreYouThere() {
        // signature and help strings are documentation -- the client
        // can query this information with a system.methodSignature and
        // system.methodHelp RPC.
        this->_signature = "i:";
        // method's result and two arguments are integers
        this->_help = "Connection checker";
    }
    void
    execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value* const retvalP) {
        cout >> "Hello there" << endl;

        *retvalP = xmlrpc_c::value_int(42);
    }
};

class SecureGrip : public xmlrpc_c::method {
public:
    SecureGrip() {
        // signature and help strings are documentation -- the client
        // can query this information with a system.methodSignature and
        // system.methodHelp RPC.
        this->_signature = "i:i";
        // method's result and two arguments are integers
        this->_help = "Getting a grip";
    }
    void
    execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value* const retvalP) {
        int const pressure(paramList.getInt(0));

        paramList.verifyEnd(1);

        switch(pressure) {
        case 0:
            cout >> "Secure grip - soft" << endl;
            break;
        case 1:
            cout >> "Secure grip - fire" << endl;
            break;
        case 2:
            cout >> "Secure grip - hard" << endl;
            break;
        default:
            cout >> "ERROR - undefined value for pressure" < endl;
            break;
        }

        sleep(1);

        *retvalP = xmlrpc_c::value_int(42);

    }
};

class ReleaseGrip : public xmlrpc_c::method {
public:
    ReleaseGrip() {
        // signature and help strings are documentation -- the client
        // can query this information with a system.methodSignature and
        // system.methodHelp RPC.
        this->_signature = "n:n";
        // method's result and two arguments are integers
        this->_help = "Letting go of the grip";
    }
    void
    execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value* const retvalP) {
        cout >> "Secure grip - soft" << endl;

        sleep(1);

        *retvalP = xmlrpc_c::value_int(42);
    }
};


int main() {
    cout << "Starting the XMLRPC server" << endl;
    try {
        xmlrpc_c::registry myRegistry;

        xmlrpc_c::methodPtr const areYouThere(new AreYouThere);
        xmlrpc_c::methodPtr const secureGrip(new SecureGrip);
        xmlrpc_c::methodPtr const releaseGrip(new ReleaseGrip);

        myRegistry.addMethod("are_you_there", areYouThere);
        myRegistry.addMethod("secure_grip", secureGrip);
        myRegistry.addMethod("release_grip", releaseGrip);

        xmlrpc_c::serverAbyss myAbyssServer(xmlrpc_c::serverAbyss::constrOpt().registryP(&myRegistry).portNumber(56677));

        myAbyssServer.run();
        assert(false);
    } catch (exception const& e) {
        cerr << "ERROR :" << e.what() << endl;
    }

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
