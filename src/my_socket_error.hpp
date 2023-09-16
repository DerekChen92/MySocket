#ifndef __MY_SOCKET_ERROR_HPP
#define __MY_SOCKET_ERROR_HPP

namespace MySocket
{
enum Error {
    ServerSuccess = 0,
    ServerAlreadyCreated,
    ServerCreateFailed,
    ServerBindFailed,
    ServerListenFailed,
    ServerAcceptFailed
};
}


#endif // __MY_SOCKET_ERROR_HPP