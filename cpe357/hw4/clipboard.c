
   if(strcmp(filename, ".") == 0) {
      char originalPath[1024];
      int len = 
      originalPath = "./";
      while((entry = readdir(directory))) { /*while there are more entries*/
         if (lstat(dirToOpen, &s) == 0 && S_ISDIR(s.st_mode)) { /*if directory entry is a directory*/
            char pathname[1024];
            int len = snprintf(pathname, sizeof(pathname)-1, "%s/%s", dirToOpen, entry->d_name); /*make pathname*/
            pathname[len] = 0;
            if((strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0)) /*if the directory isn't . or ..*/
               continue;
            printf("%s/%s\n", dirToOpen, entry->d_name);
            sprint(filename, pathname, 1);
         }
      }
      closedir(directory);
   }
   
   if(strcmp(filename, "..") == 0) {
      do {
         if (lstat(dirToOpen, &s) == 0 && S_ISDIR(s.st_mode)) { /*if directory entry is a directory*/
            char pathname[1024];
            int len = snprintf(pathname, sizeof(pathname)-1, "%s/%s", dirToOpen, entry->d_name); /*make pathname*/
            pathname[len] = 0;
            if((strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0)) /*if the directory isn't . or ..*/
               continue;
            printf("%s/%s\n", dirToOpen, entry->d_name);
            sprint(filename, pathname, 1);
         }
      } while ((entry = readdir(directory))); /*while there are more entries*/
      closedir(directory);
   }

   else {
      do {
         if (lstat(entry->d_name, &s) == 0 && S_ISDIR(s.st_mode)) { /*if directory entry is a directory*/
            char pathname[1024];
            int len = snprintf(pathname, sizeof(pathname)-1, "%s/%s", dirToOpen, entry->d_name); /*make pathname*/
            pathname[len] = 0;
            if((strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0)) /*if the directory isn't . or ..*/
               continue;
            if(strcmp(entry->d_name, filename) == 0) {
               if (depth == 0)
                  printf("%s\n", entry->d_name);
               else
                  printf("%s/%s\n", dirToOpen+2, entry->d_name);
            }
            sprint(filename, pathname, 1);
         }
      } while ((entry = readdir(directory))); /*while there are more entries*/
      closedir(directory);
   }
