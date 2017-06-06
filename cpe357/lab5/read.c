
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define size 2048

FILE * file;
char * array[size];

int main() {
   file = fopen("/usr/lib/locale/locale-archive", "r");
   while(fread(array, size, 1, file) != 0) {
      
   }
   fclose(file);
   return 0;
}
