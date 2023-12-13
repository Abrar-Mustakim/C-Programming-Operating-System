#include <stdio.h>

int sum(int a, int b);

void printstar(int n);
int main() 
{
    int a, b, c;
    a = 9;
    b = 10;
    c = sum(a, b);
    printstar(7);
    printf("The sum is %d\n", c);    
    return 0;
}

int sum(int a, int b) {
    return a+b;
}

void printstar(int n) {
    for(int i=0; i<n;i++){
        printf("%s", "*");
    }
}
