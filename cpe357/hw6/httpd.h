#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "simple_net.h"
#include <sys/stat.h>

#define queue_size 5

int get_port(int argc, char *argv[]);
void get_request(int client_fd, char *file);
void head_request(int client_fd, char *file);
void handle_request(int client_fd, char *buffer);
void send_error(int client_fd, char *error);
void cgi_like(int client_fd, char *path, char *request_type);
