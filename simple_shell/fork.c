#include <stdio.h>
#include <unistd.h>
#define _XOPEN_SOURCE 700
/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t pid;

    printf("Before fork\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return (1);
    }
    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    return (0);
}
/*
julien@ubuntu:~/c/shell$ ./fork 
Before fork
After fork
My pid is 4819
julien@ubuntu:~/c/shell$ After fork
My pid is 4820

*/