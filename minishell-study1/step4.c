
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

int main(void)
{
    while(1)
    {
        char * input = readline("minishell");

        if(input == NULL)
        {
            printf("Exiting minishell\n");
            exit(EXIT_SUCCESS);
        }

        add_history(input);

        char *token = strtok(input, " ");
        char *command = token;

        if(strcmp(command, "exit") == 0)
        {
            printf("Exiting minishell\n");
            free(input);
            exit(EXIT_SUCCESS);
        }

        char **args = malloc(sizeof(char *) * 10);

        int i = 0;
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            args[i++] = token;
        }

        args[i] = NULL;

        execute_command(command, args);

        free(input);
        free(args);
    }
    return (0);
}

