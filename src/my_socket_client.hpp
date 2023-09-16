#ifndef __MY_SOCKET_CLIENT_HPP
#define __MY_SOCKET_CLIENT_HPP

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

namespace MySocket
{

    class Client {
    public:
        Client() : _port(8080) {}

        Client(int port): _port(port) {}

        int create() {
            int status, valread;
            struct sockaddr_in serv_addr;
            char* hello = "Hello from client";
            char _buffer[1024] = { 0 };
            if ((_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                printf("\n Socket creation error \n");
                return -1;
            }
        
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(_port);
        
            // Convert IPv4 and IPv6 addresses from text to binary
            // form
            if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
                <= 0) {
                printf(
                    "\nInvalid address/ Address not supported \n");
                return -1;
            }
        
            if ((status
                = connect(_fd, (struct sockaddr*)&serv_addr,
                        sizeof(serv_addr)))
                < 0) {
                printf("\nConnection Failed \n");
                return -1;
            }
            send(_fd, hello, strlen(hello), 0);
            printf("Hello message sent\n");
            valread = read(_fd, _buffer, 1024);
            printf("%s\n", _buffer);
        
            // closing the connected socket
            close(_fd);
            return 0;        
        }

    private:
        int _port;
        int _fd;

        char _buffer[1024];
    };
} // MySocket

#endif // __MY_SOCKET_CLIENT_HPP