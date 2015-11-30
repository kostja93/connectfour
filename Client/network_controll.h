//
// Created by Konstantin Gontscharow on 29.11.15.
//

#ifndef CONNECTFOURCLIENT_NETWORK_CONTROLL_H
#define CONNECTFOURCLIENT_NETWORK_CONTROLL_H

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "../connect_four_types.h"

void initialConnectionToPeer(struct peer_info *peerInfo, int port, int , int);
int initSendSocket(struct peer_info *peerInfo);
int initRecvSocket(int);

void setSockAdr(struct sockaddr_in *sockaddr, in_addr_t ip, in_port_t port);

#endif //CONNECTFOURCLIENT_NETWORK_CONTROLL_H
