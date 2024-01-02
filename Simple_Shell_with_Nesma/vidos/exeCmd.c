#include "shell.h"

int exeCmd(char *argsC[])
{
    pid_t pid;
    int exe, status;

    pid = fork();

    if (pid == -1)
    {
        perror("Failed to create process\n");
    }
    else if (pid == 0)
    {
        //exe = execve(argsC[0], (char  * const )argsC[], NULL);
        exe = execve(argsC[0], argsC, NULL);
        if (exe == -1)
        {
            perror("Failed executing command\n");
        }
    }
    else
        wait(NULL);
    return (0);
}
