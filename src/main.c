#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>


void server_calls() {
    int status;
    struct addrinfo hints;
    struct addrinfo *servinfo;

    memset(&hints, 0 , sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; //for specific IP address, put it here

    if ((status = getaddrinfo("www.example.com", "3490", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    int sock = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    printf("socket: %d\n", sock);
    //int bin = bind(sock, servinfo->ai_addr, servinfo->ai_addrlen);
    //printf("bind: %d\n", bin);
    //printf("ai_addr family: %s", servinfo->ai_addr->sa_family);
    printf("ai_addr family: %s", servinfo->ai_addr->sa_data);

    if (status = (connect(sock, servinfo->ai_addr, servinfo->ai_addrlen)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    freeaddrinfo(servinfo);
    printf("completed\n");
}

int main(int argc, char *argv[]) {
    server_calls();
}
