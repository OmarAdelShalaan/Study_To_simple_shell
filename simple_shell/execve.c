#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}

/*
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic exec.c -o exec
julien@ubuntu:~/c/shell$ ./exec 
Before execve
total 120
drwxr-xr-x   2 root root 61440 Dec  4 00:08 bin
drwxr-xr-x   2 root root  4096 Jul 19 13:47 games
drwxr-xr-x  58 root root  4096 Oct 27 13:10 include
drwxr-xr-x 138 root root  4096 Dec  4 00:08 lib
drwxr-xr-x   3 root root  4096 Nov 10 09:54 lib32
drwxr-xr-x   3 root root  4096 Nov 10 09:54 libx32
drwxr-xr-x  10 root root  4096 Jul 19 13:42 local
drwxr-xr-x   3 root root  4096 Jul 19 13:48 locale
drwxr-xr-x   2 root root 12288 Dec  2 11:03 sbin
drwxr-xr-x 295 root root 12288 Jul 27 08:58 share
drwxr-xr-x   6 root root  4096 Dec  1 11:39 src
julien@ubuntu:~/c/shell$ 

*/
