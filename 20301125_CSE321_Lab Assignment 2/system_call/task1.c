//20301125
//System Call 
//Tasl 1

//    gcc task1.c -o task1 
//   ./task1 20301125.txt 
// Enter strings(Press '-1' to stop):
// Enter a string: Hello, This is My CSE 321 lab 1
// Enter a string: This is a String
// Enter a string: -1
// Strings saved to file '20301125.txt'.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000
int main(int argc, char *argv[]) {
    FILE *filePtr;
    char filename[MAX_LENGTH];
    char input[MAX_LENGTH];
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
    }
    strcpy(filename, argv[1]);
    filePtr = fopen(filename, "w");
    printf("Enter strings(Press '-1' to stop):\n");
    while (1) {
        printf("Enter a string: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "-1") == 0) {
            break;
        }
        fprintf(filePtr, "%s\n", input);
    }
    printf("Strings saved to file '%s'.\n", filename);
    fclose(filePtr);
}
