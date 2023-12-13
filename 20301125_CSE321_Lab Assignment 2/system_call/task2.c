//20301125
//Task 2


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    pid_t pid_child, pid_grandchild;
    pid_child = fork();
    if (pid_child == 0) {
        pid_grandchild = fork();
        if (pid_grandchild == 0) {
            printf("I am grandchild\n");
        } else if (pid_grandchild > 0) {
            wait(NULL); 
            printf("I am child\n");
        }
    } else if (pid_child > 0) {
        wait(NULL); 
        printf("I am parent\n");
    } else {
        perror("Error in fork");
    }
    return 0;
}
