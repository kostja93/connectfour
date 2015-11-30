//
// Created by Konstantin Gontscharow on 29.11.15.
//

#ifndef CONNECTFOURCLIENT_CONNECTFOURTYPES_H
#define CONNECTFOURCLIENT_CONNECTFOURTYPES_H

#include <stdlib.h>

struct default_package {
    __uint16_t type;
    __uint16_t length;
};

struct peer_info {
    __uint16_t type;
    __uint16_t length;
    __uint32_t ip;
    __uint16_t port;
    __uint16_t start;
};

struct set_column {
    __uint16_t type;
    __uint16_t length;
    __uint32_t seq_nr;
    __uint32_t column;
};

struct set_column_ack {
    __uint16_t type;
    __uint16_t length;
    __uint32_t seq_nr;
};

#endif //CONNECTFOURCLIENT_CONNECTFOURTYPES_H
