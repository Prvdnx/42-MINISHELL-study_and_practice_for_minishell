

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

/*The code uses system calls and standard library functions for process management,
input handling, and command execution.


==== Function execute_command(char *command, char **args) ====

This function takes a command and an array of arguments as input and executes the specified command
using the system call fork(), as well as execve() to replace the current process image with a new one.

1. The function begins with a call to fork(), which creates a new child process that is a copy
of the calling process. The new process, referred to as the child process, is an exact copy of
the calling process except for the returned values.

2. After forking, the function checks the return value of fork() to determine whether the call
was successful. If fork() returns -1, an error occurred, and the function calls perror() to print
an error message derived from the global variable errno and then exits with a failure status.

3. If fork() returns 0, this indicates that the function is being executed in the newly created
child process. In this case, the child process uses execve() to execute the specified command
using the arguments provided.

4. Inside the if block for the child process, the function calls execve() with the command,
arguments, and a null environment pointer. If execve() fails, meaning that the command could
not be executed, the function calls perror() to print an error message and then exits the child
process with a failure status.

5. If fork() returns a positive value, this indicates that the function is being executed in
the parent process, i.e., the original process that called fork(). In this case, the parent
process waits for the child process to terminate by calling the wait() system call.

6. The wait() system call suspends the execution of the parent process until a child process
specified by the process ID (PID) argument has terminated. In this case, the parent process
does not explicitly collect the termination status or return value of the child process.


==== Function tokenize_input(char *input, char ***args, int *argCount) ====

This function takes a string of input, a pointer to an array of strings (args), and a pointer
to an integer variable (argCount) as input. It tokenizes the input string into individual words
(tokens) and populates the args array with these tokens.

1. The function initializes the args array by allocating memory to hold 10 pointers to strings.
It also initializes argCount to 0.

2. Inside the function, strtok_r() is used to tokenize the input string. This function treats
the input string as a sequence of tokens (words) delimited by specified characters (in this
case, space characters).

3. The function iterates through the tokens by repeatedly calling strtok_r() with the input
string and a pointer to a "saveptr" variable. This pointer acts as a cursor to keep track of
the current position in the input string.

4. Within the loop, each token is processed to handle quoted substrings. If the token starts
with a single quote (' ) or double quote ("), the function removes the quote and captures
the contents until the matching quote is found. It then updates the token to contain only
the contents without the quotes.

5. After processing the token, it dynamically allocates memory to store a copy of the token
and assigns the pointer to the array args at the position indicated by argCount. It then
increments argCount to keep track of the number of tokens processed.

6. The function continues tokenizing the input string until there are no more tokens, at which
point it assigns NULL to the last element of the args array to mark the end of the token list.

7. It's important to note that the function allocates memory to store each token using the strdup()
function, which creates a new string in memory and returns a pointer to it. This allocated memory
needs to be explicitly deallocated to prevent memory leaks.


==== The main function ====

The main function serves as the entry point for the minishell program. It consists of a
continuous loop where the user is prompted with "minishell> " to enter commands.

1. Inside the loop, the function uses the readline() function to read a line of input from the user.
If the input is NULL, the program prints "Exiting minishell" and exits with a success status.

2. The add_history() function is called to add the input to the history list, allowing the user
to access previous commands using the arrow keys.

3. The tokenize_input() function is called to tokenize the input string into individual words
(tokens) and populate the args array with these tokens.

4. The program then checks if the command entered is "exit". If so, it prints "Exiting
minishell", frees the allocated memory for input and arguments, and exits with a success status.

5. If the command is not "exit", the execute_command() function


===== The memory management =====

1. Dynamic Memory Allocation:
   - Within the `tokenize_input` function, memory is dynamically allocated to store each token
   using the `strdup` function. This allows the function to create a new string in memory for each
   token and returns a pointer to it.
   - At the beginning of the `tokenize_input` function, memory is allocated to hold 10 pointers
   to strings using the `malloc` function.

2. Memory Deallocation:
   - In the `main` function, after the execution of a command or when the user enters "exit", a loop is
   used to free the dynamically allocated memory for each token in the `args` array using the `free` function.
   - Additionally, after the loop, the memory allocated for the `args` array itself and the input string
   are freed using the `free` function.
*/

