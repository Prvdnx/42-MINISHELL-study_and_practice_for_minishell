// https://www.youtube.com/watch?v=Wtd-8OiZOjk&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=6

#include <unistd.h>
#include <stdio.h>

////// 1 //////
// int main()
// {
//     char *argv[] = {"/bin/ls", "-l", NULL};

//     int value = execve(argv[0], argv, NULL);

//     if(value == -1)
//         perror("Error");

//     printf("Done with execve!");

//     return (0);
// }



////// 2 //////
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    char *argv[] = {"/bin/ls", "-l", NULL};

    pid = fork();

    if (pid == -1)
        return (-1);

    if (pid == 0)
    {
        int value = execve(argv[0], argv, NULL);

        if(value == -1)
            perror("Error");
    }
    else
    {
        wait(NULL);
        printf("\nDone with execve!\n");
    }
    return (0);
}

