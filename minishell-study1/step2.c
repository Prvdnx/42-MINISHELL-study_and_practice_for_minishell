
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

// Step 1 & 2
int main(void)
{
    printf("Welcome to my Minishell!\n");
    char *input = readline("minishell> ");

    if (input == NULL)
        {
            printf("Exiting minshell\n");
            exit(EXIT_SUCCESS);
        }
    add_history(input);
    printf("You entered: %s\n", input);

    free(input);
    return (0);
}
// compile with: cc step2.c -lreadline -o minishell

/* EXPLANATION

#include <stdio.h>: Standard Input/Output library for functions like printf.

#include <stdlib.h>: Standard library for functions like exit and dynamic memory allocation (malloc, free).

#include <unistd.h>: Unix Standard library for functions like fork, execve, pipe, etc.

#include <readline/readline.h>: Library for readline function to get user input.

#include <readline/history.h>: Library for history related functions (add_history).

int main(void) {: Main function declaration.

char *input = readline("minishell> ");: Display prompt "minishell> " and read user input using readline.

if (input == NULL) { ... }: Check if readline encountered an error or received EOF (ctrl-D), and exit gracefully.

add_history(input);: Add the input to the command history.

printf("You entered: %s\n", input);: Display the entered command.

free(input);: Free the memory allocated by readline.

return 0;: Exit the program. */