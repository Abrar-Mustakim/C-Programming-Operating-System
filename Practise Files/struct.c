#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct student
{
    int st_id;
    char name[50];
    double cgpa;
};

int main(){
    struct student alice; 
    alice.st_id = 20301125;
    strcpy(alice.name, "Alice");
    alice.cgpa = 3.5;


    printf("name: %s \nStudent ID: %d \nCGPA: %0.2f \n", alice.name, alice.st_id, alice.cgpa);

    return 0;
}