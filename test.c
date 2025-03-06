#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 20;
    int *ptr = &x;

    printf("x = %d\n", x);
    printf("&x = %d\n", &x);
    printf("ptr = %d\n", ptr);
    printf("*ptr = %d\n", *ptr);

    free(ptr);
    return 0;
}