
// https://www.youtube.com/watch?v=ilOFM4lbObU&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=8

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

////////// 1 //////////
// int main(void)
// {
//     char str[] = "Jesus Loves You";
//     char *delim = " ";
//     char *token;

//     token = strtok(str, delim);
//     printf("%s\n", token);

//     return (0);
// }


////////// 2 //////////
// int main(void)
// {
//     char str[] = "Jesus Loves You";
//     char *delim = " ";
//     char *token;

//     token = strtok(str, delim);
//     printf("%s ", token);

//     token = strtok(NULL, delim);
//     printf("%s\n", token);

//     return (0);
// }


////////// 3 //////////
// int main(void)
// {
//     char str[] = "Jesus Loves You";
//     //char *str = "Jesus Loves You"; --> Using this would cause a "Segmentation fault (core dumped)"
//     char *delim = " ";
//     char *token;

//     token = strtok(str, delim);

//     while (token != NULL)
//     {
//         printf("%s\n", token);
//         token = strtok(NULL, delim);
//     }
    
//     return (0);
// }


////////// 4 //////////
int main(void)
{
    char *src = "Jesus Loves You";
    char *str = malloc(sizeof(char) * strlen(src));
    char *delim = " ";
    char *token;

    strcpy(str, src);

    token = strtok(str, delim);

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }
    
    return (0);
}