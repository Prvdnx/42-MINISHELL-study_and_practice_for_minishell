

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <string.h>

void    execute_command(char *command, char **args)
{
    pid_t pid = fork();

    if(pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0)
    {
        if(execve(command, args, NULL) == -1)
        {
        perror("execve");
        exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(NULL);
    }
}

void    tokenize_input(char *input, char ***args, int *argCount)
{
    *args = malloc(sizeof(char *) * 10);
    *argCount = 0;

    char *token;
    char *saveptr;

    token = strtok_r(input, " ", &saveptr);

    while
}

