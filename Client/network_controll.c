//
// Created by Konstantin Gontscharow on 29.11.15.
//

#include "network_controll.h"
#include "../Logger.h"

void initialConnectionToPeer(struct peer_info *peerInfo, int port, int read, int write) {
    logger_log("Opening Ports");

    read  = initRecvSocket(port);
    write = initSendSocket(peerInfo);

    if (read == -1 || write == -1) {
        printf("An Error happend while creating connection to peer\n");
        exit(-1);
    }
}

int initSendSocket(struct peer_info *peerInfo) {
    int send_fd;
    struct sockaddr_in sock_adr;

    send_fd = socket(AF_INET, SOCK_STREAM, 0);

    setSockAdr(&sock_adr, peerInfo->ip, peerInfo->port);
    connect(send_fd, (struct sockaddr *) &sock_adr, sizeof(sock_adr));

    return send_fd;
}

int initRecvSocket(int port) {
    int fd;
    struct sockaddr_in sock_adr;

    setSockAdr(&sock_adr, INADDR_ANY, port);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(fd, (const struct sockaddr *) &sock_adr, sizeof(sock_adr));

    listen(fd, 1);

    return fd;
}

void setSockAdr(struct sockaddr_in *sockaddr, in_addr_t ip, in_port_t port) {
    memset(sockaddr, 0, sizeof(struct sockaddr_in6));

    sockaddr->sin_family        = AF_INET6;
    sockaddr->sin_addr.s_addr   = htonl(ip);
    sockaddr->sin_port          = htons(port);

    sockaddr->sin_len = sizeof(struct sockaddr_in);
}
