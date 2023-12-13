// . Again, you have lost your USIS password!! You went to the registrar's office and requested a
// new password. This time, you need to follow some rules to set your password. Otherwise, they
// won't change it. The rules are:
// • At least one lowercase letter
// • At least one uppercase letter
// • At least one digit (0-9)
// • At least one special character (_ , $, #, @)
// Your task is to find whether a given password follows all those rules. If it breaks any rule, you
// have to print “Lowercase character missing”, “Uppercase character missing”, “Digit missing” or
// “Special character missing” respective to the missing case. For more than one rule break, print
// all the rules that were broken (order doesn't matter). If the password is ok, print “OK” [3 Marks]
// Sample Input:
// • BR@CUspring
// • bracuspring
// • BR@CU20spring22
// Sample Output
// • Digit missing
// • Uppercase character missing, Digit missing, Special character
// missing
// • OK


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
int main(){
    char c[100];
    printf("Enter Your Password: ");
    scanf("%s", c);
    bool lowercase = false;
    bool uppercase = false;
    bool digit = false;
    bool character = false; 
    for(int i=0; i<strlen(c);i++){
    //printf("The Ascii Value of %c is %d\n", c[i], c[i]);
        int ascii = c[i];
        if(ascii >= 97 && ascii <=122){
            lowercase = true;
        }
        else if(ascii >=65 && ascii <=90){
            uppercase=true;
        }
        else if(ascii >= 48 && ascii <= 57){
            digit=true;

        }     
        else if(ascii == 22 || ascii == 36 || ascii == 35|| ascii == 64){
            //_. $, #, @
            character=true;

        }
    }
    if(lowercase==false){
        printf("Lowercase character missing\n");
    }
    if(uppercase==false){
        printf("Uppercase character missing\n");
    }
    if(digit == false){
        printf("Digit missing\n");
    }
    if(character==false){
        printf("Special character missing\n");

    } 
    if(lowercase && uppercase && digit && character){
        printf("OK");
    }
    return 0;


}