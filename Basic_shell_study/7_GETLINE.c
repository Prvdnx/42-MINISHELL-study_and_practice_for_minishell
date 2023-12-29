
// https://www.youtube.com/watch?v=Lx5r2XQvpVA&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj&index=7

#include <stdio.h>
#include <stdlib.h>

/////// 1 ///////
int main()
{
    size_t n = 10;
    char *buf = malloc(sizeof(char) * n);

    printf("Enter name ");
    getline(&buf, &n, stdin);

    printf("Name is %sBuffer size is %ld\n", buf, n);

    free(buf);

    return (0);
}


/////// 2 ///////
// int main()
// {
//     size_t n = 10;
//     char *buf = NULL;

//     printf("Enter name ");
//     getline(&buf, &n, stdin);

//     printf("Name is %sBuffer size is %ld\n", buf, n);

//     free(buf);

//     return (0);
// }

