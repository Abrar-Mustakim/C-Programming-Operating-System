#include <stdio.h>
int main()
{
    char str[] = {'c', 's', 'e', '3', '2', '1'};

    int i;
    printf("%s\n", str);
    printf("%ld\n", strlen(str));
    printf("%d\n", sizeof(str)/sizeof(char));
    
}