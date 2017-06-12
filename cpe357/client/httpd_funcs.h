/*
 * httpd_funcs.h
 *
 *  Created on: Mar 17, 2017
 *      Author: sfong06
 */

#ifndef HTTPD_FUNCS_H_
#define HTTPD_FUNCS_H_

void w_to_client(int accept_fd, char* cmd2);

void w_error_check(int accept_fd, char *cmd2);

void write_header(char *status, off_t length, int accept_fd);

struct stat newStat(char *target);

int *int_resize(int *output, int max, int accept_fd);

char *char_resize(char *output, int max, int accept_fd);

char **chars_resize(char **output, int max);

void close_socket(int accept_fd);

void get_files(char *cmd2);

void head_files(char *cmd2);

char **cmd_parser();

#endif /* HTTPD_FUNCS_H_ */
