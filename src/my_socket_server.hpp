#ifndef __MY_SOCKET_SERVER_HPP
#define __MY_SOCKET_SERVER_HPP

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>

#include "my_socket_error.hpp"

namespace MySocket
{
class Server {
public:
    Server() : _port(8080) {
        
    }

    Server(int port): _port(port) {}

    int create() {
        if (_fd > 0) {
            return Error::ServerAlreadyCreated;
        }

        if ((_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            return Error::ServerCreateFailed;
        }

        int new_socket, valread;
        struct sockaddr_in address;
        int addrlen = sizeof(address);

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(_port);

        // Forcefully attaching socket to the port 8080
        if (bind(_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            return Error::ServerBindFailed;
        }

        if (listen(_fd, 3) < 0) {
            return Error::ServerListenFailed;
        }

        if ((new_socket = accept(_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            return Error::ServerAcceptFailed;
        }

        valread = read(new_socket, _buffer, 1024);
        printf("%s\n", _buffer);
        char hello[32];
        sprintf(hello, "Hello from Server");
        send(new_socket, hello, strlen(hello), 0);
        printf("Hello message sent\n");
    
        // closing the connected socket
        close(new_socket);
        // closing the listening socket
        shutdown(_fd, SHUT_RDWR);
        return 0;
    }
private:
    int _port;

private:  
    int _fd;
    char _buffer[1024];
};
}





#endif // __MY_SOCKET_SERVER_HPP