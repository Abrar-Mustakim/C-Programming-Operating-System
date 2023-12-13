#include <stdio.h>
#include <stdlib.h>
int main() 
{
    FILE *ptr= NULL;
    char string[34];

    //Reading a File
    ptr= fopen("myfile.txt", "r");
    fscanf(ptr, "%s", string);
    printf("The content of this file has %s\n", string);

    //Write a File
    FILE *ptr2 = fopen("write.txt", "w");
    char string1[50] = "Hi!! This is Mustakim";
    fprintf(ptr2, "%s", string1);

    return 0;
}