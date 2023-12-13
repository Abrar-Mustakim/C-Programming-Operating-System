#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
int main(){
printf("Program-2 Running...\n");
pid_t pid, status;
pid = fork();
if(pid == 0)
execl(".","p2", 'a', 'b', 'c', 'd', NULL);
else if(pid>0){
wait(&status);
execl("bin/pwd/","pwd", NULL);
}
}