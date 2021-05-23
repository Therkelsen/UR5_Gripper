#ifndef XMLRPC_H
#define XMLRPC_H
#include <string>
#include <iostream>
#include "motorcontrol.h"

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>

#ifdef _WIN32
#define SLEEP(seconds) SleepEx(seconds * 1000);
#else
#define SLEEP(seconds) sleep(seconds);
#endif

#ifdef _WIN32
#include <windows.h>
#else
#include<unistd.h>
#endif

class XMLRPC
{
public:
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
                std::cout << "Hello there" << std::endl;

                *retvalP = xmlrpc_c::value_int(42);
            }
        };

        class SecureGrip : public xmlrpc_c::method {
        public:
            SecureGrip(MotorControl motorCtrl) {
                // signature and help strings are documentation -- the client
                // can query this information with a system.methodSignature and
                // system.methodHelp RPC.
                this->_signature = "i:i";
                // method's result and two arguments are integers
                this->_help = "Getting a grip";
                //mc = motorCtrl;
                mc = motorCtrl;
            }
            void
            execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value* const retvalP) {
                std::cout << "grip" << std::endl;

                mc.grip(500);

                *retvalP = xmlrpc_c::value_int(42);

            }
        private:
            MotorControl mc;
        };

        class ReleaseGrip : public xmlrpc_c::method {
        public:
            ReleaseGrip(MotorControl motorCtrl) {
                // signature and help strings are documentation -- the client
                // can query this information with a system.methodSignature and
                // system.methodHelp RPC.
                this->_signature = "n:n";
                // method's result and two arguments are integers
                this->_help = "Letting go of the grip";
                //mc = motorCtrl;
                mc = motorCtrl;
            }
            void
            execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value* const retvalP) {
                std::cout << "release" << std::endl;

                mc.calibrate();

                *retvalP = xmlrpc_c::value_int(42);
            }
        private:
            MotorControl mc;
        };
    XMLRPC();
    XMLRPC(MotorControl motorCtrl);
    void runServer(const unsigned int port);

    MotorControl mc;
};

#endif // XMLRPC_H
