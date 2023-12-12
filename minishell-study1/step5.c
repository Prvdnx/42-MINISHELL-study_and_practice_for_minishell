

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

    while(token != NULL)
    {
        if(token[0] == '\'' || token[0] == '\"')
        {
            char quote = token[0];
            token++;

            char *endQuote = strchr(token, quote);
            if(endQuote == NULL)
            {
                fprintf(stderr, "Unmatched %c\n", quote);
                exit(EXIT_FAILURE);
            }
            *endQuote = '\0';
        }
        (*args)[*argCount] = strdup(token);
        (*argCount)++;

        token = strtok_r(NULL, " ", &saveptr);
    }
    (*args)[*argCount] = NULL;
}

int main(void)
{
    while(1)
    {
        char * input = readline("minishell> ");

        if(input == NULL)
        {
            printf("Exiting minishell\n");
            exit(EXIT_SUCCESS);
        }

        add_history(input);

        char **args;
        int argCount;
        tokenize_input(input, &args, &argCount);

        if(strcmp(args[0], "exit") == 0)
        {
            printf("Exiting minishell\n");
            free(input);

            for(int i = 0; i < argCount; i++)
                free(args[i]);

            exit(EXIT_SUCCESS);
        }

        execute_command(args[0], args);

        for(int i = 0; i < argCount; i++)
            free(args[i]);

        free(args);
        free(input);
    }
    return (0);
}
// compile with: cc step5.c -lreadline -o minishell




