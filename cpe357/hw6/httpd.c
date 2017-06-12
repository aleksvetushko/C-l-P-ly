#include "httpd.h"

int child_counter = 0;

int get_port(int argc, char *argv[]) {
   int port;
   if(argc != 2) {
      fprintf(stderr, "You must specify a single port\n");
      exit(1);
   }
   port = atoi(argv[1]);
   if(port > 65535 || port < 1024) {
      fprintf(stderr, "You must specify a port between 1024 and 65535\n");
      exit(1);
   }
   return port;
}

void cgi_like(int client_fd, char *path, char *request_type) {
   char *arglist[1024];
   char *arg;
   char *real_path;
   char file[1024];
   int i, pid, real_pid, file_pid, status;
   /*pid is 0 when parent forks, real_pid is getpid() of child, file_pid is pid of temp file*/

   printf("%s\n", path);
   i = 0;
   memset(arglist, 0, sizeof(arglist));
   real_path = strtok(path, " ?&"); /*determine path*/
   arglist[i] = real_path;
   i++;
   printf("%s\n", path);
   while((arg = strtok(NULL, " &"))) {
      arglist[i] = arg;
      i++;
   }
   arglist[i] = NULL; /*end arglist with a null pointer*/

   if((pid = fork()) == 0) {
      real_pid = getpid();
      sprintf(file, "temp_%d", real_pid);
      file_pid = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
      dup2(file_pid, 1);

      execv(real_path, arglist);
      send_error(client_fd, "HTTP/1.0 404 Not Found"); /*if exec failed, send error*/
   }
   else if(pid < 0){
      send_error(client_fd, "HTTP/1.0 500 Internal Error");
      return;
   }

   wait(&status); /*wait for child to finish*/
   sprintf(file, "temp_%d", pid);
   
   if(strcmp(request_type, "HEAD") == 0)
      head_request(client_fd, file);
   else if(strcmp(request_type, "GET") == 0)
      get_request(client_fd, file);
   remove(file);
   exit(0);
}

void get_request(int client_fd, char *file) {
   struct stat sb;
   int file_length, fd;
   char header[1024];
   char path[1024];
   char write_buffer[1024];

   memset(path, 0, 1024);
   memset(header, 0, 1024);
   memset(write_buffer, 0, 1024);
   strcpy(path, "./");
   strcat(path, file);

   if(strncmp("cgi-like/", file, 9 ) == 0) {
      cgi_like(client_fd, path, "GET");
   }
   else if(access(path, F_OK) != -1) {
      stat(path, &sb);
      if((fd = open(path, O_RDONLY) != -1) && (sb.st_mode & S_IROTH)) {
         file_length = (int) sb.st_size;
         if(S_ISDIR(sb.st_mode)) {
            send_error(client_fd, "HTTP/1.0 400 Bad Request");
            return;
         }
         sprintf(header, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", file_length);
         write(client_fd, header, strlen(header));
         close(fd);
         fd = open(path, O_RDONLY);
         while(read(fd, write_buffer, 1024) != -1) { /*while there is more to be read*/
            write(client_fd, write_buffer, 1024);
            memset(write_buffer, 0, 1024);
         }
         shutdown(client_fd, SHUT_RD);
         close(fd);
      }
         send_error(client_fd, "HTTP/1.0 403 Permission Denied");
   }
   else
      send_error(client_fd, "HTTP/1.0 404 Not Found");
}

void head_request(int client_fd, char *file) {
   struct stat sb;
   int file_length, fd;
   char header[1024];
   char path[1024];

   memset(path, 0, 1024);
   memset(header, 0, 1024);
   strcpy(path, "./");
   strcat(path, file);

   if(strncmp("cgi-like/", file, 9 ) == 0) {
      cgi_like(client_fd, path, "HEAD");
   }
   else if(access(path, F_OK) != -1) {
      stat(path, &sb);
      if((fd = open(path, O_RDONLY) != -1) && (sb.st_mode & S_IROTH)) {
         file_length = (int) sb.st_size;
         if(S_ISDIR(sb.st_mode)) {
            send_error(client_fd, "HTTP/1.0 400 Bad Request");
            return;
         }
         sprintf(header, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", file_length);
         write(client_fd, header, strlen(header));
         close(fd);
      }
      else
         send_error(client_fd, "HTTP/1.0 403 Permission Denied");
   }
   else
      send_error(client_fd, "HTTP/1.0 404 Not Found");
}

void send_error(int client_fd, char *error) {
   char header[1024];

   memset(header, 0, 1024);

   sprintf(header, "%s\r\nContent-Type: text/html\r\n%s\r\n\r\n", error, error);
   write(client_fd, header, strlen(header));
}

void handle_request(int client_fd, char *buffer) {
   char *request_type;
   char *request_file;
   
   request_type = strtok(buffer, " \n");
   request_file = strtok(NULL, " \n");
   request_file++; /*ignore '/' */
   
   if((strstr(request_file, "/..") != NULL) || (strcmp(request_file, "..") == 0)) {
      send_error(client_fd, "HTTP/1.0 403 Permission Denied");
      shutdown(client_fd, 2);
      return;
   }
   if(strcmp(request_file, "") == 0) {
      return;
   }

   if(strcmp(request_type, "GET") == 0) {
      get_request(client_fd, request_file);
   }
   else if(strcmp(request_type, "HEAD") == 0) {
      head_request(client_fd, request_file);
   }
   else
      send_error(client_fd, "HTTP/1.0 501 Not Implemented");
}

void handler(int sig){
   while (waitpid (-1, NULL, WNOHANG) != -1)
      child_counter--;
}

int main(int argc, char *argv[]) {
   char buffer[1024];
   int port, service, pid, status, client_fd;

   port = get_port(argc, argv);

   if((service = create_service(port, queue_size)) == -1) {
      fprintf(stderr, "Could not create service\n");
      exit(1);
   }

   signal(SIGCHLD, handler); /*if a child exits, do what handler says*/

   while(1) {
      if((client_fd = accept_connection(service)) == -1) {
         fprintf(stderr, "Could not accept connection\n");
         exit(1);
      }

      pid = fork();

      if(pid == 0) { /*child*/
         child_counter++;
         /*sleep(1);*/ /*TODO*/
         memset(buffer, 0, 1024); /*set buffer to 0 so when we fill it with < 1024 chars the rest of the buffer is clean*/
         read(client_fd, buffer, 1024);
         handle_request(client_fd, buffer);
         shutdown(client_fd, 2);
      }

      if(pid < 0)
         send_error(client_fd, "HTTP/1.0 500 Internal Error");

      /*parent*/
      wait(&status);
   }

   return 0;
}

