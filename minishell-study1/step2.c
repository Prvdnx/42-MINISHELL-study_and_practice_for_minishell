
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <readline/readline.h>
//#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>

void    execute_command(char *command)
{
    pid_t pid = fork();

    if(pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0)
    {
        if
    }
}




