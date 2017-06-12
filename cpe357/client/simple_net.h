#ifndef SIMPLE_NET_H
#define SIMPLE_NET_H

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


#include <sys/socket.h>

int create_service(unsigned short port, int queue_size);
int accept_connection(int fd);

void determine_request(int port, int client_fd, char* line);
int printHeader(int port, int client_fd, char *fileName);
int fileExists(char * fileName);
void createPath(char *buf, char *fileName);
void printFile(int client_fd, int fd);
void printError(int client_fd, int errCode);
void sigPipeHandler(int sig_num);
void sigChildHandler(int sig_num);
void cgi_like(int port, int client_fd, char* cmd);



#endif
