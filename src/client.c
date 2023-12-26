#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>


void runClient() {
    struct sockaddr_in sockAddr;
    sockAddr.sin_port = htons(8080);
    sockAddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &(sockAddr.sin_addr));
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int status = connect(sock, &sockAddr, sizeof(sockAddr));
    if (status == -1) {
        printf("connection not successful\n");
        exit(0);
    }
    send(sock, "hello world\0", 11, 0);

    char result[700];
    int numbytes = recv(sock, &result, 700, 0);
    result[numbytes] = '\0';
    printf("response %s \n", result);
}

int main(int argc, char *argv[]) {
    runClient();
}
