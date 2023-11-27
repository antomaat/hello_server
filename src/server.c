#include <asm-generic/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("hello server\n");
    struct addrinfo hint;
    struct addrinfo *connection;
    struct addrinfo *serverinfo;
    int status;
    int port;
    int sockfd;

    int yes = 1;

    memset(&hint, 0, sizeof hint);
    hint.ai_family = AF_UNSPEC;
    hint.ai_socktype = SOCK_STREAM;
    hint.ai_flags = AI_PASSIVE; // use the machine IP

    if ((status = getaddrinfo(NULL, "3490", &hint, &connection)) != 0) {
        return 1;
    }

    //bind a server
    for (serverinfo = connection; serverinfo != NULL; serverinfo = serverinfo->ai_next) {
        if ((sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }

        if (bind(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) != 1) {
            close(sockfd);
            perror("server:bind");
            continue;
        }
        break;
    }

    freeaddrinfo(connection);

    if (serverinfo == NULL) {
        fprintf(stderr, "server: failed to bind\n");
    }


}

