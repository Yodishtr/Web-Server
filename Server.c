#include "Server.h"

TheServer createServer(int domain, int service, int protocol, u_long interface, int port, int backlog, 
    void (*launch)(void)){
        TheServer server;
        server.domain = domain;
        server.service = service;
        server.protocol = protocol;
        server.interface = interface;
        server.port = port;
        server.backlog = backlog;

        server.address.sin_family = domain;
        server.address.sin_port = htons(port);
        server.address.sin_addr.s_addr = htonl(interface);

        server.socket = socket(domain, service, protocol);
        if (server.socket == 0){
            perror("socket");
            exit(1);
        }

        int binding = bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address));
        if (binding < 0){
            perror("bind");
            exit(1);
        }

        int listening = listen(server.socket, backlog);
        if (listening < 0){
            perror("listen");
            exit(1);
        }

        server.launch = launch;

        return server;
    }