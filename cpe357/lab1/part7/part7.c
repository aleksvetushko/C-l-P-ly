#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int i;

   for(i = 0; i < argc; i++)
   {
      if(argv[i][0] == '-')
      {
         printf("%s", argv[i]);
         printf("\n");
      }
   }
   return 0;
}
