// Write a program that allows you to erase multiple spaces in a text file. Then rewrite the
// sentence without extra spaces in another text file. [3 Marks]
// Input:
// I love Python Programming.
// Output:
// I love Python Programming.
// =========================================================
// Hints:
// You can use the split function to separate the words into a list.

#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputs;
    FILE *outputs;
    char fileContent[1000];
    inputs = fopen("inputs.txt", "r");
    fgets(fileContent, sizeof(fileContent), inputs);
    fclose(inputs);
    if (fileContent[strlen(fileContent) - 1] == '\n') {
        fileContent[strlen(fileContent) - 1] = '\0';
    }
    outputs = fopen("outputs.txt", "w");
    // Splitting(" ") and removing extra spaces
    char *token = strtok(fileContent, " ");
    while (token != NULL) {
        if (strcmp(token, " ") != 0) {
            printf("%s ", token);
            fprintf(outputs, "%s ", token);
        }
        token = strtok(NULL, " ");
    }
    fclose(outputs);
    return 0;
}
