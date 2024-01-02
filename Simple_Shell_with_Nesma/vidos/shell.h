#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 125

int readCommand(void);
char *removeNC(char *str, int len);
int tokenize(char *command, char *argsC[]);
int exeCmd(char *argsC[]);
char *getPATH(char **env);
char *Cstrcat(char *str1, char *str2);


#endif
