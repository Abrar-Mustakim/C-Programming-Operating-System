#include <stdio.h>


int main() {
    //printf("Hello World 1");
    
    int marks[4];
    //int marks[4] = {5, 10, 11, 20};
    //int marks[][4] = {{5, 10, 11, 20}, {5, 10, 11, 20}};
    // marks[0] = 34;
    // marks[1] = 454;
    // marks[2] = 300;
    // marks[3] = 900;

    for(int i=0; i<4;i++){
        printf("Marks of Student 1 is %d: ", i);
        scanf("%d", &marks[i]);
    }
    for(int i=0; i<4;i++){
        printf("Marks of Student 1 is %d\n", marks[i]);
    }
    return 0;
}