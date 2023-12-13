//20301125
//task 4 sorting

// mustakim@DESKTOP-Q2KTU5Q:~/CSE321 Lab 3/20301125_CSE321_Lab Assignment 2/system_call$ gcc sort.c -o sort
// mustakim@DESKTOP-Q2KTU5Q:~/CSE321 Lab 3/20301125_CSE321_Lab Assignment 2/system_call$ ./sort 5 9 3 2 10 20 13
// Sorted Array in Descending Order:
// 20 13 10 9 5 3 2

#include <stdio.h>
#include <stdlib.h>

int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
int main(int argc, char *argv[]) {
    int size = argc - 1;
    int *numbers = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        numbers[i] = atoi(argv[i + 1]);
    }
    qsort(numbers, size, sizeof(int), compare_desc);
    printf("Sorted Array in Descending Order:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
