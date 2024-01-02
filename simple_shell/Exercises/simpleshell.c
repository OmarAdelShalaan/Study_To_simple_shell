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
    char *ptrline[11];
    int count;
    
    while (printf("$ ") && ((nread = getline(&line, &len, stdin)) != -1)) {
        // Remove the newline character at the end of the line
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }
        
        count = 0;
        token = strtok(line, " ");
        while (token != NULL && count < 10) {
            ptrline[count] = strdup(token);
            token = strtok(NULL, " ");
            count++;
        }
        ptrline[count] = NULL;

        if (count == 0) {
            // No command entered, skip the rest
            continue;
        }

        int i;
        for (i = 0; i < count; i++) {
            printf("%s  ", ptrline[i]);
        }
        printf("\nBefore execve\n");

        pid_t pid;
        if ((pid = fork()) == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Child process
            if (execvp(ptrline[0], ptrline) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else { // Parent process
            wait(NULL); // Wait for the child to finish
        }

        // Free the memory allocated for duplicated strings
        for (i = 0; i < count; i++) {
            free(ptrline[i]);
        }
    }

    free(line);
    exit(EXIT_SUCCESS);
}

