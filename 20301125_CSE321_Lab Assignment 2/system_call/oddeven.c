//20301125
//task 4 oddeven



// mustakim@DESKTOP-Q2KTU5Q:~/CSE321 Lab 3/20301125_CSE321_Lab Assignment 2/system_call$ gcc oddeven.c -o oddeven
// mustakim@DESKTOP-Q2KTU5Q:~/CSE321 Lab 3/20301125_CSE321_Lab Assignment 2/system_call$ ./oddeven 5 13 20 24 26 30 33
// Odd/Even Status:
// 5 is odd
// 13 is odd
// 20 is even
// 24 is even
// 26 is even
// 30 is even
// 33 is odd
// mustakim@DESKTOP-Q2KTU5Q:~/CSE321 Lab 3/20301125_CSE321_Lab Assignment 2/system_call$



#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    printf("Odd/Even Status:\n");
    for (int i = 1; i < argc; ++i) {
        int num = atoi(argv[i]);
        if (num % 2 == 0) {
            printf("%d is even\n", num);
        } else {
            printf("%d is odd\n", num);
        }
    }
    return 0;
}
