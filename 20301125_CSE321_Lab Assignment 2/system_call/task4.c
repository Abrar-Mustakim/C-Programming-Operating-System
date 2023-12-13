
//20301125
//Task 4

// mustakim@DESKTOP-Q2KTU5Q:~/CSE321 Lab 3/20301125_CSE321_Lab Assignment 2/system_call$ gcc task4.c -o output
// mustakim@DESKTOP-Q2KTU5Q:~/CSE321 Lab 3/20301125_CSE321_Lab Assignment 2/system_call$ ./output 5 13 20 28 29 50 47
// Sorted Array in Descending Order:
// 50 47 29 28 20 13 5
// Odd/Even Status:
// 5 is odd
// 13 is odd
// 20 is even
// 28 is even
// 29 is odd
// 50 is even
// 47 is odd


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid = fork();
    if (pid < 0) {
        printf("Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        // array sorting
        char *args[argc];
        args[0] = "./sort";
        for (int i = 1; i < argc; ++i) {
            args[i] = argv[i];
        }
        args[argc] = NULL;
        execv(args[0], args);
    } else {
        // Odd even
        wait(NULL); 
        char *args[argc];
        args[0] = "./oddeven";
        for (int i = 1; i < argc; ++i) {
            args[i] = argv[i];
        }
        args[argc] = NULL;
        execv(args[0], args);
    }
    return 0;
}
