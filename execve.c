#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	int s = 24;
	char *const argv[] = {"/usr/bin/ls", "-l", "/media/omar/Hard Disk/ALX_folder", NULL};
	//char * const argv[] = {"./helloOmar", NULL};
	printf("Hello, exeve....\n");
	fflush(stdin);
	getchar();
	int fflag = fork();
	if(fflag ==0)
	{
		printf("Child\n");
		execve(argv[0], argv, NULL);
	}
	else if(fflag == -1)
	printf("fealuire");
	else 
	{
		wait(&s);
		printf("\n\n\n\nParent %d\n",s);
	}
	
	printf("After execve\n");
	return (0);
}








