
// https://www.youtube.com/watch?v=FbUCu28Joj4&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=3
// https://www.youtube.com/watch?v=Pdf1_Gm5G2s&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=4
#include <unistd.h>
#include <stdio.h>

/////// 1 /////// fork1
/*int main(void)
{
    pid_t pid;

    printf("Before fork, I was one\n");

    pid = fork();

    if (pid == -1)
    {
        perror("Unsucessful\n");
        return 1;
    }

    printf("After fork, I became two\n");

    return (0);
}


/////// 2 /////// fork2
int main(void)
{
    pid_t pid;

    // Before fork is called

    // Call fork
    pid = fork();

    if (pid == -1)
    {
        perror("Unsucessful\n");
        return 1;
    }

    if (pid == 0)
    {
        sleep(5);
        printf("I am in the child\n");
    }
    else
        printf("I am the parent\n");

    return (0);
}*/


/////// 3 /////// fork3
int main(void)
{
    pid_t pid;
    pid_t ppid;

    // Before fork is called

    // Call fork
    pid = fork();

    if (pid == -1)
    {
        perror("Unsucessful\n");
        return 1;
    }

    if (pid == 0)
    {
        sleep(40);
        printf("I am in the child\n");
    }
    else
    {
        ppid = getpid();
        printf("The parent pid is %u\n", ppid);
    }

    return (0);
}


