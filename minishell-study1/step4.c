
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
        char * input = readline("minishell> ");

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

/*
============### Main Execution Flow ###============

1. User Prompt and Input:
   - The program starts by entering an infinite loop (`while (1)`) to continuously prompt the user for commands.
   - `readline` is used to read input from the user, and the prompt is set as "minishell> ".
        
        while (1)
        {
            char *input = readline("minishell> ");
            // ...
        }

2. Exit Check for Ctrl-D:
   - Checks if `readline` encounters an error or receives EOF (ctrl-D), in which case it exits gracefully.
        
        if (input == NULL)
        {
            printf("Exiting minishell\n");
            exit(EXIT_SUCCESS);
        }

3. Command History:
   - Adds the input to the command history using `add_history`.

        add_history(input);

4. Tokenization of Input:
   - Tokenizes the input using `strtok` to separate the command and its arguments.
   - The first token (`command`) represents the command itself.

        char *token = strtok(input, " ");
        char *command = token;

5. Exit Check for "exit" Command:
   - Checks if the command is "exit". If true, it prints a message and exits the minishell.
        
        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting minishell\n");
            free(input);
            exit(EXIT_SUCCESS);
        }

6. Dynamic Memory Allocation for Arguments:
   - Allocates memory for an array (`args`) to store command-line arguments.
   - Assumes a maximum of 10 arguments (you can adjust this as needed).

        char **args = malloc(sizeof(char *) * 10);

7. Argument Tokenization Loop:
   - Uses a loop to continue tokenizing the input and populate the `args` array.

        int i = 0;
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            args[i++] = token;
        }
        args[i] = NULL; // Null-terminate the arguments array

8. Command Execution:
   - Calls the `executeCommand` function with the command and arguments.
   - `executeCommand` forks a new process and executes the command in the child process.

        executeCommand(command, args);

9. Memory Cleanup:
   - Frees the memory allocated for both the input and arguments in each iteration of the loop.

        free(input);
        free(args);


============### `execute_command` Function ###============

1. Forking a New Process:
   - `fork` is used to create a new process.

        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

2. Child Process Execution:
   - In the child process, `execve` is used to replace the current process with a new one based on the provided command and arguments.

        if (pid == 0)
        {
            if (execve(command, args, NULL) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }

3. Parent Process Waiting:
   - In the parent process, it waits for the child process to complete using `wait`.

        else
        {
            wait(NULL);
        }

===### Memory Management ###===

1. Dynamic Memory Allocation:
   - The program uses dynamic memory allocation for the `args` array to store command-line arguments.

        char **args = malloc(sizeof(char *) * 10);

2. Memory Deallocation:
   - The program frees the memory allocated for both `input` and `args` at the end of each loop iteration.

        free(input);
        free(args);

===### Command Execution and Loop ###===

1. Execute Commands:
   - The `executeCommand` function is responsible for forking and executing the command.

        execute_command(command, args);

2. Infinite Loop:
   - The program is structured in an infinite loop (`while (1)`) to continuously prompt the user for commands until they decide to exit.

        while (1)
        {
            // ...
        }

===### User Interaction ###===

1. Prompt Display:
   - The program displays a prompt ("minishell> ") to indicate that it is waiting for a new command.

        char *input = readline("minishell> ");

2. Command History:
   - User commands are added to the history using `add_history`.

        add_history(input);

===### Exit and Cleanup ###===

1. Exit on Ctrl-D
   - Checks if `readline` encounters an error or receives EOF (ctrl-D) and exits gracefully.

        if (input == NULL)
        {
            printf("Exiting minishell\n");
            exit(EXIT_SUCCESS);
        }

2. Exit on "exit" Command:
   - Checks if the command is "exit" and exits the minishell.

        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting minishell\n");
            free(input);
            exit(EXIT_SUCCESS);
        }


This minishell program now allows users to enter commands with arguments, executes them, and
continuously prompts for new commands until the user decides to exit. It's a basic structure
that can be extended to handle more complex features as required by the minishell project requirements.*/
