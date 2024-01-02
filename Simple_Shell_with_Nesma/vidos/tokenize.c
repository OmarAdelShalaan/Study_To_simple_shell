#include "shell.h"

int tokenize(char *command, char *argsC[])
{
    char *delim = " ", *token;
    int count = 0;
    token = strtok(command, delim);

    while (token)
    {
        printf("%s\n", token);
        argsC[count++] = token;
        token = strtok(NULL, delim);
    }
    argsC[count] = NULL;
    return (count);
}