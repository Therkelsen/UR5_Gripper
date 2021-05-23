#include "xmlrpc.h"

#include <iostream>
#include <stdexcept>

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

XMLRPC::XMLRPC(){}

XMLRPC::XMLRPC(MotorControl mc){
    _mc = mc;
}

void XMLRPC::runServer(const unsigned int port){

    std::cout << "Starting the XMLRPC server on port " << port << std::endl;

    try {
        xmlrpc_c::registry myRegistry;

        xmlrpc_c::methodPtr const areYouThere(new AreYouThere);
        xmlrpc_c::methodPtr const secureGrip(new SecureGrip(_mc));
        xmlrpc_c::methodPtr const releaseGrip(new ReleaseGrip(_mc));

        myRegistry.addMethod("are_you_there", areYouThere);
        myRegistry.addMethod("secure_grip", secureGrip);
        myRegistry.addMethod("release_grip", releaseGrip);

        xmlrpc_c::serverAbyss myAbyssServer(
            xmlrpc_c::serverAbyss::constrOpt().registryP(&myRegistry).portNumber(port)
        );

        myAbyssServer.run();    // stuck here

        //xmlrpc_c::serverAbyss.run() never returns
        //assert(false);

    } catch (std::exception const& e) {
        std::cerr << "XMLRPC ERROR: " << e.what() << std::endl;
    }
}
