#ifndef Server.h;
#define Server.h

#include <sys/socket.h>
#include <netinet/in.h>

typedef struct TheServer{
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;

    struct sockaddr_in address;
    int socket;

    void (*launch)(void);

} TheServer;

TheServer createServer(int domain, int service, int protocol, u_long interface, int port, int backlog,
    void (*launch)(void));

#endif // Server.h
