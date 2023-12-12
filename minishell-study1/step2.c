
/*#include <stdio.h>
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
}*/
// minishell.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

// Function prototypes
void execute_command(char *command);

int main(void) {
    char *input;

    while (1) {
        // Display prompt and read user input
        input = readline("minishell> ");

        // Check for ctrl-D or exit command
        if (input == NULL || strcmp(input, "exit") == 0) {
            printf("Exiting minishell\n");
            free(input);
            exit(EXIT_SUCCESS);
        }

        // Add the input to the history
        add_history(input);

        // Execute the command
        execute_command(input);

        // Free the memory allocated by readline
        free(input);
    }

    return 0;
}

void execute_command(char *command) {
    pid_t pid;
    int status;

    // Fork to create a new process
    pid = fork();

    // Check for fork errors
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Child process
    if (pid == 0) {
        // Execute the command in the child process
        if (execve(command, NULL, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        // Wait for the child process to complete
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }
}




