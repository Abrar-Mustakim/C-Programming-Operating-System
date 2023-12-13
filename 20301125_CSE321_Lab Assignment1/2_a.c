// Write a program where you have to take 2 numerical inputs and 1 input for operator {the
// operator input has to be either ‘+’, ’-’, ’*’). Depending on some comparisons, you need to carry
// out three operations: addition ( + ), subtraction ( - ), and multiplication ( * ). Each of these
// operations will be implemented in separate methods.
// [2 Marks]
// i. If the first number is greater than the second number, do subtraction and print the
// result.
// ii. If the first number is less than the second number, perform addition and print the result.
// iii. If the first number is equal to the second number, do multiplication and print the result


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 4 5 +
// 5 5 *
// 5 4 -

int main(){
    printf("Enter two numbers and operand after a space each: "); // 4 5 + 
    int first_num;
    int second_num;
    char operand[50]; 
    scanf("%d %d %s", &first_num, &second_num, &operand);
    if(first_num>second_num){
        int result = first_num-second_num;
        printf("%d %s %d = %d\n", first_num, operand, second_num, result);
    }
    else if(first_num<second_num) {
        int result = first_num+second_num;
        printf("%d %s %d = %d\n", first_num, operand, second_num, result);
    }
    else if(first_num==second_num) {
        int result = first_num * second_num;
        printf("%d %s %d = %d\n", first_num, operand, second_num, result);
    }
    return 0;
}