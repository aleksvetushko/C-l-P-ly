#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
   int x, i;

   x = atoi(argv[1]);

   for(i = 1; i <= x; i ++) {
      if(i % 2 == 1)
         printf("%d\n", i);
   }

   return 0;
}
