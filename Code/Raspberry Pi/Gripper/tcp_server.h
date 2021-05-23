#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read
#include <string.h>

class tcp_server {
public:
    tcp_server();
    tcp_server(unsigned int port);
    void runServer(std::string string);
    void error(const char *msg);
private:
    unsigned int ip;
    unsigned int port;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = strdup("");
};

#endif // TCP_SERVER_H
