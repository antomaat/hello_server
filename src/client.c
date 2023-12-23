#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>


void runClient() {

    struct addrinfo host;
    struct addrinfo *connection;
    memset(&host, 0 , sizeof host);
    host.ai_family = AF_INET;
    host.ai_socktype = SOCK_STREAM;
    host.ai_protocol = 0;
    host.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(NULL, "8080", &host, &connection);
    printf("ai addr %d \n", connection->ai_addrlen);
    printf("ai addr %d \n", connection->ai_addr->sa_family);

    struct addrinfo hints;
    struct sockaddr sockAddr;
    memset(&hints, 0, sizeof(struct addrinfo));
    memset(&sockAddr, 0, sizeof(struct sockaddr));
    int socket_conn = socket(PF_INET, SOCK_STREAM, 0);
    connect(socket_conn, connection->ai_addr, connection->ai_addrlen);
}

int main(int argc, char *argv[]) {
    runClient();
}
