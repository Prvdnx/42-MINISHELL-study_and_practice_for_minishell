
// https://www.youtube.com/watch?v=jNmmizQXJC8&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /*
        argv looks like this

        char *argv[] = {"./cmd_line_args", "coding", "is", "fun", NULL};
    */

    printf("argc: %d\n", argc);

    for (int i = 0; argv[i]; i++)
        printf("argv[%d]: %s\n", i, argv[i]);

    return (0);
}
