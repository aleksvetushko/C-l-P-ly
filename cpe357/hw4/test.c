#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
   char src[40];
   char dest[100];
           
   strcpy(src, "hi");
   strcpy(dest, src);
   src[0] = 'x';

   printf("%s\n", dest);
                        
   return(0);
}
