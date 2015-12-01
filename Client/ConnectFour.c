//
// Created by Konstantin Gontscharow on 29.11.15.
//

#include <stdio.h>
#include "network_controll.h"
#include "../4clib.h"
#include "../connect_four_types.h"
#include "../Logger.h"

#define DEBUG_CF 1

struct peer_info gamePeerInfo;
int port, peer_socket;
int recv_fd, send_fd;

void extractPeerInfo(int argc, char **argv);
int connectedToPeer();

int main(int argc, char **argv) {
    printf("Connect Four\n");
    extractPeerInfo(argc, argv);

    init_logger();
    init_4clib();
    initialConnectionToPeer(&gamePeerInfo, port);

    print_board();
}

void extractPeerInfo(int argc, char **arguments) {
    if (argc != 5) {
        printf("WRONG USAGE!\n");
        printf("%s IP PORT START YOUR_PORT\n", arguments[0]);
    }

    gamePeerInfo.ip    = (__uint32_t) atoi(arguments[1]);
    gamePeerInfo.port  = (__uint16_t) inet_addr(arguments[2]);
    gamePeerInfo.start = (__uint16_t) atoi(arguments[3]);

    port = atoi(arguments[4]);
}

int connectedToPeer() {
    return 1;
}
