
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <string.h>

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
        if(execve(command, NULL, NULL) == -1)
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

int main (void)
{
    char *input = readline("minishell> ");

    if(input == NULL)
    {
        printf("Exiting minishell\n");
        exit(EXIT_SUCCESS);
    }

    add_history(input);

    printf("You entered: %s\n", input);

    char *command = strtok(input, " ");

    if(strcmp(command, "exit") == 0)
    {
        printf("Exiting minishell\n");
        exit(EXIT_SUCCESS);
    }

    execute_command(command);

    free(input);

    return(0);
}
// compile with: cc step3.c -lreadline -o minishell

/*Explanation:

execute_command Function:
I created a new function called executeCommand to encapsulate the logic related to forking and executing the command.
The function takes a char* parameter (command), representing the command to be executed.

Forking and Executing in execute_command:
Inside execute_command, I kept the code responsible for forking and executing the command.
It forks a new process, and in the child process, it executes the command using execve.

Main Function:
The main function now focuses on user input and high-level control flow.
It reads user input using readline, adds it to the history, and displays the entered command.
The tokenization logic is kept here for now (to be implemented in later steps). It splits the input
into tokens, and we assume a simple command without arguments for now.
It checks if the command is "exit" and exits the shell if true.
The actual execution of the command is delegated to the executeCommand function.*/
