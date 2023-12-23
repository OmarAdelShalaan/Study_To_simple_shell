#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	int fflag = 0, len;
	char * buffer = NULL;
	size_t bufsize = 1024;
	size_t characters = 0;
	char * argv[10];
//	argv[10]= {ptr1,ptr2,ptr3,ptr4,...,ptr10}
	int i = 0;
	// char *const argv[] = {"/usr/bin/ls", "-l", "/media/omar/Hard Disk/ALX_folder", NULL};
	//char * const argv[] = {"./execve", NULL};
	//execve(argv[0], argv, NULL);
	//printf("After execve\n");
	while(1){
		    // --------------------------get command line -----------------------------------------------
		    printf("Type something: ");
		    characters = getline(&buffer,&bufsize,stdin);    //omar\n\0==>5
		    printf("characters were read: %ld.\n",characters);
		    printf("You typed: %s\n",buffer);
		    //----------------------------------------------------------------------------------------
		    /* Reallocating memory */
		    //buffer = (char *) realloc(buffer, characters + 5);
		    if(buffer == NULL)
		    {
			    printf("Fauiler Realloc\n");
		    }
		    // --------------------------Cut Buffer-------------------------------------------
		    //strcat(buffer, "NULL");
		    printf("Before Strtok\n");
		    buffer[characters - 1] = '\0';
		    buffer = strtok( buffer, " ");
		    printf("after Strtok\n");
		    i = 0;
		    while(buffer != NULL)
		    {
		        //strcpy(argv[i] , buffer);
		        argv[i] = buffer;//omar\0adel\0shalaan\0//	argv[10]= {ptr1,ptr2,ptr3,ptr4,...,ptr10}
		        printf("buffer: %s,  argv: %s\n",buffer,argv[i]);////omar\0adel\0shalaan\0
		        buffer = strtok(NULL, " ");////omar\0adel\0shalaan\0
		                                    ////adel\0shalaan\0
		        i++;
		    }
		    //*argv[i] += "\0";
		    //strcat(argv[i],"\0");
		    i = 0;
		    while(argv[i] != NULL)
		    {
		        printf("*****%s\n",argv[i]);
		        i++;
		    }
		    printf("Done argv add\n");
		    //		char *strtok(char *str, const char *delims);
		    //char * argv[] = strtok( buffer, " ");
		    //strtok--------------------------------------------------
		    //add Path /usr/bin/--------------------------------------$PATHls
		    
		    // ------------------fork to child execve----------------------------
		    fflag = fork();
		    if (fflag == 0)
		    {
		    // --------------------------child execve--------------------
			    printf("Child\n");
			    
			    execve(argv[0], ( char **)argv, NULL);
		    }
		    else if (fflag == -1)
			    printf("fealuire");
		    else 
		    {
			    // --------------------------wait child execve--------------------
			    wait(NULL);
			    printf("\n\n\n\nParent\n");
		    }
		    
		    printf("After execve\n");
		    free(buffer);
        	i = 0;
        	while(argv[i] != NULL)
		    {
                argv[i] = NULL;
		        i++;
		    }
		}
	return (0);
}

















