
// https://www.youtube.com/watch?v=DFABCB2CbsU&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

    // A Shell -> R: Read
    //            E: Evaluate
    //            P: Print
    //            L: Loop

int main(void)
{
    char *cmd = NULL;
    char *cmd_cpy = NULL;
    char *token = NULL;
    char *delim = " \n";
    size_t n = 0;
    int argc = 0;
    int i = 0;
    char **argv = NULL;

    printf("$ ");
    if (getline(&cmd, &n, stdin) == -1)
        return (-1);
    
    cmd_cpy = strdup(cmd);

    while (cmd[i])
    {
        if (cmd[i] == '\n')
            printf("\\n ---> Input has %ld characters", strlen(cmd));
        else
            printf("%c", cmd[i]);
        i++;
    }

    return (0);
}

