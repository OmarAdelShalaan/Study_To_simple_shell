#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token = NULL;
    char *ptrline[11]; // Increase the size to 11 to hold the command and its arguments
    int count = 0;
    pid_t my_pid;
    pid_t pid;
    char *pathtemp = "/bin/";
    char path[128] = "/bin/";
    int i = 0;
    
    
    
    while (printf("$ ") && ((nread = getline(&line, &len, stdin)) != -1)) {
        // Remove the newline character at the end of the line
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }
	
        token = strtok(line, " ");
        strcat(path, token);
        ptrline[count] = path; // Make a copy of the path

        // Keep printing tokens while one of the
        // delimiters present in str[].
        while (token != NULL) {
            count++;
            token = strtok(NULL, " ");
            if (token != NULL) {
                ptrline[count] = strdup(token); // Make a copy of the token
            }
        }
        count++;
        ptrline[count] = NULL;

        count = 0;
        while (ptrline[count] != NULL) {
            printf("%s  ", ptrline[count]);
            count++;
        }

        printf("\nBefore execve\n");
        if ((pid = fork()) == -1) {
            perror("fork");
        } else if (pid == 0) { // Child process
            if (execvp(ptrline[0], ptrline) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else { // Parent process
            wait(NULL); // Wait for the child to finish
        }

        // Free the memory allocated for duplicated strings
        for (int i = 0; i < count - 1; i++) {
            free(ptrline[i]);}
            
        
    }

    free(line);
    exit(EXIT_SUCCESS);
}

