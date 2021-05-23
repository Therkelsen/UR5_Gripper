#include "tcp_server.h"
#define PORT 8080
#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read
#include <string.h>

tcp_server::tcp_server() {}

tcp_server::tcp_server(unsigned int port) {
    this->port = port;

    std::cout << "TCP/IP: Definitions handled" << std::endl;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    std::cout << "TCP/IP: Socket created" << std::endl;

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    std::cout << "TCP/IP: Socket set" << std::endl;

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    std::cout << "TCP/IP: Socket bound" << std::endl;
}

void tcp_server::runServer(std::string string) {
    hello = new char[string.length() + 1];
    strcpy(hello, string.c_str());

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket, hello, strlen(hello), 0);
    printf("TCP/IP: String sent to client\n");
}

void tcp_server::error(const char *msg) {
    perror(msg);
    exit(1);
}
