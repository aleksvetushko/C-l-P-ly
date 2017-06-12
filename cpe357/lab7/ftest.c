#include <stdlib.h>
#include <stdio.h>
#include  <sys/types.h>

int main(int argc, char *argv[]) {
   pid_t pid;
   int x, i, status;

   x = atoi(argv[1]);

   pid = fork();
   if(pid == 0) { /*child*/
      for(i = 1; i <= x; i ++) {
         if(i % 2 == 1)
            printf("%d\n", i);
      }
   }
   if(pid > 0) { /*parent*/
      for(i = 1; i <= x; i ++) {
         if(i % 2 == 0)
            printf("\t%d\n", i);
      }
      wait(&status);
   }

   return 0;
}
