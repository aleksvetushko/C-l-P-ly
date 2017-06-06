/*Aleks Vetushko
 * This program is a simplified form of the stat utility*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int i; /*general purpose iterator*/
   char type; /*type of file*/

   if(argc < 2) {
      fprintf(stderr, "please specify at least one filename\n");
      exit(-1);
   }

   struct stat sStat;
   for(i = 1; i < argc; i++) {
      if(stat(argv[i], &sStat) < 0) {
         fprintf(stderr, "error\ncould not obtain info about %s\n", argv[i]);
         continue;
      }
      printf("File: '%s'\n", argv[i]);
      printf("Type: ");
      switch (sStat.st_mode & S_IFMT) {
         case S_IFBLK:
            type = 'b';
            printf("Block Device\n");
            break;
         case S_IFCHR:
            type = 'c';
            printf("Character Device\n");
            break;
         case S_IFDIR:
            type = 'd';
            printf("Directory\n");
            break;
         case S_IFREG:
            type = '-';
            printf("Regular File\n");
            break;
         case S_IFIFO:
            type = 'p';
            printf("FIFO\n");
            break;
         case S_IFLNK:
            type = 'l';
            printf("Symbolic Link\n");
            break;
      }
      printf("Size: %d\n", sStat.st_size);
      printf("Inode: %d\n", sStat.st_ino);
      printf("Links: %d\n", sStat.st_nlink);

      /*access*/
      printf("%c", type);

      printf( (sStat.st_mode & S_IRUSR) ? "r" : "-" ); /*user*/
      printf( (sStat.st_mode & S_IWUSR) ? "w" : "-" );
      if(sStat.st_mode & S_ISUID)
         printf( (sStat.st_mode & S_IXUSR) ? "s" : "S" );
      else
         printf( (sStat.st_mode & S_IXUSR) ? "x" : "-" );

      printf( (sStat.st_mode & S_IRGRP) ? "r" : "-" ); /*group*/
      printf( (sStat.st_mode & S_IWGRP) ? "w" : "-" );
      if(sStat.st_mode & S_ISGID) 
         printf( (sStat.st_mode & S_IXGRP) ? "s" : "S" );
      else
         printf( (sStat.st_mode & S_IXUSR) ? "x" : "-" );

      printf( (sStat.st_mode & S_IROTH) ? "r" : "-" ); /*other*/
      printf( (sStat.st_mode & S_IWOTH) ? "w" : "-" );
      printf( (sStat.st_mode & S_IXOTH) ? "x" : "-" );
      printf("\n");

}

   return 0;
}
