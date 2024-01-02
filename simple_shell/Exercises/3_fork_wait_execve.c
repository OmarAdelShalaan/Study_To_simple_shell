#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char* token = NULL;
	char *ptrline[10];
	int count = 0;
	pid_t my_pid;
    	pid_t pid;
    	char path[128] = "/user/bin/";

	while (printf("$ ")&&((nread = getline(&line, &len, stdin)) != -1)) 
	{
		printf("Retrieved line of length %zd:\n", nread);
		//fwrite(line, nread, 1, stdout);
		token = strtok(line, " ");
	        strcat (path, token);
		ptrline[count] = path;

		// Keep printing tokens while one of the
		// delimiters present in str[].
		while (token != NULL) 
		{
			count++;
			printf("token: %s\n", token);
			token = strtok(NULL, " ");
			ptrline[count] = token;
			
		}
		count++;
		ptrline[count] = NULL;
		count = 0;
		while (ptrline[count] != NULL)
		{
			printf("%s  ", ptrline[count]);
			count++;
		}
		
		printf("Before execve\n");
		if (execve(ptrline[0], ptrline, NULL) == -1)	
		{
			perror("Error:");
		}
		//wait();
		printf("After execve\n");
	}

	free(line);
	exit(EXIT_SUCCESS);
}

/*
char* token = strtok(str, " - ");

	// Keep printing tokens while one of the
	// delimiters present in str[].
	while (token != NULL) {
		printf(" % s\n", token);
		token = strtok(NULL, " - ");
	}
	
	 printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
*/
