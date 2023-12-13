#include <stdio.h>

int main(){

    int n=5;
    int *ptr = &n;

    printf("&n= %x\n", &n);
    printf("ptr = %x\n", ptr);
    printf("*ptr=%d\n", *ptr);

}