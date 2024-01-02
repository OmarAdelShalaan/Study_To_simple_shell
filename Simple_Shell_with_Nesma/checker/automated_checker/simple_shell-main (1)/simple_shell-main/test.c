#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

extern char **environ;

int main()
{
    char **env;
    char name[] = "PATH";
	size_t name_len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		//if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			printf("\n\n%s\n\n",(*env)) ;
		}
	}

    return 0;
}