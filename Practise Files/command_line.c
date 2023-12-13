
#include <stdio.h>

int main(int argc, char const *argv[])  //argc=arguments count(default=1), argv=arguments array pointer
{
    printf("The value of argc is %d\n", argc);
    for (int i=0; i<argc; i++){
        printf("This argument number at index %d has value of %s \n", i, argv[i]);
        
    }
    return 0;
}
