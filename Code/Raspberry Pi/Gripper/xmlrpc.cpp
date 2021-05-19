#include "xmlrpc.h"

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

#include <iostream>
#include <stdexcept>

XMLRPC::XMLRPC(){}

void XMLRPC::server(const unsigned int port, int const, const char ** const){
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
                std::cout << "Secure grip - soft" << std::endl;
                break;
            case 1:
                std::cout << "Secure grip - fire" << std::endl;
                break;
            case 2:
                std::cout << "Secure grip - hard" << std::endl;
                break;
            default:
                std::cout << "ERROR - undefined value for pressure" << std::endl;
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
            std::cout << "Secure grip - soft" << std::endl;

            sleep(1);

            *retvalP = xmlrpc_c::value_int(42);
        }
    };

    std::cout << "Starting the XMLRPC server on port " << port << std::endl;
    try {
        xmlrpc_c::registry myRegistry;

        xmlrpc_c::methodPtr const areYouThere(new AreYouThere);
        xmlrpc_c::methodPtr const secureGrip(new SecureGrip);
        xmlrpc_c::methodPtr const releaseGrip(new ReleaseGrip);

        myRegistry.addMethod("are_you_there", areYouThere);
        myRegistry.addMethod("secure_grip", secureGrip);
        myRegistry.addMethod("release_grip", releaseGrip);

        xmlrpc_c::serverAbyss myAbyssServer(
            xmlrpc_c::serverAbyss::constrOpt().registryP(&myRegistry).portNumber(port)
        );

        myAbyssServer.run();    // stuck here

        //xmlrpc_c::serverAbyss.run() never returns
        //assert(false);

    } catch (exception const& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

}
