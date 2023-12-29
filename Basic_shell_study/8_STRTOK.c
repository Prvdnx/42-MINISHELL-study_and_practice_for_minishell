
// https://www.youtube.com/watch?v=ilOFM4lbObU&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=8

#include <stdio.h>
#include <string.h>

////////// 1 //////////
int main(void)
{
    char str[] = "Jesus Loves You";
    char *delim = " ";
    char *token;

    token = strtok(str, delim);

    printf("%s", token);
    return (0);

}

