#include <stdio.h>
#include <string.h>
struct Student
{
    int id;
    int marks;
    char fav_char;
    char name[34];
};

// struct Student
// {
//     int id;
//     int marks;
//     char fav_char;
//     char name[34];
// } s1 s2;

//struct Student s1, s2;

int main() 
{
    struct Student s2;

    struct Student s1 = {1, 35, 'I', "Iron Man is Hero"};
    s2.id = 2;
    s2.marks = 35;
    s2.fav_char= 'B';  
    strcpy(s2.name, "Batman is the hero");
    printf("Iron Man got %d marks\n", s1.marks);
    printf("Batman quote is %s\n", s2.name);
    return 0;
}