#include "shell.h"

char *removeNC(char *str, int len)
{
    if (str > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
    return (str);
}