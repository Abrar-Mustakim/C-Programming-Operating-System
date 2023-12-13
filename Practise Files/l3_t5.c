#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


diameter(int r){
    //d=2r
    int d = 2*r;
    return d;
}

circumference(int r){
    //c=2*pi*r
    double c = 2 * 3.1416 * r;
    return c;
}

area_of_circle(int r){

    //pi*r^2
    double r_square = r*r;
    double a = 3.1416 * r_square;
    return a;
}

int main(){
    int r;
    printf("Enter radius: ");
    scanf("%d", &r);
    double diameters = diameter(r);
    printf("Diameter: %f\n", diameters);
    double circumferences = circumference(r);
    printf("Circumference: %f\n", circumferences);
    double area = area_of_circle(r);
    printf("Area of Circle: %f\n", area);



    return 0;
}