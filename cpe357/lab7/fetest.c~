#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
   pid_t pid1, pid2;
   int status1, status2;

   pid1 = fork();

   if(pid1 == 0) /*child*/
      execl("odds", "odds", argv[1], (char *)NULL);

   pid2 = fork();
   if(pid2 == 0) /*other child*/
      execl("/home/avetushk/cpe357/lab7/evens", "evens", argv[1], (char *)NULL);
   else {
      wait(&status2);
      wait(&status1);
   }

   return 0;
}
