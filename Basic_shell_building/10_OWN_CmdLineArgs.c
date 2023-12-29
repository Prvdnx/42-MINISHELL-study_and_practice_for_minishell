
// https://www.youtube.com/watch?v=DFABCB2CbsU&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


    // A Shell -> R: Read
    //            E: Evaluate
    //            P: Print
    //            L: Loop


///////// 1 //////////
// int main(void)
// {
//     char *cmd = NULL;
//     char *cmd_cpy = NULL;
//     char *token = NULL;
//     char *delim = " \n";
//     size_t n = 0;
//     int argc = 0;
//     int i = 0;
//     char **argv = NULL;

//     printf("$ ");
//     if (getline(&cmd, &n, stdin) == -1)
//         return (-1);
    
//     cmd_cpy = strdup(cmd);

//     while (cmd[i])
//     {
//         if (cmd[i] == '\n')
//             printf("\\n ---> Input has %ld characters\n", strlen(cmd));
//         else
//             printf("%c", cmd[i]);
//         i++;
//     }

//     return (0);
// }


///////// 2 //////////
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

    token = strtok(cmd, delim);

    while (token)
    {
        token = strtok(NULL, delim);
        argc++;
    }

    printf("%d\n", argc);

    argv = malloc(sizeof(char *) * argc);

    token = strtok(cmd_cpy, delim);

    while (token)
    {
        argv[i] = token;
        token = strtok(NULL, delim);
        i++;
    }
    argv[i] = NULL;

    i = 0;

    while (argv[i])
        printf("%s\n", argv[i++]);

    free(cmd), free(cmd_cpy), free(argv);

    return (0);
}


