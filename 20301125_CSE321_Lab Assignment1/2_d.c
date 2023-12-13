//  A company named Sheba.xyz has recently moved from their old domain to a new domain.
// However, a lot of the company email addresses are still using the old one
// (employeeName@kaaj.com). Write a function in C that takes the email id of an employee as
// input and checks whether that email id is updated (I.E. using the new domain
// employeeName@sheba.xyz) or not. [3 Marks]
// Sample Input:
// • fahmid@kaaj.com
// • zaki@sheba.xyz
// Sample Output:
// • Email address is outdated
// • Email address is okay


#include <stdio.h>
#include <string.h>
int main(){
    char mail[100];
    printf("Enter Mail Address: ");
    scanf("%s", mail);
    //printf("%s\n", mail);
    //now point at @ index
    int indexofat = -2;
    int maillength = strlen(mail);
    for(int i=0; i<maillength; i++){
        if(mail[i]=='@'){
            indexofat = i;
        }

    }
    //printf("%d\n", indexofat);
    //printf("%d\n", maillength);
    //printf("%d\n", indexofat);
    char domain[50];
    if(indexofat>0){
        int j=0;
        for(int i=indexofat+1; i<maillength; i++){
            domain[j] = mail[i];
            j++;
        }
    domain[j] = '\0';
    }
    //printf("%s\n", domain);
    char old_domain[] = "kaaj.com";
    char new_domain[] = "sheba.xyz";
    int old = strcmp(domain, old_domain);
    int new = strcmp(domain, new_domain);
    if(new==0){
        printf("Email address is okay");
    }
    else if(old==0){
        printf("Email address is outdated");
    }
    return 0;
}