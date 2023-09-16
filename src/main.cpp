

#include <stdio.h>
#include <stdlib.h>

#include "my_socket_server.hpp"
#include "my_socket_client.hpp"

enum class AppMode {
    None = 0,
    Server,
    Client,
    Max
};

int server_main(int argc, char ** argv) {
    MySocket::Server server;
    server.create();
    return 0;
}

int client_main(int argc, char ** argv) {
    MySocket::Client client;
    client.create();
    return 0;
}

int main(int argc, char ** argv)
{
    if (argc < 2) {
        printf("Usage: %s client\n", argv[0]);
        printf("Usage: %s server\n", argv[0]);
        return 0;
    }

    AppMode app_mode = AppMode::None;

    if (strcmp(argv[1], "client") == 0) {
        app_mode = AppMode::Client;
    } else if (strcmp(argv[1], "server") == 0) {
        app_mode = AppMode::Server;
    }

    switch (app_mode) {
    case AppMode::Client:
        puts("This is client");
        return client_main(argc, argv);

    case AppMode::Server:
        puts("This is server");
        return server_main(argc, argv);

    default:
        return 0;
    }
    
    // MySocket::Server server;
    // server.create();
    return 0;     
}