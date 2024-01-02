#include "shell.h"

char *getPATH(char **env)
{
    char *delim = "=";
    int i = 0;
    char *pathKey, *pathValue, *path;

    while (env[i] != NULL)
    {
        pathKey = strtok(env[i], delim);
        pathValue = strtok(NULL, delim);

        if (pathKey != NULL && pathValue != NULL && strcmp(pathKey, "PATH") == 0)
        {
            path = pathValue;
            return (path);
        }
        i++;
    }
}