#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int input = 0;

int main(int argc, char *argv[]) {
   char **argv1;
   char **argv2;
   pid_t pid1, pid2;
   int status, i;
   int fd[2];

   argv1 = argv2 = argv;
   i = 0;
   while(strcmp(argv2[i], ";") != 0) {
      i++;
   }
   argv2[i] =  '\0'; /*put NULL terminator instead of ";"*/

   i++;
   argv2 = &argv2[i];
   argv1 = &argv1[1];
   
   /*now argv1 points to the first command to exec, and argv2 points to the second */

   pipe(fd); /*create a pipe*/

   pid1 = fork(); /*create a child*/ 
   if(pid1 == 0) { /*if child*/
      dup2(fd[1], 1); /*stdout of first child is replaced by write end of pipe*/

      execvp(argv1[0], argv1);
   }

   /*parent*/
   wait(&status); /*wait for the child to send output to pipe*/
   close(fd[1]); /*close write end of the pipe so that we can read
                   but why??? i thought since we waited for child to finish, the program would know that the pipe
                   will not be written to*/
   pid2 = fork();
   
   if(pid2 == 0) { /*child process*/
      dup2(fd[0], 0); /*stdin of second child replaced with read end of pipe*/
      execvp(argv2[0], argv2);
   }

   /*parent*/
   wait(&status);
   wait(&status);

   close(fd[0]);
   close(fd[1]);

   return 0;
}

