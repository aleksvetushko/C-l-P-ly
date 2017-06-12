#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#include "simple_net.h"
#include "httpd.h"
#include "httpd_funcs.c"

#define error400 write_header("400 Bad Request", 0, accept_fd)
#define error403 write_header("403 Permission Denied", 0, accept_fd)
#define error404 write_header("404 Not Found", 0, accept_fd)
#define error500 write_header("500 Internal Error", 0, accept_fd)
#define error501 write_header("501 Not Implemented", 0, accept_fd)

#define r_usr_chk (stats->st_mode & S_IRUSR)
#define r_grp_chk (stats->st_mode & S_IRGRP)
#define r_oth_chk (stats->st_mode & S_IROTH)
#define r_chk (r_usr_chk || r_grp_chk || r_oth_chk)

int accept_fd;

void handle_sigpipe(int signum) {
    close_socket(accept_fd);
    errno = 0;
    exit(1);
}

void handle_sigsev(int signum) {
    close_socket(accept_fd);
    exit(1);
}

void handle_eaccess(int signum) {
    close_socket(accept_fd);
    exit(1);
}

int main() {
    int server_fd;

    pid_t pid;

    if ((server_fd = create_service(5555, 20)) == -1) {
        printf("Failed creating service!");
        exit(1);
    }

    while (1) {
        if ((accept_fd = accept_connection(server_fd)) == -1) {
            printf("Too many file descriptors!");
            continue;
        }

        if ((pid = fork()) == 0) {
            struct sigaction action;
            struct sigaction action2;
            struct sigaction action3;
            char **cmds;

            sigemptyset(&action.sa_mask);
            action.sa_flags = 0;
            action.sa_handler = handle_sigpipe;

            sigaction(SIGPIPE, &action, NULL);
            sigaction(EPIPE, &action, NULL);

            sigemptyset(&action2.sa_mask);
            action2.sa_flags = 0;
            action2.sa_handler = handle_sigsev;

            sigaction(SIGSEGV, &action2, NULL);

            sigemptyset(&action3.sa_mask);
            action3.sa_flags = 0;
            action3.sa_handler = handle_eaccess;

            sigaction(EACCES, &action2, NULL);

            cmds = cmd_parser(accept_fd);
            free(cmds[2]);
            if (strcmp(cmds[0], "GET") == 0) {
                get_files(cmds[1], accept_fd);
                free(cmds[0]);
                free(cmds[1]);
                free(cmds);
                close_socket(accept_fd);
            }
            else if (strcmp(cmds[0], "HEAD") == 0) {
                head_files(cmds[1], accept_fd);
                free(cmds[0]);
                free(cmds[1]);
                free(cmds);
                close_socket(accept_fd);
            }
            else {
                error501;
                close_socket(accept_fd);
            }

            close_socket(accept_fd);
        }
        else {
            if (pid == -1) {
                error500;
                shutdown(accept_fd, 2);
            }
        }
    }

    return 0;
}
