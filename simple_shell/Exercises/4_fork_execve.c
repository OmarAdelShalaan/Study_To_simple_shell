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
	pid_t my_pid;
    	pid_t pid;
	
	while (printf("$ ")&&((nread = getline(&line, &len, stdin)) != -1)) 
	{
		printf("Retrieved line of length %zd:\n", nread);
		//fwrite(line, nread, 1, stdout);
		token = strtok(line, " ");

		// Keep printing tokens while one of the
		// delimiters present in str[].
		while (token != NULL) 
		{
			printf("token: %s\n", token);
			printf("Before execve\n");
			printf("Before fork\n");
			pid = fork();
			if (pid == -1)
			{
				//perror("Error:");
				return (1);
			}
			if (execve(token, &token, NULL) == -1)	
			{
				perror("Error:");
			}
			printf("After execve\n");
			token = strtok(NULL, " ");
			
		}
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
