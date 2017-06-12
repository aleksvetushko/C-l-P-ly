#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
   int x, i;

   printf("this is evens\n");
   x = atoi(argv[1]);

   for(i = 1; i <= x; i ++) {
      if(i % 2 == 0)
         fprintf(stdout, "%d\n", i);
   }

   return 0;
}
