#include <stdio.h>
#include <string.h>

char * strcat1(char * s1, char * s2) {
   int i;
   if(s2 == NULL || strlen(s2) == 0) {
      return s1;
   }

   for(i=0; i < strlen(s2); i++) {
      s1[strlen(s1)] = s2[i];
   }

   s1[strlen(s1)] = '\0';
   return s1;
}

int main() {
   char * s1 = "hi";
   char * s2 = " there";
   printf("%s", strcat1(s1, s2));
   return 0;
}
