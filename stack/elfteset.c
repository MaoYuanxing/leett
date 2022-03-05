#include <stdio.h>
int main()
{
    // printf("hello world!\n");
    char *str = "hello";
    *str = 'H';
    printf("%s\n", str);
    return 0;
}