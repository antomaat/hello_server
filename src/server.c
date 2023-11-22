#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    printf("hello server\n");
    struct addrinfo hint;
    struct addrinfo *connection;
    struct addrinfo *serverinfo;
    int status;
    int port;
    int sockfd;

    memset(&hint, 0, sizeof hint);
    hint.ai_family = AF_UNSPEC;
    hint.ai_socktype = SOCK_STREAM;
    hint.ai_flags = AI_PASSIVE; // use the machine IP

    if ((status = getaddrinfo(NULL, port, &hint, &connection)) != 0) {
        return 1;
    }

    for (serverinfo = connection; serverinfo != NULL; serverinfo = serverinfo->ai_next) {
        if (sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol) == -1) {
            perror("server: socket");
            continue;
        }
    }
}

