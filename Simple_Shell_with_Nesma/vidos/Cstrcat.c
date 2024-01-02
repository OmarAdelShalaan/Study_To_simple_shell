#include "shell.h"

char *Cstrcat(char *str1, char *str2)
{
    int len1 = strlen(str1), len2 = strlen(str2);
    char *result = (char *)malloc(len1 + len2 + 2);

    result = strcat(str1, "/");
    result = strcat(result, str2);
    result = strcat(result, "\0");

    return (result);
}