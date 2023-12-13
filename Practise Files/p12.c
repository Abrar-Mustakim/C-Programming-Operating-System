#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    pid_t a,b,parID, chID, gcID;

    parID = getpid();
    printf("Parent id before fork: %d\n",parID);
    a = fork();
    if (a<0)
    {
        printf("Fork Error!");
    }
    else if (a==0)
    {
        chID = getpid();
        printf("Child id before fork: %d\n", chID);
        b = fork();
        if(b<0){
            printf("fork error\n");
        }
        else if(b>0){
            wait();
            printf("Child id before fork: %d\n",getpid());
            
        }
        else {
            gcID=getpid();
            printf("Grand Child ID: %d\n",gcID);
        }
    }
    else 
    {
        wait();
        printf("Parent id after fork: %d\n", getpid());
    }
    


    return 0;
}