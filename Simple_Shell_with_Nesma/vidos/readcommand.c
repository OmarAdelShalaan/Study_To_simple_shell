#include "shell.h"

/*
 * readCommand - Fun to take user input
 */
int readCommand(void)
{
    size_t n = 0;
    char *buff = NULL, *command, *argsC[MAX_ARGS];
    int size, argcount;

    size = getline(&buff, &n, stdin);
    if (size == -1)
    {
        if (feof(stdin))
        {
            free(buff);
            exit(0);
        }
        else
        {
            perror("Failed to read user input");
            free(buff);
        }
    }
    command = removeNC(buff, size);
    printf("%s", command);
    argcount = tokenize(command, argsC);
    printf("%s\t%s\n", argsC[0], argsC[1]);
    exeCmd(argsC);

    free(buff);
    return (size);
}