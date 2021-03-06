#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * readline(FILE * file) {
   char c;
   int i;

   char *string = malloc(sizeof(char) * 10);
   i = 0;
   while((c = fgetc(file)) != EOF && c != '\n') {
      string[i] = c;
      i++;
      if((i+1) % 10 == 0) {
         string = realloc(string, i*sizeof(char) + sizeof(char)*10);
      }
   }

   if(i == 0) {
      return NULL;
   }
   
   return string;
}

int main(int argc, char *argv[]) {
   while(argc == 2) {
      const char *filename = argv[1];
      char * string;

      FILE * file = fopen(filename, "r");
      while((string = readline(file)))  {
         printf("%s\n", string);
         free(string);
      }
      free(string);
      fclose(file);
      return 0;   
   }

   return 1;
}
