#include <stdio.h>
#include <dirent.h>
#include "sfind.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/*extern assumes functions are defined and gets rid of compiler warnings*/
extern int lstat(const char *path, struct stat *buf);
extern int snprintf(char *str, size_t size, const char *format, ...);

char *substring;

void sexec(char *command) {

}

/* if filename can be opened, print it (if print command).
 * if it's a directory, execute command*/
void openFilename(char *filename, int commandType) {
   DIR *directory;
   int len;
   char pathname[1024];

   if (!(directory = opendir(filename))) { /*if you cannot open filename as a directory*/
      if(errno == EACCES) { /*if filename can't be accessed*/
         printf("%s\n", filename);
         fprintf(stderr, "find: ‘%s’: Permission denied\n", filename);
      }
      else if (errno == ENOTDIR) /*if filename is not a directory*/
         printf("%s\n", filename);
      else
         fprintf(stderr, "find: ‘%s’: No such file or directory\n", filename);
      closedir(directory);
      exit(0);
   }

   if(filename[strlen(filename) - 1] == '/') { /*if file is aaa/ make it aaa*/
      strcpy(pathname, filename);
      filename[strlen(filename) - 1] = 0;
   }
   else
      strcpy(pathname, filename);

   if(commandType == 1) /*if print command then print filename*/
      printf("%s\n", pathname);
   else if(commandType == 2 && strcmp(filename, substring) == 0) /*if print command then print filename*/
      printf("%s\n", pathname);
   
   len = snprintf(pathname, sizeof(pathname)-1, "%s/", filename); /*make pathname*/
   pathname[len] = 0;

   closedir(directory);
   if (commandType == 1) /*print if print command*/
      sprint(filename, pathname, 0);
   else if (commandType == 2)
      sprint(filename, pathname, 1);
   else if (commandType == 3)
      /*sexec()*/ return;
   else if (commandType == 4)
      /*sexec()*/ return;
}

/*open the directory, go through it, print full pathname of everything.
 * If the element is a directory, call sprint on it.
 * don't print or follow '.', '..', or symlinks*/
void sprint(char *filename, char *pathname, int mode /*0 for print, 1 for print -name*/) { 
   DIR *directory;
   struct dirent *entry;
   struct stat s;
   int len;
   char path[1024];
   char entryPath[1024];
   
   strcpy(path, pathname);
   len = strlen(path);
   directory = opendir(path); /*open the directory*/

   while((entry = readdir(directory))) { /*while there are more entries*/
      if((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) /*if entry is "." or ".." continue*/
         continue;
      if(mode == 0)
         printf("%s%s\n", path, entry->d_name); /*print element including path*/
      if(mode == 1 && strcmp(entry->d_name, substring) == 0)
         printf("%s%s\n", path, entry->d_name); /*print element including path*/
      sprintf(entryPath, "%s%s/", pathname, entry->d_name);
      if (lstat(entryPath, &s) == 0 && S_ISDIR(s.st_mode) != 0) { /*if entry is a directory*/
         sprintf(path + len, "%s/", entry->d_name); /*make pathname*/
         sprint(entryPath, path, mode); /*print directory*/
         path[len] = 0;
      }
   }
   closedir(directory);
}

int main(int argc, char *argv[]) {
   int commandType = 0;

   /*parse command line input and check if it's valid*/
   if(argc < 3) { /*minimum of 3 command line arguments, print/current dir is not defaulted to*/
      printf("We're sorry. This version of sfind does not currently support less than 3 command line arguments. Goodbye!\n");
      exit(-1);
   }
   if(argc == 3) {
      if(strcmp(argv[2], "-print") == 0)
         commandType = 1; /*print*/
      else if(strcmp(argv[2], "-exec") == 0)
         commandType = 3; /*exec*/
      else { /*if "sfind x -qwer" OR "sfind x qwer" OR "sfind -x anything"*/
         if(argv[1][0] == '-')
            printf("find: unknown predicate `%s'\n", argv[1]);
         else if(argv[2][0] == '-')
            printf("find: unknown predicate `%s'\n", argv[2]);
         else
            printf("Please specify a valid command: -print or -exec\n");
         exit(-1);
      }
   }
   if(argc == 4) {
      printf("We're sorry. This version of sfind does not currently support 4 command line arguments. Goodbye!\n");
      exit(-1);
   }
   if(argc == 5) {
      if(strcmp(argv[2], "-name") == 0 && strcmp(argv[4], "-print") == 0) {
         commandType = 2; /*-name print*/
         substring = argv[3];
      }
   }
   /*TODO implement check for argc > 3*/

   if(commandType == 0) {
      if(argc == 5)
         printf("Please fix your input. The format shoud be ./sfind filename -name substring -print\n");
      else
         printf("Unspecified error.\n\nCongrats! The developer implemented the program incorrectly and you found a bug.\n");
      exit(-1);
   }
   /*look for filename. if found: print if print command, then execute the rest of the program*/
   openFilename(argv[1], commandType); 
   return 0;
}
