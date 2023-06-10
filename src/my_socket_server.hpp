#ifndef __MY_SOCKET_SERVER_HPP
#define __MY_SOCKET_SERVER_HPP

#include <sys/socket.h>

#include "my_socket_error.hpp"


namespace MySocket
{
class Server {
    public:
    	Server() {
    		
    	}

        int create() {
            if (_fd > 0) {
                return Error::ServerCreated;
            }
        }
    private:  
        int _fd;
};
}





#endif // __MY_SOCKET_SERVER_HPP