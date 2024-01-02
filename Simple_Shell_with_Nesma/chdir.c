#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
// chdir function is declared
// inside this header
#include <unistd.h>
int main()
{
    char s[100];
    
    // printing current working directory
    printf("%s\n", getcwd(s, 100));
    DIR *myDIR = opendir(s);
    //pritnf("%s",myDIR);
    // using the command
    chdir("..");
    system("cls");
    system("ls");
    // system("pwd");
    //  printing current working directory
    printf("%s\n", getcwd(s, 100));
    opendir(s);
    // after chdir is executed
    return 0;
}