#include <stdio.h>


int main() {
    
    printf("Let's learn about pointers\n");
    int a=76;
    int* ptra = &a;
    int* ptr2 = NULL;
    printf("THe value of a is: %d\n", a);
    printf("THe address of a is: %d\n", &a);
    printf("THe address of a is: %d\n", ptra);
    printf("THe address of a is: %x\n", ptra);
    printf("THe address of NULL is: %p\n", ptr2);
    printf("THe value of a is: %d\n", *ptra);
    return 0;
   
}