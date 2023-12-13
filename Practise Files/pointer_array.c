#include <stdio.h>

const int MAX=3;

int main () 

{
    int var[] = {10, 100, 200};
    int i, *ptr; 
    ptr = var; //as it is array, we do not need to use &
    // ptr stored the base address of the variable array, so if we just extract value, it will print the first value
    for (i = 0; i<MAX; i++)
    {
        printf("Address of var[%d]=%x\n", i, ptr);
        printf("Value of var[%d]=%d\n", i, *ptr);

        ptr++;
    }
    return 0;
}
