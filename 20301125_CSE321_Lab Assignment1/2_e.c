//20301125
//S.M.ABRAR MUSTAKIM TAKI

// Take a string input from the user and find out whether it is a palindrome using pointers.
// [3 Marks]
// Sample Input:
// AAABBAAA
// AABBABA
// aabcbaa
// Sample Output:
// Palindrome
// Not Palindrome
// Palindrome


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main() {
    char strings[50];
    printf("Enter a String: ");
    scanf("%s", strings);
    char *start = strings;
    char *reversedstr = strings + strlen(strings) - 1;
    bool isPalindrome = true;
    while (start < reversedstr) {
        if (*start != *reversedstr) {
            isPalindrome = false;
            break;
        }
        start+=1;
        reversedstr-=1;
    }
    if (isPalindrome) {
        printf("Palindrome");
    } else {
        printf("Not Palindrome");
    }
    return 0;
}
