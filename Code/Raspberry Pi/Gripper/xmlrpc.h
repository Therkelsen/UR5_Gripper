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
                std::cout << "XMLRPC: URCap successfully connected" << std::endl;

                *retvalP = xmlrpc_c::value_int(42);
            }
        };

        class SecureGrip : public xmlrpc_c::method {
        public:
            SecureGrip(MotorControl mc) {
                // signature and help strings are documentation -- the client
                // can query this information with a system.methodSignature and
                // system.methodHelp RPC.
                this->_signature = "i:i";
                // method's result and two arguments are integers
                this->_help = "Getting a grip";
                //mc = motorCtrl;
                _mc = mc;
            }
            void
            execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value* const retvalP) {
                std::cout << "XMLRPC: Gripping object" << std::endl;

                _mc.grip(500);

                *retvalP = xmlrpc_c::value_int(42);

            }
        private:
            MotorControl _mc;
        };

        class ReleaseGrip : public xmlrpc_c::method {
        public:
            ReleaseGrip(MotorControl mc) {
                // signature and help strings are documentation -- the client
                // can query this information with a system.methodSignature and
                // system.methodHelp RPC.
                this->_signature = "n:n";
                // method's result and two arguments are integers
                this->_help = "Letting go of the grip";
                //mc = motorCtrl;
                _mc = mc;
            }
            void
            execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value* const retvalP) {
                std::cout << "XMLRPC: Releasing object" << std::endl;

                _mc.calibrate();

                *retvalP = xmlrpc_c::value_int(42);
            }
        private:
            MotorControl _mc;
        };
    XMLRPC();
    XMLRPC(MotorControl mc);
    void runServer(const unsigned int port);

    MotorControl mc;
};

#endif // XMLRPC_H
