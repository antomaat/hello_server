#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>


void runClient() {
    struct sockaddr_in sockAddr;
    inet_pton(AF_INET, "0.0.0.0:8080", &(sockAddr))
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    int status = connect(sock, &sockAddr, sizeof(sockAddr));
    send(sock, "hello world", 11, 0);
}

int main(int argc, char *argv[]) {
    runClient();
}
