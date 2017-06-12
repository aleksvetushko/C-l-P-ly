
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

#define error400 write_header("400 Bad Request", 0, accept_fd)
#define error403 write_header("403 Permission Denied", 0, accept_fd)
#define error404 write_header("404 Not Found", 0, accept_fd)
#define error500 write_header("500 Internal Error", 0, accept_fd)
#define error501 write_header("501 Not Implemented", 0, accept_fd)

#define r_usr_chk (stats->st_mode & S_IRUSR)
#define r_grp_chk (stats->st_mode & S_IRGRP)
#define r_oth_chk (stats->st_mode & S_IROTH)
#define r_chk (r_usr_chk || r_grp_chk || r_oth_chk)

void close_socket(int accept_fd) {
    shutdown(accept_fd, 2);
    exit(0);
}

char **chars_resize(char **output, int max, int accept_fd) {
    if ((output = realloc(output, sizeof(*output) * max)) == NULL) {
        perror("Char** realloc error");
        error500;
        close_socket(accept_fd);
    }
    return output;
}

char *char_resize(char *output, int max, int accept_fd) {
    if ((output = realloc(output, sizeof(*output) * max)) == NULL) {
        perror("Char* realloc error");
        error500;
        close_socket(accept_fd);
    }
    return output;
}

int *int_resize(int *output, int max, int accept_fd) {
    if ((output = realloc(output, sizeof(*output) * max)) == NULL) {
        perror("Char* realloc error");
        error500;
        close_socket(accept_fd);
    }
    return output;
}

/**********************************************************
 * newStat
 *
 * creates stat structure.
 * returns -1 for st_size if stat can not be created.
 **********************************************************/

struct stat newStat(char *target) {
    struct stat new;

    if (stat(target, &new) < 0) {
        new.st_size = -1;
        return new;
    }

    return new;
}

void write_header(char *status, off_t length, int accept_fd) {
    char *temp = NULL;
    temp = char_resize(temp, 12, accept_fd);
    sprintf(temp, "%ld", length);
    write(accept_fd, "HTTP/1.0 ", sizeof("HTTP/1.0 "));
    write(accept_fd, status, strlen(status));
    write(accept_fd, "\r\nContent-Type: text/html\r\n", sizeof("\r\nContent-Type: text/html\r\n"));
    write(accept_fd, "Content-Length: ", sizeof("Content-Length: "));
    write(accept_fd, temp, strlen(temp));
    write(accept_fd, "\r\n\r\n", sizeof("\r\n\r\n"));
    free(temp);
}

void w_error_check(int accept_fd, char *cmd2) {
    struct stat *stats;
    char *length = NULL;
    length = char_resize(length, PATH_MAX, accept_fd);

    if ((stats = malloc(sizeof(struct stat))) == NULL) {
        error500;
        close_socket(accept_fd);
    }

    if ((*stats = newStat(cmd2)).st_size == -1 || !S_ISREG(stats->st_mode)) {
        printf("STAT FAIL\n");
        error404;
        close_socket(accept_fd);
    }
    else {
        write_header("200 OK", stats->st_size, accept_fd);
    }
    free(length);
    free(stats);
}

void w_to_client(int accept_fd, char* cmd2) {
    struct stat *stats;
    int buff_size = 1024;
    char *buffer;
    int fd;
    int fail;

    buffer = char_resize(NULL, buff_size, accept_fd);

    if ((stats = malloc(sizeof(struct stat))) == NULL) {
        error500;
        close_socket(accept_fd);
    }

    *stats = newStat(cmd2);

    if (!r_chk) {
        error403;
        close_socket(accept_fd);
    }

    if ((fd = open(cmd2, O_RDONLY)) == -1) {
        error500;
        close_socket(accept_fd);
    }

    write(accept_fd, "\r\n", strlen("\r\n"));
    while ((fail = read(fd, buffer, buff_size)) == buff_size) {
        write(accept_fd, buffer, buff_size);
    }

    write(accept_fd, buffer, fail);
    close(fd);
    free(stats);
    free(buffer);
}


