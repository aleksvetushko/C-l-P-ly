#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char * str_lower(char string[], char buffer[])
{
   int i;
   for(i = 0; i < strlen(string); i++)
   {
      buffer[i] = tolower(string[i]);
   }
   /*buffer[i+1] = "\0";*/

   return buffer;
}

char * str_lower_mutate(char string[])
{
   int i;
   for(i = 0; string[i]; i++)
   {
      string[i] = tolower(string[i]);
   }

   return string;
}
