
//https://www.youtube.com/watch?v=wXkHx_noxws&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=5
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

/////// 1 /////// wait
/*int main(void)
{
    pid_t pid;

    // Before fork is called

    // Call fork -> Child process is created
    pid = fork();

    if (pid == -1)
    {
        perror("Unsucessful\n");
        return 1;
    }

    // In child process
    if (pid == 0)
    {
        printf("I am in the child process\n");
    }
    // In parent process
    else
    {
        sleep(30);
        printf("The is the parent process\n");
    }

    return (0);
}*/


////// 2 /////// wait
#include <sys/wait.h>
int main(void)
{
    pid_t pid; 

    // Before fork is called

    // Call fork -> Child process is created
    pid = fork();

    if (pid == -1)
    {
        perror("Unsucessful\n");
        return 1;
    }

    // In child process
    if (pid == 0)
    {
        printf("I am in the child process\n");
    }
    // In parent process
    else
    {
        wait(NULL);
        sleep(30);
        printf("The is the parent process\n");
    }

    return (0);
}


