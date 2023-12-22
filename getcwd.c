#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#define PATH_MAX    1024

int main() {
    char pwd[PATH_MAX]; // Allocate a buffer for the path

    if (getcwd(pwd, sizeof(pwd)) != NULL) {
        printf("Current working directory: %s\n", pwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    return 0;
}
