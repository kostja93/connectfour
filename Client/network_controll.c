//
// Created by Konstantin Gontscharow on 29.11.15.
//

#include "network_controll.h"
#include "../Logger.h"

void initialConnectionToPeer(struct peer_info *peerInfo, int port) {
    recv_fd = initRecvSocket(port);
    send_fd = 1;//initSendSocket(peerInfo);
    if (recv_fd == -1 || send_fd == -1) {
        logger_log("An Error happend while creating connection to peer\n");
        exit(-1);
    }
}

int initSendSocket(struct peer_info *peerInfo) {
    int send_fd, connected = -1;
    struct sockaddr_in sock_adr;

    send_fd = socket(AF_INET, SOCK_STREAM, 0);

    setSockAdr(&sock_adr, peerInfo->ip, peerInfo->port);

    for (int i = 0; i < 3 && connected != 0; i++) {
        connected = connect(send_fd, (struct sockaddr *) &sock_adr, sizeof(sock_adr));
        if (connected < 0) {
            logger_log("Retrying connecting");
            sleep(5);
        }
    }

    if (connected == 0)
        logger_log("Connected to client");
    else {
        logger_log("Couldn't connect to client");
        exit(-1);
    }

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
    memset(sockaddr, 0, sizeof(struct sockaddr_in));

    sockaddr->sin_family        = AF_INET;
    sockaddr->sin_addr.s_addr   = htonl(ip);
    sockaddr->sin_port          = htons(port);

    sockaddr->sin_len = sizeof(struct sockaddr_in);
}
