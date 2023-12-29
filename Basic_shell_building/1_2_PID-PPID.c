
// https://www.youtube.com/watch?v=cIBmeEpsMj0&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=1
// https://www.youtube.com/watch?v=slj9inMi2-A&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=2
#include <stdio.h>
#include <unistd.h>

/////// 1 /////// add
// int main()
// {
//     int a = 2;
//     int b = 3;
//     int sum = a + b;

//     pid_t pid = getpid();

//     printf("sum is %d\n", sum);
//     printf("the process id of this program is -> %u\n", pid);
//     return (0);
// }


/////// 2 /////// add
// int main()
// {
//     int a = 2;
//     int b = 3;
//     int sum = a + b;

//     pid_t ppid = getppid();

//     printf("%d\n", sum);
//     printf("the parent process id of this program is -> %u\n", ppid);
//     return (0);
// }


/////// 3 /////// subtract
int main()
{
    int a = 5;
    int b = 2;
    int diff = a - b;

    pid_t ppid = getppid();

    printf("The difference is -> %d\n", diff);
    printf("The parent process id of this program is -> %u\n", ppid);
    return (0);
}

// echo $$