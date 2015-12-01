//
// Created by Konstantin Gontscharow on 01.12.15.
//

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Logger.h"

void init_logger() {
    if (DEBUGLOGGER) {
        logger_fd = STDIN_FILENO;
        return;
    }

    logger_fd = open("Client_ConnectFour.log", O_RDWR, S_IREAD & S_IWRITE);
}

void logger_log(char *msg) {
    size_t length = strlen(msg);

    char *message = create_message(msg);

    write(logger_fd, message, strlen(message));

    free(message);
}

char *create_message(char *msg) {
    char *fullMessage = malloc(strlen(msg) + 20 * sizeof(char) + 1);
    char *time_str = getCurrentTimeString();

    strcat(fullMessage, time_str);
    strcat(fullMessage, "\t");
    strcat(fullMessage, msg);
    strcat(fullMessage, "\n");
    strcat(fullMessage, "\0");

    free(time_str);

    return fullMessage;
}

char* getCurrentTimeString() {
    time_t current_time;
    struct tm * time_info;
    char *timeString = malloc(sizeof(char) * 18);

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(timeString, sizeof(char) * 18, "%D %H:%M:%S", time_info);

    return timeString;
}