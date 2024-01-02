#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ARGS 100
extern char **environ;

/**
 * main - execve example
 *
 * Return: Always 0.
 */

size_t gitCommandLine();
void cutCommandLine(char *buffer, char *argv[MAX_ARGS]);
int exeCommandLine(char *argv[MAX_ARGS]);
void Printenv();
void FREEARGV(char **argv);



int main(void)
{
	int len = 0;
	char *buffer = NULL;
	size_t bufsize = 1024;
	size_t characters = 0;
	char *argv[MAX_ARGS] = {NULL};
	int i = 0;
	char *tempPTR;

	while (1)
	{
	    characters = gitCommandLine(&buffer, &bufsize);
		if(buffer[0] == ' ')
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		else if(buffer[0] == '\n')
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		cutCommandLine(buffer, argv);
		//printf("Done CutCommand\n");
		if(!strcmp(argv[0], "exit"))
		{
			printf("exit\n");
			exit(0);
		}
		else if((*argv[0]) == '/')
		{	
			exeCommandLine(argv);
        	//printf("Done exeCommand\n");
		}
		else if (!strcmp(argv[0], "env"))
		{
			Printenv();
		}
		else
		{
			//handle PATH
			//PutPATH();
		}
        /*
		i = 0;
		while (argv[i] != NULL)
		{
			tempPTR = argv[i];
			printf("argv: %s\n",*argv);
			//argv[i] = NULL;
			printf("temp: %s\n",tempPTR);
			free(tempPTR);
			i++;
		}
		*/
		//realloc(argv,0);
		//printf("%s\n",buffer);
		//free(buffer);
        //buffer = NULL;
		//FREEARGV(argv);
		free(buffer);
		buffer = NULL;
		
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
		    free(buffer);
			//if (EOF) exit(1);
			printf("Fauiler Realloc\n");
		    return -1;
		}
		if((*buffer)[characters - 1] == '\n' && characters != 1)
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
char *_getenv(const char *name)
{
	char **env;
	size_t name_len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}
void Printenv()
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
/*
void FREEARGV(char **argv)
{
	/*
	int i = 0, j = 0;

	while(*argv != NULL)
	{
		/*
		while(argv[i][j] != '\0')
		{
			printf("%c ", argv[i][j]);
			free(argv[i]);
			j++;
		}
		printf("\n");
		
		printf("1.free\n");
		free(*argv);
		printf("2.free\n");
		*argv = NULL;
		printf("3.free\n");
		argv++;
		i++;
	}
	
int i = 0;
char *temp;
    while (argv[i] != NULL) {
        printf("Freeing: %s\n", argv[i]);
        temp = argv[i];
		mfree(argv[i],strlen(argv[i]) + 1);
        //realloc(temp, 0);
		argv[i] = NULL; // Set to NULL after freeing to avoid potential double free
        i++;
    }
}
*/