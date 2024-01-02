#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ARGS 100

/**
 * main - execve example
 *
 * Return: Always 0.
 */

size_t gitCommandLine();
void cutCommandLine(char *buffer, char *argv[MAX_ARGS]);
int exeCommandLine(char *argv[MAX_ARGS]);
 
int main(void)
{
	int len = 0;
	char *buffer = NULL;
	size_t bufsize = 1024;
	size_t characters = 0;
	char *argv[MAX_ARGS] = {NULL};
	char *tempPtr = NULL;
	int i = 0;

	while (1)
	{
	    characters = gitCommandLine(&buffer, &bufsize);
		cutCommandLine(buffer, argv);
		//printf("Done CutCommand\n");
		exeCommandLine(argv);
        //printf("Done exeCommand\n");
		
        free(buffer);
		for (i = 0; i < MAX_ARGS; i++) {
            argv[i] = NULL;
        }
		
	}
	return (0);
}
size_t gitCommandLine(char **buffer, size_t *bufsize)
{
        // --------------------------get command line -----------------------------------------------
		printf("($) ");
		size_t characters = getline(buffer, bufsize, stdin); // omar\n\0==>5
		//printf("characters were read: %ld.\n", characters);
		//printf("You typed: %s\n", *buffer);
		//----------------------------------------------------------------------------------------
		if (buffer == NULL)
		{
			printf("Fauiler Realloc\n");
		}
		if((*buffer)[characters - 1] == '\n')
		    (*buffer)[characters - 1] = '\0';
		return characters;
}
void cutCommandLine(char *buffer, char *argv[MAX_ARGS])
{
        // ----------------------Cut Buffer--------------------
        char *tok = NULL;
        int i = 0;
                                    //omar adel shalaan/0
        tok = strtok(buffer, " ");
        while (tok != NULL)
		{
			argv[i] = tok;
			//printf("tok: %s,  argv: %s\n", tok, argv[i]); ////omar\0adel shalaan\0
			tok = strtok(NULL, " ");					  ////omar\0adel\0shalaan\0
			i++;
		}
		tok = NULL;
		argv[i] = NULL;
}
int exeCommandLine(char *argv[MAX_ARGS])
{
        int fflag = 0;

        // ------------------fork to child execve------------------------
		fflag = fork();
		if (fflag == -1)
		{
			printf("fealuire");
			return (-1);
		}
		else if (fflag == 0)
		{
			// --------------------------child execve--------------------
			//printf("Child\n");
			execve(argv[0], (char **)argv, NULL);
		}
		else
		{
			// --------------------------wait child execve--------------------
			wait(NULL);
			//printf("\nParent\n");
			return (0);
		}
		//printf("After execve\n");
		return (2);
}


