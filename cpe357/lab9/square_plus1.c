#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int input = 0;

int main(int argc, char *argv[]) {
   pid_t pid1, pid2;
   int status, count, child1int, child2int;
   char buffer[50];
   int fd[2];

   while(gets(buffer)) {
      if(strcmp(buffer, "0") == 0)
         break;

      pipe(fd); /*create a pipe*/
      write(fd[1], buffer, 10); /*write the integer to the write end of the pipe, to be read by child*/
      
      pid1 = fork(); /*create a child*/

      if(pid1 == 0) { /*if child*/
         read(fd[0], buffer, 10); /*read from read end of pipe into buffer*/

         child1int = atoi(buffer);
         child1int = child1int * child1int;
         sprintf(buffer, "%d", child1int);

         write(fd[1], buffer, 10); /*write integer to write end of the pipe, to be read by second child*/

         pid2 = fork(); /*make second chid*/

         if(pid2 == 0) { /*if second child*/
            read(fd[0], buffer, 10); /*read from read end of pipe into buffer*/
            child2int = atoi(buffer);
            child2int ++;
            sprintf(buffer, "%d", child2int);

            write(fd[1], buffer, 10); /*write integer to write end of the pipe, to be read by parent*/
            exit(0);
         }
         exit(0);
      }

      else /*parent*/
         wait(&status);

      read(fd[0], buffer, 10); /*read integer into buffer from read end of pipe*/

      close(fd[0]);
      close(fd[1]);

      printf("%s\n", buffer);
   }

   return 0;
}
