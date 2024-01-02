#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    // char *const argv[] = {"/usr/bin/ls", "-l", "/media/omar/Hard Disk/ALX_folder", NULL};
    char * const argv[] = {"./execve", NULL};
    printf("Hello, Omar....\n");
    fflush(stdin);
     getchar();
    execve(argv[0], argv, NULL);
    printf("After execve\n");
    return (0);
}
