#include <stdio.h>
#include "Server.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


void launch(TheServer *server){
    char buffer[3000];
    printf("Waiting for connections...\n");
    int address_length = sizeof(server->address);
    int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);
    read(new_socket, buffer, 3000);
    printf("%s\n", buffer);
    char *response = "HTTP/1.1 200 OK\n\nHello World";
    write(new_socket, response, strlen(response));
    close(new_socket);

}

int main(){
    TheServer server = createServer(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
    server.launch(&server);
    return 0;
}