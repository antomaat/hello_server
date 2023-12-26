//#include <csignal>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct addrinfo host;
    struct addrinfo *connection;
    int status;

    memset(&host, 0 , sizeof host);
    host.ai_family = AF_INET;
    host.ai_socktype = SOCK_STREAM;
    host.ai_protocol = 0;
    host.ai_flags = AI_PASSIVE;

    printf("start the connection process \n");

    if (status = getaddrinfo(NULL, "8080", &host, &connection) != 0) {
        printf("something went wrong");
    }

    printf("create addrinfo %d \n", connection->ai_addrlen);

    int sock = socket(connection->ai_family, connection->ai_socktype, connection->ai_protocol);
    printf("created a socket %d \n", sock);
    if (status = bind(sock, connection->ai_addr, connection->ai_addrlen) != 0) {
        printf("something went wrong\n");
    }
    printf("socket binded successfully\n");

    listen(sock, 5);
    printf("listen to sock %d\n", sock);

    struct sockaddr_in incomingSock;
    memset(&incomingSock, 0, sizeof(incomingSock));
    int addrSize = sizeof(incomingSock);
    int newFd = accept(sock, &incomingSock, &addrSize);
    printf("new connection accepted\n");

    char results[750];
    recv(newFd, &results, 750, 0);

    printf("result %s \n", results);

    send(newFd, "result sent", 11, 0);
    close(newFd);

}

