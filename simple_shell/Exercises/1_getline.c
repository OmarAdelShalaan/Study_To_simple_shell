#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *stream;
   char *line = NULL;
   size_t len = 0;
   ssize_t nread;

   while (printf("$ ")&&((nread = getline(&line, &len, stdin)) != -1)) {
       printf("Retrieved line of length %zd:\n", nread);
       fwrite(line, nread, 1, stdout);
   }

   free(line);
   fclose(stream);
   exit(EXIT_SUCCESS);
}