void get_files(char *cmd2, int accept_fd) {
    char *tempFile;
    int tempFd;
    pid_t pid2;
    char *temp;

    temp = char_resize(NULL, strlen(cmd2)+1+strlen("./"), accept_fd);

    if (strstr(cmd2, "/cgi-like") == cmd2 || strstr(cmd2, "cgi-like") == cmd2) {
        tempFile = char_resize(NULL, 20, accept_fd);
        sprintf(tempFile, ".temp%d", getpid());
        tempFd = open(tempFile, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

        dup2(tempFd, STDOUT_FILENO);

        if ((pid2 = fork()) == -1) {
            error500;
            close(tempFd);
            close_socket(accept_fd);
        }
        if (pid2 == 0) {
            int count = 0;
            int max   = 1;

            char **cmds = NULL;
            char *path = char_resize(NULL, strlen(cmd2)+strlen("./")+1, accept_fd);
            char *tempcmd;
            cmds = chars_resize(cmds, max+2, accept_fd);
            strcpy(path, "./");
            strcat(path, strtok(cmd2, "?"));
            printf("%s\n", path);
            cmds[0] = strrchr(path, '/');
            count++;
            while ((tempcmd = strtok(NULL, "&")) != NULL) {
                if (count == max) {
                    max = max*2;
                    cmds = chars_resize(cmds, max+1, accept_fd);
                }
                cmds[count] = tempcmd;
                count++;
            }
            cmds[count] = NULL;

            if (execvp(path, cmds) == -1) {
                printf("here\n");
                error400;
                close_socket(accept_fd);
                exit(1);
            }
            cmds[1] = tempFile;
            cmds[2] = NULL;
            if (execvp("rm", cmds) == -1) {
                printf("here\n");
                error400;
                close_socket(accept_fd);
                exit(1);
            }
            free(path);
            free(cmds);
            exit(1);
        }
        else {
            waitpid(pid2, NULL, 0);

            close(tempFd);

            w_error_check(accept_fd, tempFile);

            w_to_client(accept_fd, tempFile);

            if ((pid2 = fork()) == -1) {
                error500;
                close(tempFd);
                close_socket(accept_fd);
            }
            if (pid2 == 0) {
                char **cmds = chars_resize(NULL, 3, accept_fd);
                cmds[0] = "rm";
                cmds[1] = tempFile;
                cmds[2] = NULL;
                execvp("rm", cmds);
                free(cmds);
            }
            else {
                waitpid(pid2, NULL, 0);
            }
        }
        free(temp);
        if (tempFile != NULL) {
            free(tempFile);
        }
        return;
    }

    strcpy(temp, "./");
    strcat(temp, cmd2);
    strcpy(cmd2, temp);
    free(temp);

    w_error_check(accept_fd, cmd2);

    w_to_client(accept_fd, cmd2);
}

void head_files(char *cmd2, int accept_fd) {
    char *tempFile;
    int tempFd;
    pid_t pid2;
    char *temp;

    temp = char_resize(NULL, strlen(cmd2)+1+strlen("./"), accept_fd);

    if (strstr(cmd2, "/cgi-like") == cmd2 || strstr(cmd2, "cgi-like") == cmd2) {
          tempFile = char_resize(NULL, 20, accept_fd);
          sprintf(tempFile, ".temp%d", getpid());
          tempFd = open(tempFile, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

          dup2(tempFd, STDOUT_FILENO);

          if ((pid2 = fork()) == -1) {
              error500;
              close(tempFd);
              close_socket(accept_fd);
          }
          if (pid2 == 0) {
              int count = 0;
              int max   = 1;

              char **cmds = NULL;
              char *path = char_resize(NULL, strlen(cmd2)+strlen("./")+1, accept_fd);
              char *tempcmd;
              cmds = chars_resize(cmds, max+2, accept_fd);
              strcpy(path, "./");
              strcat(path, strtok(cmd2, "?"));
              printf("%s\n", path);
              cmds[0] = strrchr(path, '/');
              count++;
              while ((tempcmd = strtok(NULL, "&")) != NULL) {
                  if (count == max) {
                      max = max*2;
                      cmds = chars_resize(cmds, max+1, accept_fd);
                  }
                  cmds[count] = tempcmd;
                  count++;
              }
              cmds[count] = NULL;

              if (execvp(path, cmds) == -1) {
                  printf("here\n");
                  error400;
                  close_socket(accept_fd);
                  exit(1);
              }
              cmds[1] = tempFile;
              cmds[2] = NULL;
              if (execvp("rm", cmds) == -1) {
                  printf("here\n");
                  error400;
                  close_socket(accept_fd);
                  exit(1);
              }
              free(path);
              free(cmds);
              exit(1);
          }
          else {
              waitpid(pid2, NULL, 0);

              close(tempFd);

              w_error_check(accept_fd, tempFile);

              if ((pid2 = fork()) == -1) {
                  error500;
                  close(tempFd);
                  close_socket(accept_fd);
              }
              if (pid2 == 0) {
                  char **cmds = chars_resize(NULL, 3, accept_fd);
                  cmds[0] = "rm";
                  cmds[1] = tempFile;
                  cmds[2] = NULL;
                  execvp("rm", cmds);
                  free(cmds);
              }
              else {
                  waitpid(pid2, NULL, 0);
              }
          }
          if (tempFile != NULL) {
              free(tempFile);
          }
          free(temp);
          return;
      }

    strcpy(temp, "./");
    strcat(temp, cmd2);
    strcpy(cmd2, temp);

    free(temp);

    w_error_check(accept_fd, cmd2);
}

char **cmd_parser(int accept_fd) {
    char **output = NULL;

    char *cmd1 = NULL;
    char *cmd2 = NULL;
    char *cmd3 = NULL;

    int read_bytes;
    int buff_size = PATH_MAX;

    char *cmd_buff = NULL;

    output = chars_resize(output, 3, accept_fd);
    cmd_buff = char_resize(cmd_buff, buff_size, accept_fd);
    cmd1 = char_resize(cmd1, buff_size, accept_fd);
    cmd2 = char_resize(cmd2, buff_size, accept_fd);
    cmd3 = char_resize(cmd3, buff_size, accept_fd);

    if ((read_bytes = recv(accept_fd, cmd_buff, buff_size, 0)) == -1) {
        error500;
        close_socket(accept_fd);
    }

    if (cmd_buff == NULL) {
        error400;
        close_socket(accept_fd);
    }

    strcpy(cmd1, strtok(cmd_buff, " "));

    if (cmd1 == NULL) {
        error400;
        close_socket(accept_fd);
    }
    strcpy(cmd2, strtok(NULL, " "));
    if (cmd2 == NULL) {
        error400;
        close_socket(accept_fd);
    }
    if (strstr(cmd2, "..") != NULL) {
        error403;
        close_socket(accept_fd);
    }

    strcpy(cmd3, strtok(NULL, " "));
    if (cmd3 == NULL || strstr(cmd3, "HTTP") == NULL) {
        error400;
        close_socket(accept_fd);
    }

    cmd1 = char_resize(cmd1, strlen(cmd1)+1, accept_fd);
    cmd2 = char_resize(cmd2, strlen(cmd2)+1+strlen("./"), accept_fd);
    cmd3 = char_resize(cmd3, strlen(cmd3)+1, accept_fd);

    free(cmd_buff);

    output[0] = cmd1;
    output[1] = cmd2;
    output[2] = cmd3;

    return output;
}
