//
// Created by Konstantin Gontscharow on 01.12.15.
//

#ifndef CONNECTFOURCLIENT_LOGGER_H
#define CONNECTFOURCLIENT_LOGGER_H

#include <unistd.h>

#define DEBUGLOGGER (1)

int logger_fd;

void init_logger();
void logger_log(char *msg);
char *create_message(char *msg);
char *getCurrentTimeString();

#endif //CONNECTFOURCLIENT_LOGGER_H
