#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    struct addrinfo host;
    struct addrinfo *connection;
    memset(&host, 0 , sizeof host);
    host.ai_family = AF_INET;
    host.ai_socktype = SOCK_STREAM;
    host.ai_protocol = 0;
    host.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(NULL, "8080", &host, &connection);
    printf("created a connection with status: %d \n", status);

    int sock_conn = socket(connection->ai_family, connection->ai_socktype, connection->ai_protocol);
    printf("created a socket with status: %d \n", sock_conn);

    bind(sock_conn, connection->ai_addr, connection->ai_addrlen);

    //connect(sock_conn, connection->ai_addr, connection->ai_addrlen);
    listen(sock_conn, 0);

    int client_conn = accept(sock_conn, 0, 0);


    char buffer[256] = {0};

    recv(client_conn, buffer, 256, 0);
    printf("message received\n");

    printf("message receiver: %s\n", buffer);

    send(client_conn, "Hello back\n", 256, 0);

    freeaddrinfo(connection);
}

