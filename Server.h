#ifndef Server_H
#define Server_H

#include <sys/socket.h>
#include <netinet/in.h>

struct the_Server;

typedef void (*LaunchFunction)(struct the_Server *server);

typedef struct the_Server{
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;

    struct sockaddr_in address;
    int socket;

    LaunchFunction launch;

}TheServer;

TheServer createServer(int domain, int service, int protocol, u_long interface, int port, int backlog,
    LaunchFunction launch);

#endif // Server.h
